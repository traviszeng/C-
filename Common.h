/**
 * public headers
 * 
*/

#ifndef CHATROOM_COMMON_H
#define CHATROOM_COMMON_H
#include <iostream>
#include <list>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/epoll.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 7777

//max handle size for epoll
#define EPOLL_SIZE 5000

//SIZE OF BUFFER
#define BUF_SIZE 0xFFFF
// 新用户登录后的欢迎信息
#define SERVER_WELCOME "Welcome you join to the chat room! Your chat ID is: Client #%d"
 
// 其他用户收到消息的前缀
#define SERVER_MESSAGE "ClientID %d say >> %s"
#define SERVER_PRIVATE_MESSAGE "Client %d say to you privately >> %s"
#define SERVER_PRIVATE_ERROR_MESSAGE "Client %d is not in the chat room yet~"
// 退出系统
#define EXIT "EXIT"
 
// 提醒你是聊天室中唯一的客户
#define CAUTION "There is only one int the char room!"

//add new fd to epollfd
static void addfd(int epollfd,int fd,bool enable_et){
    struct epoll_event ev;
    ev.data.fd = fd;
    ev.events = EPOLLIN;
    if(enable_et)
        ev.events = EPOLLIN |EPOLLET;
    epoll_ctl(epollfd,EPOLL_CTL_ADD,fd,&ev);
    

    fcntl(fd,F_SETFL,fcntl(fd,F_GETFD,0) | O_NONBLOCK);
    printf("fd added to epoll!!\n\n");
}


struct Message{
    int type;
    int fromID;
    int toID;
    char content[BUF_SIZE];

};


#endif //CHATROOM_COMMON_H