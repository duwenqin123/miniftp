#include "privparent.h"
#include "privsock.h"
#include "sysutil.h"
#include "tunable.h"
//#include <sys/capability.h>


static void privop_pasv_get_data_sock(session_t *sess);
static void privop_pasv_active(session_t *sess);
static void privop_pasv_listen(session_t *sess);
static void privop_pasv_accept(session_t *sess);

int capset(cap_user_header_t hdrp, const cap_user_data_t datap)
{
	return syscall(__NR_capset, hdrp, datap);
}

/*
 * �ú���������rootȨ�޲���ִ��
 * �޶�Ȩ��ΪnobodyȨ�ޣ���ʹ����ӵ�а󶨶˿�20������
 */
void minimize_privilege(void)
{
    /*
     *  ʹ��nobody�û�����'Ŀ��'�ǣ�ʹ�κ��˶����Ե�¼ϵͳ��
     *  ������ UID �� GID ���ṩ�κ���Ȩ������uid��gidֻ�ܷ������˽Կɶ�д���ļ�
     */
    struct passwd* pw;
    if ((pw = getpwnam("nobody")) == NULL) {
        return;
    }
    //Ϊ��Ҫ������egid�أ�
    if (setegid(pw->pw_gid) < 0) {
        ERR_EXIT("setegid error");
    }
    if (seteuid(pw->pw_uid) < 0) {
        ERR_EXIT("seteuid error");
    }
    /*struct passwd *pw = getpwnam("nobody");
    if (pw == NULL)
        return;

    if (seteuid(pw->pw_uid) < 0)
        ERR_EXIT("seteuid");
    if (setegid(pw->pw_gid) < 0)
        ERR_EXIT("setegid");*/

	struct __user_cap_header_struct cap_header;
	struct __user_cap_data_struct cap_data;

	memset(&cap_header, 0, sizeof(cap_header));
	memset(&cap_data, 0, sizeof(cap_data));

	cap_header.version = _LINUX_CAPABILITY_VERSION_1;
	cap_header.pid = 0;

	__u32 cap_mask = 0;
    /* Allows binding to TCP/UDP sockets below 1024 */
	cap_mask |= (1 << CAP_NET_BIND_SERVICE);

	cap_data.effective = cap_data.permitted = cap_mask;
	cap_data.inheritable = 0;

	capset(&cap_header, &cap_data);
}

void handle_parent(session_t *sess)
{
	minimize_privilege();

	char cmd;
	while (1)
	{
		//read(sess->parent_fd, &cmd, 1);
		cmd = priv_sock_get_cmd(sess->parent_fd);
		// �����ڲ�����
		// �����ڲ�����
		switch (cmd) {
		case PRIV_SOCK_GET_DATA_SOCK:
			privop_pasv_get_data_sock(sess);
			break;
		case PRIV_SOCK_PASV_ACTIVE:
			privop_pasv_active(sess);
			break;
		case PRIV_SOCK_PASV_LISTEN:
			privop_pasv_listen(sess);
			break;
		case PRIV_SOCK_PASV_ACCEPT:
			privop_pasv_accept(sess);
			break;
		}
	}
}

