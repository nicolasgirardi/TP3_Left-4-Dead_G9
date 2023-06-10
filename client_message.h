#ifndef CLIENT_MESSAGE_H
#define CLIENT_MESSAGE_H

#include <iostream>
#include "client_character.h"

enum Type_of_character {jumper, soldier1,soldier2,soldier3,spear,venom,witch,zombie};

class Message{
    private:
    int id;
    int action;
    int pos_x;
    int pos_y;
    Type_of_character type;
    int ABM;

    public:
    Message(int id,int action,int pos_x,int pos_y,Type_of_character type,int ABM);

    int get_id();

    int get_action();

    void update(Character* character,uint32_t frame);

    int get_amb();

    Type_of_character get_type();

    int get_x();

    int get_y();

    Message(const Message&);
    Message& operator=(const Message&);

};
#endif