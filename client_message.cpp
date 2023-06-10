#include <iostream>
#include "client_message.h"

Message::Message(int id,int action,int pos_x,int pos_y,int tipo){
    this->id = id;
    this->action = action;
    this->pos_x = pos_x;
    this->pos_y = pos_y;
    this->tipo = tipo;
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