static void privop_pasv_get_data_sock(session_t *sess)
{
	/*
	nobody���̽���PRIV_SOCK_GET_DATA_SOCK����
	 ����ģʽ
	 ��ŵ��ò����ǣ����̽��յ�Ҫ��������ݵ�������ǵ�����ش�����������do_list��,
	 ���Ǵ����������ӣ�get_transfer_fd�����ú�����⵽��ǰ��������ģʽ��
	 ���ǵ���get_port_fd����nobody����
    PRIV_SOCK_GET_DATA_SOCK����,�ٷ��Ϳͻ��˵�port��ip
    ��һ������һ��������Ҳ����port
    ����һ���ַ�����Ҳ����ip

fd = socket 
bind(20)
connect(ip, port);
n
OK
send_fd
BAD
*/
    unsigned short port = (unsigned short) priv_sock_get_int(sess->parent_fd);
    char ip[16];
    priv_sock_recv_buf(sess->parent_fd, ip, sizeof(ip));

    struct sockaddr_in client_addr;
    bzero(&client_addr, sizeof(client_addr));
    client_addr.sin_family=AF_INET;
    client_addr.sin_port = htons(port);
    inet_pton(AF_INET,ip,&client_addr.sin_addr);

    int fd=tcp_client(20);
    if (fd < 0) {
        priv_sock_send_result(sess->parent_fd, PRIV_SOCK_RESULT_BAD);
        return;
    }
    if (connect_timeout(fd, &client_addr, tunable_connect_timeout) < 0) {
        close(fd);
        priv_sock_send_result(sess->parent_fd, PRIV_SOCK_RESULT_BAD);
        return;
    }
    priv_sock_send_result(sess->parent_fd, PRIV_SOCK_RESULT_OK);
    /*
     * ֮�������䣬�������ش�������������
     * fdsess->data_fd = priv_sock_recv_fd(sess->child_fd);
     */
	priv_sock_send_fd(sess->parent_fd, fd);
    /*
     * ��unix�׽��ִ���fdʱ��������fdָ���inode�������ü������ʿ��Թرյ�ǰ���
     */
	close(fd);
}

/*
 *�ͻ��˷���List������󣬷���������do_list������do_list����
 * gettransfer_fd,�ú����ֵ���pasv_active���ú�����child->fd����
 * PRIV_SOCK_PASV_ACTIVE�����ǵ��ñ��������ж�passiveģʽ�Ƿ��ѿ�����
 */
static void privop_pasv_active(session_t *sess)
{
	int active;
	if (sess->pasv_listen_fd != -1)
	{
		active = 1;
	}
	else
	{
		active = 0;
	}

	priv_sock_send_int(sess->parent_fd, active);
}

/*
 * �����������׼�������µ����ӣ�����tcp_server��bind���Ƕ˿ں�0��
 * ����getsockname����ں˰󶨵Ķ˿ںţ����ظ��������
 * ��do_pasv�з���
 */
static void privop_pasv_listen(session_t *sess)
{
    char ip[16] = {0};
    getlocalip(ip);

    sess->pasv_listen_fd=tcp_server(ip,0);
    struct sockaddr_in addr;
    socklen_t len = sizeof(addr);
    if (getsockname(sess->pasv_listen_fd, (struct sockaddr *) &addr, &len) < 0) {
        ERR_EXIT("getsockname");
    }

    unsigned short port = ntohs(addr.sin_port);
    priv_sock_send_int(sess->parent_fd,(int)port);
}

/*
 * ����˳��do_list->gettransfer_fd->get_pasv_fd,����PASV_ACCEPT,
 * �Ӷ����ñ�����
 */
static void privop_pasv_accept(session_t *sess) {
    /*int fd;
    if ((fd = accept_timeout(sess->pasv_listen_fd, NULL, tunable_accept_timeout)) < 0) {
        priv_sock_send_result(sess->parent_fd, PRIV_SOCK_RESULT_BAD);
        return;
    }
    close(sess->pasv_listen_fd);
    sess->pasv_listen_fd=-1;

    priv_sock_send_result(sess->parent_fd, PRIV_SOCK_RESULT_OK);
    priv_sock_send_int(sess->parent_fd, fd);
    close(fd);*/
    int fd = accept_timeout(sess->pasv_listen_fd, NULL, tunable_accept_timeout);
    close(sess->pasv_listen_fd);
    sess->pasv_listen_fd = -1;

    if (fd == -1)
    {
        priv_sock_send_result(sess->parent_fd, PRIV_SOCK_RESULT_BAD);
        return;
    }

    priv_sock_send_result(sess->parent_fd, PRIV_SOCK_RESULT_OK);
    priv_sock_send_fd(sess->parent_fd, fd);
    close(fd);
}

