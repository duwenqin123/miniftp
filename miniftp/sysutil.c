#include "sysutil.h"
#include <net/if.h>
#include <sys/ioctl.h>

int tcp_client(unsigned short port)
{
	int sock;
	if ((sock = socket(PF_INET, SOCK_STREAM, 0)) < 0)
		ERR_EXIT("tcp_client");

	if (port > 0)
	{
		int on = 1;
		if ((setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, (const char*)&on, sizeof(on))) < 0)
			ERR_EXIT("setsockopt");

		char ip[16] = {0};
		getlocalip(ip);
		struct sockaddr_in localaddr;
		memset(&localaddr, 0, sizeof(localaddr));
		localaddr.sin_family = AF_INET;
		localaddr.sin_port = htons(port);
		localaddr.sin_addr.s_addr = inet_addr(ip);
		if (bind(sock, (struct sockaddr*)&localaddr, sizeof(localaddr)) < 0)
			ERR_EXIT("bind");
	}

	return sock;
}

/**
 * tcp_server - 启动tcp服务器
 * @host: 服务器IP地址或者服务器主机名
 * @port: 服务器端口
 * 成功返回监听套接字
 */
int tcp_server(const char *host, unsigned short port)
{
	int listenfd;
	if ((listenfd = socket(PF_INET, SOCK_STREAM, 0)) < 0)
		ERR_EXIT("tcp_server");

	struct sockaddr_in servaddr;
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	if (host != NULL)
	{
		if (inet_aton(host, &servaddr.sin_addr) == 0)
		{
			struct hostent *hp;
			hp = gethostbyname(host);
			if (hp == NULL)
				ERR_EXIT("gethostbyname");

			servaddr.sin_addr = *(struct in_addr*)hp->h_addr;
		}
	}
	else
		servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

	servaddr.sin_port = htons(port);

	int on = 1;
	if ((setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, (const char*)&on, sizeof(on))) < 0)
		ERR_EXIT("setsockopt");

	if (bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0)
		ERR_EXIT("bind");

	if (listen(listenfd, SOMAXCONN) < 0)
		ERR_EXIT("listen");

	return listenfd;
}

int getlocalip(char *ip)
{
	/*char host[100] = {0};
	if (gethostname(host, sizeof(host)) < 0)
		return -1;
	struct hostent *hp;
	if ((hp = gethostbyname(host)) == NULL)
	return -1;

	strcpy(ip, inet_ntoa(*(struct in_addr*)hp->h_addr));
	return 0;*/
	int sockfd; 
    if(-1 == (sockfd = socket(PF_INET, SOCK_STREAM, 0)))
    {
        perror( "socket" );
        return -1;
    }
    struct ifreq req;
    struct sockaddr_in *host;
    bzero(&req, sizeof(struct ifreq));
    strcpy(req.ifr_name, "ens33");
    ioctl(sockfd, SIOCGIFADDR, &req);
    host = (struct sockaddr_in*)&req.ifr_addr;
//    strcpy(ip, inet_ntoa(host->sin_addr));
    inet_ntop(AF_INET, &host->sin_addr, ip, 1024);

    close(sockfd);
    return 1;
}


/**
 * activate_noblock - 设置I/O为非阻塞模式
 */
void activate_nonblock(int fd)
{
    int ret,flag;
    if((flag=fcntl(fd,F_GETFL))<0)
        ERR_EXIT("fcntl");
    flag |= O_NONBLOCK;
    if ((ret = fcntl(fd, F_SETFL, flag)) < 0) {
        ERR_EXIT("fcntl");
    }

}

/**
 * deactivate_nonblock - 设置I/O为阻塞模式
 */
void deactivate_nonblock(int fd)
{
    int ret,flag;
    if ((flag = fcntl(fd, F_GETFL)) < 0) {
        ERR_EXIT("fcntl");
    }
    flag &= ~O_NONBLOCK;
    if ((ret = fcntl(fd, F_SETFL, flag)) < 0) {
        ERR_EXIT("fcntl");
    }
}

/**
 * read_timeout - 读超时检测函数，不含读操作
 * wait_seconds: 等待超时秒数，如果为0表示不检测超时
 * 成功（未超时）返回0，失败返回-1，超时返回-1并且errno = ETIMEDOUT
 */
int read_timeout(int fd, unsigned int wait_seconds)
{
    int nready;
    if (wait_seconds > 0) {
        fd_set rset;
        FD_ZERO(&rset);
        FD_SET(fd,&rset);

        struct timeval timeout;
        timeout.tv_sec=wait_seconds;
        timeout.tv_usec=0;

        while((nready=select(fd+1,&rset,NULL,NULL,&timeout))<0){
            if (errno == EINTR) {
                continue;
            }else {
                return -1;
            }
        }
        if (nready == 0) {
            errno=ETIMEDOUT;
            return -1;
        }
        else if(nready==1) {
            return 0;
        }
    }
    return 0;
}

