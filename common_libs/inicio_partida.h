#ifndef INICIO_PARTIDA_H
#define INICIO_PARTIDA_H

#include <cstdint>
#include <string>

class InicioPartida {
 public:
    static const uint8_t crear = 0x01;
    static const uint8_t join = 0x02;
    static const std::string crearStr;
    static const std::string joinStr;
    static const std::string error;
};

const std::string InicioPartida::crearStr = "crear";
const std::string InicioPartida::joinStr = "join";
const std::string InicioPartida::error = "error";

#endif // INICIO_PARTIDA_H
