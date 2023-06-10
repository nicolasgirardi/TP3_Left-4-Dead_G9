#ifndef SERVER_SERVER_H
#define SERVER_SERVER_H
#include <iostream>
#include "common_socket.h"
#include "server_thread.h"

class Server {
    private:
    Socket socket;
        
    public:
    explicit Server(char* service);
    void run();
};
#endif
