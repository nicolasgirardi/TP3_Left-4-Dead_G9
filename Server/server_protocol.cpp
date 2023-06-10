#include <iostream>
#include "common_socket.h"
#include "server_message.h"
#include "server_protocol.h"
#include <arpa/inet.h>
#include <cstring>

uint8_t Protocol::receive_action(Socket* skt,bool* close){
    uint8_t code;
    skt->recvall(&code,1,close);
    return code;
}
uint32_t Protocol::receive_code(Socket* skt,bool* close){
    uint32_t code;
    skt->recvall(&code,4,close);
    return ntohl(code);
}
void Protocol::receive_name(Socket* skt,bool* close){
    uint16_t size;
    skt->recvall(&size,2,close);
    size = ntohs(size);
    char* name = new char[size]; 
    skt->recvall(name,size,close);
    delete[] name;
}
void Protocol::send(Socket* skt,bool* close,Message& msg){
    char* buffer;
    uint16_t size = msg.get_size();
    uint8_t code = msg.get_code();
    buffer = new char[size+3];
    buffer[0] = (char) code;
    size = htons(size);
    std::memcpy(buffer+1,&size,2);
    std::memcpy(buffer+3,msg.get_message(),msg.get_size());
    skt->sendall(buffer,msg.get_size()+3,close);
    delete[] buffer;
}
Message Protocol::receive(Socket* skt,bool* close){
    uint8_t code;
    uint16_t size;
    int leo = skt->recvall(&code,1,close);
    if (!leo){
        *close = true;
        skt->close();
        return Message();
    }
    skt->recvall(&size,2,close);
    size = ntohs(size);
    uint8_t* content = new uint8_t[size];
    skt->recvall(content,size,close);
    Message message(content,size,code);
    //delete[] content;
    return message;
}
void Protocol::send_code(Socket* skt,bool* close,uint32_t code){
    code = htonl(code);
    skt->sendall(&code,4,close);
}
void Protocol::send_result(Socket* skt,bool* close,uint8_t code){
    skt->sendall(&code,1,close);
}
