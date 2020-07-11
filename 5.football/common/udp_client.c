/*************************************************************************
	> File Name: udp_client.c
	> Author: GJY
	> Mail: gujiyuan0101@163.com
	> Created Time: Fri 10 Jul 2020 04:34:55 AM CST
 ************************************************************************/

#include "head.h"

int socket_udp()
{
    int fd;

    if ((fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        return -1;
    }

    return fd;
}

