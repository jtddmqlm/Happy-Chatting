/*************************************************************************
	> File Name: udp_epoll.h
	> Author: GJY
	> Mail: gujiyuan0101@163.com
	> Created Time: Fri 10 Jul 2020 05:33:35 PM CST
 ************************************************************************/

#ifndef _UDP_EPOLL_H
#define _UDP_EPOLL_H

void add_event_ptr(int epollfd, int fd, int events, struct User *user);
void del_event(int epollfd, int fd);
int find_sub(struct User *team);
void add_to_sub_reactor(struct User *user);
int udp_connect(struct sockaddr_in *client);
int udp_accept(int fd, struct User *user);

#endif
