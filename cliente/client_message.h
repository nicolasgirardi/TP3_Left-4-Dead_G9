#ifndef LEFT4DEAD_CLIENT_MESSAGE_H
#define LEFT4DEAD_CLIENT_MESSAGE_H


#include <string>
#include "client_myenum.h"

class Message {
 private:
    int id;
    myenum::Type_of_action action;
    int pos_x;
    int pos_y;
    Type_of_character type;
    Type_of_AMB ABM;

 public:
    Message();
    Message(int id,myenum::Type_of_action action,int pos_x,int pos_y,Type_of_character type,Type_of_AMB ABM);

    int get_id();

    myenum::Type_of_action get_action();

    //void update(Character* character,uint32_t& frame);

    Type_of_AMB get_amb();

    Type_of_character get_type();

    int get_x();

    int get_y();

    Message(const Message&);
    Message& operator=(const Message&);

    void ParseFromString(std::string &estadoJuego);
};


#endif // LEFT4DEAD_CLIENT_MESSAGE_H