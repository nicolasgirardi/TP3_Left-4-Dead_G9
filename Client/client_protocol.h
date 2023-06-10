#ifndef CLIENT_PROTOCOL_H
#define CLIENT_PROTOCOL_H

#include "common_socket.h"
#include <string>
class Protocol{
    private:
    char* buff;
    size_t size;

    public:
    Protocol();

    void create_game(std::string& name);
    void join_game(uint32_t code);
    void broadcast(std::string& text);
    void send(Socket* skt,bool* close);

    uint32_t receive_create(Socket& skt,bool* close);

    uint8_t receive_join(Socket& skt,bool* close);

    void receive_read(Socket& skt,bool* close,std::string& broadcasted);

    ~Protocol();
};
#endif
