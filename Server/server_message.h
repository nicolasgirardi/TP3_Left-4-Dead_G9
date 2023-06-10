#ifndef SERVER_MESSAGE_H
#define SERVER_MESSAGE_H

#include <iostream>
class Message{
    private:
    uint8_t code;
    uint8_t* content;
    uint16_t size;

    public:
    Message(uint8_t* msg,uint16_t lenght,uint8_t action);
    Message();
    uint8_t* get_message();
    uint16_t get_size();
    uint8_t get_code();
    void change_code(uint8_t new_code);
    Message(const Message&);
    Message& operator=(const Message&);
    ~Message();
};
#endif
