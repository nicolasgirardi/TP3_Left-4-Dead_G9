#ifndef CLIENT_KEY_BIND_ENUM_H_
#define CLIENT_KEY_BIND_ENUM_H_

#include <cstdint>

enum EVENTO : uint8_t {
    MOVE = 0x03,
    ATACAR = 0x01,
    IDLE = 0x02,
    DEAD = 0x03,
    EATING = 0x04,
    HURT = 0x05,
    JUMP = 0x06,
    RUN = 0x07,
    WALK = 0x08,
    EXPLOTION = 0x09,
    SHOOT = 0x0A,
    RECHARGE = 0x0B,
    FALL = 0x0C,
    PROTECT = 0x0D,
    RUN_ATTACK = 0x0E,
    SCREAM = 0x0F,
    BITE = 0x10,
    NONE_ACTION = 0x11
};

enum MOVER : uint8_t {
    START_RIGHT = 0x00,
    STOP_RIGHT = 0x01,
    START_LEFT = 0x02,
    STOP_LEFT = 0x03
};

#endif // CLIENT_KEY_BIND_ENUM_H_
