#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <arpa/inet.h>
#include <cstring>
#include <array>

#include "client_protocol.h"
#include "common_socket.h"

Protocol::Protocol(){
    buff = nullptr;
    size = 0;
}
void Protocol::create_game(std::string& name){
    uint16_t aux16;
    buff = new char[name.size()+3];
    buff[0] = 1;
    aux16 = htons((uint16_t) name.size());
    std::memcpy(buff+1,&aux16,sizeof(aux16));
    std::memcpy(buff+3,name.c_str(),name.size());
    size = name.size()+3;    
}
void Protocol::join_game(uint32_t code){
    size = 5;
    buff = new char[size];
    buff[0] = 2;
    code = htonl(code);
    std::memcpy(buff+1,&code,sizeof(code));
}
void Protocol::broadcast(std::string& text){
    uint16_t aux16;
    buff = new char[text.size()+3];
    buff[0] = 3;
    aux16 = htons((uint16_t) text.size());
    std::memcpy(buff+1,&aux16,sizeof(aux16));
    std::memcpy(buff+3,text.c_str(),text.size());
    size = text.size()+3;
}
void Protocol::send(Socket* skt,bool* close){
    if (size > 0)
        skt->sendall(buff,size,close);
}
void Protocol::receive_read(Socket& skt,bool* close,std::string& broadcasted){
    uint8_t aux_8; 
    uint16_t aux_16;
    skt.recvall(&aux_8,1,close);
    if (aux_8 == 4){
        skt.recvall(&aux_16,2,close);
        aux_16 = ntohs(aux_16);
        buff = new char[aux_16+1];
        skt.recvall(buff,aux_16,close);
        buff[aux_16] = '\0';
        broadcasted.clear();
        broadcasted.assign((char*)buff);
    }
} 
uint32_t Protocol::receive_create(Socket& skt,bool* close,int& id){
    int32_t aux;
    skt.recvall(&aux,4,close);
    aux = ntohl(aux);
    skt.recvall(&id,4,close);
    id = ntohl(id);
    return aux;
}
uint8_t Protocol::receive_join(Socket& skt,bool* close,int& id){
    int8_t aux;
    skt.recvall(&aux,1,close);
    if(aux == 0){
        skt.recvall(&id,4,close);
        id = ntohl(id);
    }
    return aux;
}

Protocol::~Protocol(){
    if (buff != nullptr)
        delete[] buff;
}
