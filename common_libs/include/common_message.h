#ifndef CLIENT_MESSAGE_H
#define CLIENT_MESSAGE_H


#include <string>
#include "common_myenum.h"
#include "common_character.h"

#define FIN "FIN"

class Message {
 private:
    int id;
    Type_of_action action;
    int pos_x;
    int pos_y;
    Type_of_character type;
    Type_of_AMB ABM;
    uint32_t ammo;
    uint32_t hp;

 public:
    Message();
    Message(int id, Type_of_character type, Type_of_AMB ABM);
    Message(int id, Type_of_action action,int pos_x,int pos_y,Type_of_character type,Type_of_AMB ABM,
            uint32_t ammo, uint32_t hp);

    int get_id();
    Type_of_action get_action();
    void update(Character* character,uint32_t& frame);
    Type_of_AMB get_amb();
    Type_of_character get_type();
    int get_x();
    int get_y();
    uint32_t get_ammo();
    uint32_t get_hp();
    void ParseFromString(std::string &estadoJuego);
    bool es_fin_de_juego();

    Message(const Message&);
    Message& operator=(const Message&);


};


#endif // CLIENT_MESSAGE_H