/**
 * write_timeout - 写超时检测函数，不含写操作
 * @wait_seconds: 等待超时秒数，如果为0表示不检测超时
 * 成功（未超时）返回0，失败返回-1，超时返回-1并且errno = ETIMEDOUT
 */
int write_timeout(int fd, unsigned int wait_seconds)
{
    if (wait_seconds > 0) {
        int nready;
        fd_set wset;
        FD_ZERO(&wset);
        FD_SET(fd,&wset);

        struct timeval timeout;
        timeout.tv_sec=wait_seconds;
        timeout.tv_usec=0;

        while ((nready = select(fd + 1, NULL,&wset, NULL, &timeout)) < 0) {
            if(errno==EINTR)
                continue;
            else
                return -1;
        }
        if(nready==0) {
            errno=ETIMEDOUT;
            return -1;
        } else if (nready == 1) {
            return 0;
        }
    }
    return 0;
}

/**
 * accept_timeout - 带超时的accept
 * @addr: 输出参数，返回对方地址
 * @wait_seconds: 等待超时秒数，如果为0表示正常模式
 * 成功（未超时）返回已连接套接字，超时返回-1并且errno = ETIMEDOUT
 */
int accept_timeout(int fd, struct sockaddr_in *addr, unsigned int wait_seconds)
{
	int ret;
	socklen_t addrlen = sizeof(struct sockaddr_in);

	if (wait_seconds > 0)
	{
		fd_set accept_fdset;
		struct timeval timeout;
		FD_ZERO(&accept_fdset);
		FD_SET(fd, &accept_fdset);
		timeout.tv_sec = wait_seconds;
		timeout.tv_usec = 0;
		do
		{
			ret = select(fd + 1, &accept_fdset, NULL, NULL, &timeout);
		} while (ret < 0 && errno == EINTR);
		if (ret == -1)
			return -1;
		else if (ret == 0)
		{
			errno = ETIMEDOUT;
			return -1;
		}
	}

	if (addr != NULL)
		ret = accept(fd, (struct sockaddr*)addr, &addrlen);
	else
		ret = accept(fd, NULL, NULL);

	return ret;
}

/**
 * connect_timeout - connect
 * @addr: 要连接的对方地址
 * @wait_seconds: 等待超时秒数，如果为0表示正常模式
 * 成功（未超时）返回0，失败返回-1，超时返回-1并且errno = ETIMEDOUT
 * 见UNP353页
 */
int connect_timeout(int fd, struct sockaddr_in *addr, unsigned int wait_seconds)
{
    if (wait_seconds > 0) {
        activate_nonblock(fd);
    }
    int ret;
    if ((ret = connect(fd, (struct sockaddr *) addr, sizeof(struct sockaddr_in))) < 0) {
        if (errno != EINPROGRESS) {
            return -1;
        }
        fd_set connect_set;
        FD_ZERO(&connect_set);
        FD_SET(fd,&connect_set);
        struct timeval timeout;
        timeout.tv_sec=wait_seconds;
        timeout.tv_usec=0;
        while ((ret = select(fd + 1, NULL, &connect_set, NULL, &timeout)) < 0) {
            if (errno == EINTR) {
                continue;
            }else{
                return -1;
            }
        }
        if (ret == 0) {
            errno=ETIMEDOUT;
            return -1;
        }
        if(FD_ISSET(fd,&connect_set)){
            int error;
            socklen_t len=sizeof(error);
            if (getsockopt(fd, SOL_SOCKET, SO_ERROR, &error, &len) < 0) {
                return -1;
            }
            if (error) {
                errno=error;
                return -1;
            }
        }else{
            ERR_EXIT("select error: fd not set");
        }
    }
    if (wait_seconds > 0) {
        deactivate_nonblock(fd);
    }
    return 0;
}

/**
 * readn - 读取固定字节数
 * @buf: 接收缓冲区
 * @count: 要读取的字节数
 * 成功返回count，失败返回-1，读到EOF返回<count
 */
ssize_t readn(int fd, void *buf, size_t count)
{
    size_t nleft=count;
    ssize_t nread;
    char *ptr = (char *) buf;
    while (nleft > 0) {
        if ((nread = read(fd, buf, nleft)) < 0) {
            if(errno==EINTR)
                continue;
            return -1;
        } else if (nread == 0) {
            return count-nleft;
        }
        nleft-=nread;
        ptr+=nread;
    }
    return count;
}

