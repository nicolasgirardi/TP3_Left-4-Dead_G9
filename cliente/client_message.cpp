#include "client_message.h"

Message::Message(int id,myenum::Type_of_action action,int pos_x,int pos_y,Type_of_character type,Type_of_AMB ABM){
    this->id = id;
    this->action = action;
    this->pos_x = pos_x;
    this->pos_y = pos_y;
    this->type = type;
    this->ABM = ABM;
}

Message::Message() {

}

int Message::get_id(){
    return id;
}
myenum::Type_of_action Message::get_action(){
    return action;
}
/*void Message::update(Character* character,uint32_t& frame){
    character->change_action(action,frame);
    character->set_position(pos_x,pos_y);
}*/
Type_of_AMB Message::get_amb(){
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

void Message::ParseFromString(std::string &estadoJuego) {
    std::string delimiter = ",";
    std::string token = estadoJuego.substr(0, estadoJuego.find(delimiter));
    this->id = std::stoi(token);
    estadoJuego.erase(0, estadoJuego.find(delimiter) + delimiter.length());

    token = estadoJuego.substr(0, estadoJuego.find(delimiter));
    this->action = (myenum::Type_of_action) std::stoi(token);
    estadoJuego.erase(0, estadoJuego.find(delimiter) + delimiter.length());

    token = estadoJuego.substr(0, estadoJuego.find(delimiter));
    this->pos_x = std::stoi(token);
    estadoJuego.erase(0, estadoJuego.find(delimiter) + delimiter.length());

    token = estadoJuego.substr(0, estadoJuego.find(delimiter));
    this->pos_y = std::stoi(token);
    estadoJuego.erase(0, estadoJuego.find(delimiter) + delimiter.length());

    token = estadoJuego.substr(0, estadoJuego.find(delimiter));
    this->type = (Type_of_character) std::stoi(token);
    estadoJuego.erase(0, estadoJuego.find(delimiter) + delimiter.length());

    token = estadoJuego.substr(0, estadoJuego.find(delimiter));
    this->ABM = (Type_of_AMB) std::stoi(token);
    estadoJuego.erase(0, estadoJuego.find(delimiter) + delimiter.length());
}