#include "../include/evento_usuario.h"

EventoUsuario::EventoUsuario(uint8_t idEvento, int32_t param1, int32_t param2) : idEvento(idEvento),
                                                                                 param1(param1), param2(param2) {}

EventoUsuario::EventoUsuario(uint8_t idEvento) : idEvento(idEvento){}

uint8_t EventoUsuario::getIdEvento() const {
    return idEvento;
}

int32_t EventoUsuario::getParam1() const {
    return param1;
}

int32_t EventoUsuario::getParam2() const {
    return param2;
}