/**
 * writen - 发送固定字节数
 * @buf: 发送缓冲区
 * @count: 要读取的字节数
 * 成功返回count，失败返回-1
 */
ssize_t writen(int fd, const void *buf, size_t count)
{
    size_t nleft=count;
    ssize_t nwrite;
    char* ptr=(char*)buf;
    while (nleft > 0) {
        if ((nwrite = write(fd, ptr, nleft)) <= 0) {
            if (nwrite == 0 && errno == EINTR) {
                continue;
            }
            return -1;
        }
        nleft-=nwrite;
        buf+=nwrite;
    }
    return count;
}

/**
 * recv_peek - 仅仅查看套接字缓冲区数据，但不移除数据
 * @buf: 接收缓冲区
 * @len: 长度
 * 成功返回>=0，失败返回-1
 */
ssize_t recv_peek(int sockfd, void *buf, size_t len)
{
    while (1) {
        int ret;
        if((ret=recv(sockfd,buf,len,MSG_PEEK))<0){
            if (errno == EINTR) {
                continue;
            }
        }
        return ret;
    }
}

/**
 * readline - 按行读取数据
 * @buf: 接收缓冲区
 * @maxline: 每行最大长度
 * 成功返回>=0，失败返回-1
 * 该行可以不以'\0'结尾
 */
ssize_t readline(int sockfd, void *buf, size_t maxline)
{
    size_t nleft=maxline;
    ssize_t nread;
    char* ptr=buf;
    int ret;
    while (1) {
        if ((ret = recv_peek(sockfd, ptr, nleft)) < 0) {
            return -1;
        } else if (ret == 0) {
            return ptr-(char*)buf;
        }
        nread=ret;
        int i;
        for (i = 0; i < nread; ++i) {
            if (ptr[i] == '\n' || ptr[i] == '\0') {
                if ((ret = readn(sockfd, ptr, i + 1)) != i + 1) {
                    exit(1);
                }
                /*易错点，不要写成ptr-(char*)buf */
                return ptr+i-1-(char*)buf;
            }
        }
        if ((ret = readn(sockfd, ptr, nread)) != nread) {
            exit(1);
        }
        nleft-=nread;
        ptr+=nread;
    }
    return -1;
}

/*
 * 向sock_fd发送fd
 */
void send_fd(int sock_fd, int send_fd) {
    struct msghdr msg;
    char cmsgbuf[CMSG_SPACE(sizeof(int))];

    msg.msg_control=cmsgbuf;
    msg.msg_controllen = sizeof(cmsgbuf);

    struct cmsghdr* cmsg_ptr=CMSG_FIRSTHDR(&msg);
    cmsg_ptr->cmsg_level=SOL_SOCKET;
    cmsg_ptr->cmsg_type = SCM_RIGHTS;
    cmsg_ptr->cmsg_len=CMSG_LEN(sizeof(int));
    *((int*)CMSG_DATA(cmsg_ptr))=send_fd;

    msg.msg_name=NULL;
    msg.msg_namelen=0;

    struct iovec iov[1];
    char send_data = '\0';
    iov[0].iov_base=&send_data;
    iov[0].iov_len=sizeof(send_data);
    msg.msg_iov=iov;
    msg.msg_iovlen=1;

    int ret;
    if ((ret = sendmsg(sock_fd, &msg, 0)) != 1) {
        exit(1);
    }
}

int recv_fd(const int sock_fd)
{
	int ret;
	struct msghdr msg;
	char recvchar;
	struct iovec vec;
	int recv_fd;
	char cmsgbuf[CMSG_SPACE(sizeof(recv_fd))];
	struct cmsghdr *p_cmsg;
	int *p_fd;
	vec.iov_base = &recvchar;
	vec.iov_len = sizeof(recvchar);
	msg.msg_name = NULL;
	msg.msg_namelen = 0;
	msg.msg_iov = &vec;
	msg.msg_iovlen = 1;
	msg.msg_control = cmsgbuf;
	msg.msg_controllen = sizeof(cmsgbuf);
	msg.msg_flags = 0;

	p_fd = (int*)CMSG_DATA(CMSG_FIRSTHDR(&msg));
	*p_fd = -1;  
	ret = recvmsg(sock_fd, &msg, 0);
	if (ret != 1)
		ERR_EXIT("recvmsg");

	p_cmsg = CMSG_FIRSTHDR(&msg);
	if (p_cmsg == NULL)
		ERR_EXIT("no passed fd");


	p_fd = (int*)CMSG_DATA(p_cmsg);
	recv_fd = *p_fd;
	if (recv_fd == -1)
		ERR_EXIT("no passed fd");

	return recv_fd;
}

