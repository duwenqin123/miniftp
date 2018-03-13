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
 * 该函数必须以root权限才能执行
 * 限定权限为nobody权限，并使进程拥有绑定端口20的能力
 */
void minimize_privilege(void)
{
    /*
     *  使用nobody用户名的'目的'是，使任何人都可以登录系统，
     *  但是其 UID 和 GID 不提供任何特权，即该uid和gid只能访问人人皆可读写的文件
     */
    struct passwd* pw;
    if ((pw = getpwnam("nobody")) == NULL) {
        return;
    }
    //为何要先设置egid呢？
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
		// 解析内部命令
		// 处理内部命令
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
	nobody进程接收PRIV_SOCK_GET_DATA_SOCK命令
	 主动模式
	 大概调用步骤是，进程接收到要求输出数据的命令，于是调用相关处理函数，（如do_list）,
	 于是创建数据连接（get_transfer_fd），该函数检测到当前处于主动模式，
	 于是调用get_port_fd，向nobody发送
    PRIV_SOCK_GET_DATA_SOCK命令,再发送客户端的port和ip
    进一步接收一个整数，也就是port
    接收一个字符串，也就是ip

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
     * 之后会有这句，用来传回创建的数据连接
     * fdsess->data_fd = priv_sock_recv_fd(sess->child_fd);
     */
	priv_sock_send_fd(sess->parent_fd, fd);
    /*
     * 用unix套接字传回fd时，会增加fd指向的inode结点的引用计数，故可以关闭当前这个
     */
	close(fd);
}

/*
 *客户端发送List等命令后，服务器调用do_list函数，do_list调用
 * gettransfer_fd,该函数又调用pasv_active，该函数向child->fd发送
 * PRIV_SOCK_PASV_ACTIVE，于是调用本函数，判断passive模式是否已开启。
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
 * 创建服务进程准备接收新的连接，由于tcp_server中bind的是端口号0，
 * 故用getsockname获得内核绑定的端口号，返回给服务进程
 * 在do_pasv中返回
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
 * 调用顺序：do_list->gettransfer_fd->get_pasv_fd,发送PASV_ACCEPT,
 * 从而调用本函数
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

