/*************************************************************************
	> File Name: client.c
	> Author: GJY
	> Mail: gujiyuan0101@163.com
	> Created Time: Wed 08 Jul 2020 02:54:44 AM CST
 ************************************************************************/

#include "head.h"

int main(int argc, char *argv[])
{
    char ip[20] = {0};
    int port = 0, sockfd, n;
    struct sockaddr_in server;

    char student_name[] = "顾纪元";
    char student_id[] = "2019302180180";

    if (argc != 3) {
        fprintf(stderr, "Usage: %s ip port!\n", argv[0]);
        exit(1);
    }

    strcpy(ip, argv[1]);
    port = atoi(argv[2]);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket()");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr(ip);

    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect");
        exit(1);
    }

    while (1) {
        recv(sockfd, &n, sizeof(int), 0);
        switch (n) {
            case 1:
                send(sockfd, student_id, strlen(student_id) + 1, 0);
                break;
            case 2:
                send(sockfd, student_name, strlen(student_name) + 1, 0);
                break;
            case 3:
                close(sockfd);
                exit(0);
            default:
                break;
        }
    }

    return 0;
}
