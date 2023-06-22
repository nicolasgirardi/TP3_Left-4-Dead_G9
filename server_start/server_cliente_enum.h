#include <cstdint>

#ifndef LEFT4DEAD_SERVER_CLIENTE_ENUM_H
#define LEFT4DEAD_SERVER_CLIENTE_ENUM_H

//0x01 create + 8bits con largo del nombre + string
//0x02 join + 32bits del codigo
//0x03 move + 2 coordenadas en 2 variables de 32bits con signo
//0x04 stop movecommon_libs/common_protocolo
//0x05 shoot
//0x06 stop shoot
//0x07 bomb + 1 coordenada en 1 variable de 32bits con signo para la direccion
//0x08 strike

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

#endif //LEFT4DEAD_SERVER_CLIENTE_ENUM_H