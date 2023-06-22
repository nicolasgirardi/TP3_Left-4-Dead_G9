#ifndef LEFT4DEAD_TIPOS_ESTADO_ENUM_H
#define LEFT4DEAD_TIPOS_ESTADO_ENUM_H

#include <cstdint>

enum EVENTO : uint8_t {
    ATACAR = 0x00,
    IDLE = 0x01,
    DEAD = 0x02,
    EATING = 0x03,
    HURT = 0x04,
    JUMP = 0x05,
    RUN = 0x06,
    WALK = 0x07,
    EXPLOTION = 0x08,
    SHOOT = 0x09,
    RECHARGE = 0x0A,
    FALL = 0x0B,
    PROTECT = 0x0C,
    RUN_ATTACK = 0x0D,
    SCREAM = 0x0E,
    BITE = 0x0F,
    NONE_ACTION = 0x10
};

enum PERSONAJE : uint8_t {
    JUMPER = 0x00,
    SOLDIER_IDF = 0x01,
    SOLDIER_P90 = 0x02,
    SOLDIER_SCOUT = 0x03,
    SPEAR = 0x04,
    VENOM = 0x05,
    WITCH = 0x06,
    ZOMBIE = 0x07,
    NONE_CHARACTER = 0x08
};

#endif //LEFT4DEAD_TIPOS_ESTADO_ENUM_H
