#ifndef LEFT4DEAD_PROTOCOLOACTIONS_H
#define LEFT4DEAD_PROTOCOLOACTIONS_H

#include <cstdint>

namespace ProtocoloActions {
    constexpr unsigned char CREATE = 0x01;
    constexpr unsigned char JOIN = 0x02;
    constexpr unsigned char MOVE = 0x03;
    constexpr unsigned char STOP_MOVE = 0x04;
    constexpr unsigned char SHOOT = 0x05;
    constexpr unsigned char STOP_SHOOT = 0x06;
    constexpr unsigned char BOMB = 0x07;
    constexpr unsigned char STRIKE = 0x08;
}

enum ACTION: uint8_t {
    IDLE,
    MOVE,
    STOP_MOVE,
    SHOOT,
    STOP_SHOOT,
    BOOM,
    STRIKE
};

#endif // LEFT4DEAD_PROTOCOLOACTIONS_H
