#ifndef SERVER_PROTOCOL_H
#define SERVER_PROTOCOL_H

#include <iostream>
#include "common_socket.h"
#include "server_message.h"


class Protocol{
    public:
    uint8_t receive_action(Socket* skt,bool* close);

    uint32_t receive_code(Socket* skt,bool* close);

    Message receive(Socket* skt,bool* close);

    void send(Socket* skt,bool* close,Message& msg);

    void receive_name(Socket* skt,bool* close);

    void send_code(Socket* skt,bool* close,uint32_t code);

    void send_result(Socket* skt,bool* close,uint8_t code);
};
#endif
