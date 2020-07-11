/*************************************************************************
	> File Name: server.c
	> Author: GJY
	> Mail: gujiyuan0101@163.com
	> Created Time: Wed 08 Jul 2020 02:33:33 AM CST
 ************************************************************************/

#include "head.h"
#include "common.h"

void *work(void *arg)
{
    int fd;
    char buff[512];
    fd = *(int *)arg;
    recv(fd, buff, sizeof(buff), 0);
    printf("Recv Msg: %s \n", buff);
    close(fd);
    return NULL;
}

int main()
{
    int server_listen, sockfd;
    if ((server_listen = socket_create(8888)) < 0) {
        perror("socket_create()");
    }
    while (1) {
        pthread_t tid;
        if ((sockfd = accept(server_listen, NULL, NULL)) > 0) {
            pthread_create(&tid, NULL, work, (void *)&sockfd);
        }
    }

    return 0;
}
