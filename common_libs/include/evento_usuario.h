#ifndef EVENTO_USUARIO_H
#define EVENTO_USUARIO_H


#include <cstdint>

class EventoUsuario {
 private:
    uint8_t idEvento;
    int32_t param1;
    int32_t param2;
 public:
    EventoUsuario(uint8_t idEvento, int32_t param1, int32_t param2);

    EventoUsuario(uint8_t idEvento);

    uint8_t getIdEvento() const;

    int32_t getParam1() const;

    int32_t getParam2() const;

    //make copiable
    EventoUsuario(const EventoUsuario&) = default;
};


#endif // EVENTO_USUARIO_H
