#include <iostream>
#include "server_message.h"
#include <cstring>

Message::Message(uint8_t* msg,uint16_t lenght,uint8_t action){
    content = msg;
    //std::memcpy(content,msg,lenght);
    size = lenght;
    code = action;
}
Message::Message(){
    content = nullptr;
    size = 0;
    code = 0;
}
uint8_t* Message::get_message(){
    return content;
}
uint16_t Message::get_size(){
    return size;
}
uint8_t Message::get_code(){
    return code;
}
Message::Message(const Message& other){
    this->content = new uint8_t[other.size];
    std::memcpy(this->content,other.content,other.size);
    this->size = other.size;
    this->code = other.code;
}
Message& Message::operator=(const Message& other){
    if (this == &other)
        return *this;
    if (this->size != 0)
        delete[] this->content;
    this->content = new uint8_t[other.size];
    std::memcpy(this->content,other.content,other.size);
    this->size = other.size;
    this->code = other.code;
    return *this;
}
void Message::change_code(uint8_t new_code){
    code = new_code;
}
Message::~Message(){
    if (content != nullptr)
        delete[] content;
}
