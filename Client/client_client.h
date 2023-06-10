#ifndef CLIENT_CLIENT_H
#define CLIENT_CLIENT_H

#include "common_socket.h"
#include <fstream>
#include <string>

class Client{
    private:
    Socket socket;
    int my_id;

    public:
    Client(char* server,char* port);

    void process_commands();

    private:
    void send(std::string& command,bool* close);

    void receive_broadcast(bool* close);

    void receive_create(bool* close);

    void receive_join(bool* close);
};
#endif
