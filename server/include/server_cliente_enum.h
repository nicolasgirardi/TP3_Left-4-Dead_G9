#include <cstdint>

#ifndef SERVER_CLIENTE_ENUM_H
#define SERVER_CLIENTE_ENUM_H

enum ClienteMensaje {
    CREAR = 0x01,
    JOIN = 0x02,
    MOVE = 0x03,
    STOP_MOVE = 0x04,
    SHOOT = 0x05,
    STOP_SHOOT = 0x06,
    BOMB = 0x07,
    STRIKE = 0x08
};

#endif // SERVER_CLIENTE_ENUM_H