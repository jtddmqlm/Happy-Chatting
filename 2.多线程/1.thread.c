/*************************************************************************
	> File Name: 1.thread.c
	> Author: GJY
	> Mail: gujiyuan0101@163.com
	> Created Time: Wed 08 Jul 2020 12:01:16 AM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

struct Msg {
    char name[20];
    int age;
};

void *print(void *arg)
{
    struct Msg *tmp;
    tmp = (struct Msg *)arg;
    printf("In thread!\n");
    printf("%s is %d years old.\n", tmp->name, tmp->age);
    return NULL;
}

int main()
{
    pthread_t tid;
    struct Msg msg;
    bzero(&msg, sizeof(msg));
    strcpy(msg.name, "GJY");
    msg.age = 20;

    pthread_create(&tid, NULL, print, (void *)&msg);

    pthread_join(tid, NULL);
    return 0;
}
