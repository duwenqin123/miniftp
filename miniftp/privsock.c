#include "privsock.h"
#include "common.h"
#include "sysutil.h"

void priv_sock_init(session_t *sess) {
    int sockfd[2];
    if (socketpair(AF_LOCAL, SOCK_STREAM, 0, sockfd) < 0) {
        ERR_EXIT("sock init error");
    }
    sess->parent_fd = sockfd[0];
    sess->child_fd = sockfd[1];
}

void priv_sock_close(session_t *sess)
{
	if (sess->parent_fd != -1) {
		close(sess->parent_fd);
		sess->parent_fd = -1;
	}

	if (sess->child_fd != -1)
	{
		close(sess->child_fd);
		sess->child_fd = -1;
	}
}

void priv_sock_set_parent_context(session_t *sess)
{
	if (sess->child_fd != -1)
	{
		close(sess->child_fd);
		sess->child_fd = -1;
	}
}

void priv_sock_set_child_context(session_t *sess) {
	if (sess->parent_fd != -1)
	{
		close(sess->parent_fd);
		sess->parent_fd = -1;
	}
}

void priv_sock_send_cmd(int fd, char cmd) {
    int ret;
    if ((ret = writen(fd, &cmd, sizeof(cmd))) != sizeof(cmd)) {
        ERR_EXIT("priv_sock_send_cmd error");
    }
}

char priv_sock_get_cmd(int fd)
{
    char cmd;
    int ret;
    if ((ret = readn(fd, &cmd, sizeof(cmd))) == 0) {
        printf("ftp process exit\n");
        exit(0);
    } else if (ret != sizeof(cmd)) {
        ERR_EXIT("get cmd error");
    }
    return cmd;
}

void priv_sock_send_result(int fd, char res)
{
	int ret;
    if ((ret = writen(fd, &res, sizeof(res))) != sizeof(res)) {
        ERR_EXIT("priv_sock_send_result error");
    }
}

char priv_sock_get_result(int fd)
{
	char res;
	int ret;
	ret = readn(fd, &res, sizeof(res));
	if (ret != sizeof(res)) {
	    ERR_EXIT("priv_sock_get_result error");
	}

	return res;
}

void priv_sock_send_int(int fd, int the_int)
{
    int ret;
    if ((ret = writen(fd, &the_int, sizeof(the_int))) != sizeof(the_int)) {
        ERR_EXIT("priv_sock_send_int error");
    }
}

int priv_sock_get_int(int fd)
{
	int the_int;
	int ret;
	ret = readn(fd, &the_int, sizeof(the_int));
	if (ret != sizeof(the_int))
	{
		fprintf(stderr, "priv_sock_get_int error\n");
		exit(EXIT_FAILURE);
	}

	return the_int;
}

void priv_sock_send_buf(int fd, const char *buf, unsigned int len)
{
    priv_sock_send_int(fd, (int) len);
    int ret;
    if((ret=writen(fd,buf,len))!=(int)len){
        ERR_EXIT("priv_sock_send_buf error");
    }
}

void priv_sock_recv_buf(int fd, char *buf, unsigned int len)
{
	unsigned int recv_len = (unsigned int)priv_sock_get_int(fd);
	if (recv_len > len)
	{
		fprintf(stderr, "priv_sock_recv_buf error\n");
		exit(EXIT_FAILURE);
	}

	int ret = readn(fd, buf, recv_len);
	if (ret != (int)recv_len)
	{
		fprintf(stderr, "priv_sock_recv_buf error\n");
		exit(EXIT_FAILURE);
	}
}

void priv_sock_send_fd(int sock_fd, int fd)
{
	send_fd(sock_fd, fd);
}

int priv_sock_recv_fd(int sock_fd)
{
	return recv_fd(sock_fd);
}


