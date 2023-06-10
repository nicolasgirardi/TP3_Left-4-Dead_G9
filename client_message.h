#ifndef CLIENT_MESSAGE_H
#define CLIENT_MESSAGE_H

#include <iostream>
#include "client_character.h"

class Message{
    private:
    int id;
    int action;
    int pos_x;
    int pos_y;
    int tipo;

    public:
    Message(int id,int action,int pos_x,int pos_y,int tipo);

    int get_id();

    int get_action();

    void update(Character* character,uint32_t frame);

};
#endif