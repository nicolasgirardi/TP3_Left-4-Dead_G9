#include <iostream>
#include "client_message.h"

Message::Message(int id,int action,int pos_x,int pos_y,Type_of_character type,int ABM){
    this->id = id;
    this->action = action;
    this->pos_x = pos_x;
    this->pos_y = pos_y;
    this->type = type;
    this->ABM = ABM;
}
int Message::get_id(){
    return id;
}
int Message::get_action(){
    return action;
}
void Message::update(Character* character,uint32_t frame){
    character->change_action(action,frame);
    character->set_position(pos_x,pos_y);
}
int Message::get_amb(){
    return ABM;
}
Type_of_character Message::get_type(){
    return type;
}
int Message::get_x(){
    return pos_x;
}
int Message::get_y(){
    return pos_y;
}
Message::Message(const Message& other){
    this->ABM = other.ABM;
    this->action = other.action;
    this->id = other.id;
    this->pos_x = other.pos_x;
    this->pos_y = other.pos_y;
    this->type = other.type;
}
Message& Message::operator=(const Message& other){
    if (this == &other)
        return *this;
    this->ABM = other.ABM;
    this->action = other.action;
    this->id = other.id;
    this->pos_x = other.pos_x;
    this->pos_y = other.pos_y;
    this->type = other.type;
    return *this;
}