const char* statbuf_get_perms(struct stat *sbuf)
{
	static char perms[] = "----------";
	perms[0] = '?';

	mode_t mode = sbuf->st_mode;
    if (S_ISREG(mode)) {
        perms[0] = '-';
    } else if (S_ISDIR(mode)) {
        perms[0] = 'd';
    } else if (S_ISCHR(mode)) {
        perms[0] = 'c';
    } else if (S_ISBLK(mode)) {
        perms[0] = 'b';
    } else if (S_ISFIFO(mode)) {
        perms[0] = 'p';
    } else if (S_ISSOCK(mode)) {
        perms[0] = 's';
    } else if (S_ISLNK(mode)) {
        perms[0] = 'l';
    }

	if (mode & S_IRUSR) {
		perms[1] = 'r';
	}
	if (mode & S_IWUSR) {
		perms[2] = 'w';
	}
	if (mode & S_IXUSR) {
		perms[3] = 'x';
	}
	if (mode & S_IRGRP)
	{
		perms[4] = 'r';
	}
	if (mode & S_IWGRP) {
		perms[5] = 'w';
	}
	if (mode & S_IXGRP) {
		perms[6] = 'x';
	}
	if (mode & S_IROTH) {
		perms[7] = 'r';
	}
	if (mode & S_IWOTH) {
		perms[8] = 'w';
	}
	if (mode & S_IXOTH) {
		perms[9] = 'x';
	}
    if (mode & S_ISUID) {
        perms[3] = (perms[3] == 'x') ? 's' : 'S';
    }
    if (mode & S_ISGID) {
        perms[6] = (perms[6] == 'x') ? 's' : 'S';
    }
    if (mode & S_ISVTX) {
        perms[9] = (perms[9] == 'x') ? 't' : 'T';
    }

	return perms;
}

const char* statbuf_get_date(struct stat *sbuf)
{
    time_t mtime=sbuf->st_mtime;
    //time_t t;
//    time(&mtime);
    struct tm* tmp=localtime(&mtime);
    //注意要用static
    static char buf[64] = {0};
    strftime(buf, sizeof(buf), "%b %e %H:%M", tmp);
    return buf;
}

static int lock_internal(int fd, int lock_type)
{
    int ret;
    struct flock lock;
    bzero(&lock, sizeof(lock));
    lock.l_type=lock_type;
    lock.l_whence=SEEK_SET;
    lock.l_start=0;
    lock.l_len = 0;
    do {
        ret = fcntl(fd, F_SETLKW, &lock);
    } while (ret < 0 && errno == EINTR);
    return ret;
}

int lock_file_read(int fd)
{
	return lock_internal(fd, F_RDLCK);
}


int lock_file_write(int fd)
{
	return lock_internal(fd, F_WRLCK);
}


int unlock_file(int fd)
{
    struct flock lock;
    memset(&lock, 0, sizeof(lock));
    lock.l_type=F_UNLCK;
    lock.l_whence=SEEK_SET;
    lock.l_start=0;
    lock.l_len=0;

    return fcntl(fd, F_SETLK, &lock);
}

static struct timeval s_curr_time;
long get_time_sec(void)
{
	if (gettimeofday(&s_curr_time, NULL) < 0)
	{
		ERR_EXIT("gettimeofday");
	}

	return s_curr_time.tv_sec;
}

long get_time_usec(void)
{
	return s_curr_time.tv_usec;
}

void nano_sleep(double seconds)
{
    time_t secs=(time_t)seconds;//整数部分
    double fractional = seconds - (double) secs;//小数部分

    struct timespec ts;
    ts.tv_sec=secs;
    ts.tv_nsec = (long) (fractional * 1000000000);

    int ret;
    do {
        ret = nanosleep(&ts, &ts);
    } while (ret < 0 && errno == EINTR);
}

// 开启套接字fd接收带外数据的功能
void activate_oobinline(int fd)
{
    int on=1;
    int ret;
    if ((ret = setsockopt(fd, SOL_SOCKET, SO_OOBINLINE, &on, sizeof(on))) < 0) {
        ERR_EXIT("setsockopt");
    }
}

// 当文件描述fd上有带外数据的时候，将产生SIGURG信号，
// 该函数设定当前进程能够接收fd文件描述符所产生的SIGURG信号
void activate_sigurg(int fd)
{
    int ret;
    if ((ret = fcntl(fd, F_SETOWN, getpid())) < 0) {
        ERR_EXIT("activate_sigure error");
    }
}
