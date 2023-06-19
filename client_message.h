#ifndef CLIENT_MESSAGE_H
#define CLIENT_MESSAGE_H

#include <iostream>
#include "client_character.h"
#include "client_myenum.h"


class Message{
    private:
    int id;
    myenum::Type_of_action action;
    int pos_x;
    int pos_y;
    Type_of_character type;
    Type_of_AMB ABM;
    uint32_t ammo;
    uint32_t hp;

    public:
    Message(int id,myenum::Type_of_action action,int pos_x,int pos_y,Type_of_character type,Type_of_AMB ABM,uint32_t ammo,uint32_t hp);

    int get_id();

    myenum::Type_of_action get_action();

    void update(Character* character,uint32_t& frame);

    Type_of_AMB get_amb();

    Type_of_character get_type();

    int get_x();

    int get_y();

    uint32_t get_ammo();

    uint32_t get_hp();

    Message(const Message&);
    Message& operator=(const Message&);

};
#endif