#ifndef EVENTO_USUARIO_H
#define EVENTO_USUARIO_H


#include <cstdint>

class EventoUsuario {
 private:
    uint8_t idEvento;
    int32_t param1;
    int32_t param2;
 public:
    EventoUsuario(uint8_t idEvento, int32_t param1, int32_t param2) : idEvento(idEvento),
        param1(param1), param2(param2) {}

    EventoUsuario() {
    }

    uint8_t getIdEvento() const {
        return idEvento;
    }

    int32_t getParam1() const {
        return param1;
    }

    int32_t getParam2() const {
        return param2;
    }
};


#endif // EVENTO_USUARIO_H
