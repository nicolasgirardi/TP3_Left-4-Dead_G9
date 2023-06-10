#ifndef SERVER_CLIENT_H
#define SERVER_CLIENT_H

#include "server_reciever.h"

class Client{
    private:
    Reciever* receiver;
    bool status;
    
    public:
    Client(Socket& socket,Allgames* games);
    void start();
    void finish();
    void join();
    Client(const Client&) = delete;
    Client& operator=(const Client&) = delete;
    ~Client();
};
#endif
