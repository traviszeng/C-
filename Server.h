/**
 * Server
 * 1.Init() initialize server
 * 2.Start() start server
 * 3.Close() close server
 * 4.SendBroadcastMessage() broadcast message to all client
*/

#ifndef CHATROOM_SERVER_H
#define CHATROOM_SERVER_H
 
#include <string>
 
#include "Common.h"
 
using namespace std;

class Server{

public:
    Server();
    //initialize server
    void Init();

    //close server
    void Close();

    //start server
    void Start();

private:

    //broadcast message
    int SendBroadcastMessage(int clientfd);
    //server address
    struct  sockaddr_in serverAddr;

    //create new socket
    int listener;

    //return val after epoll_create
    int epfd;

    //client list
    list<int> clients_lists;

};

#endif