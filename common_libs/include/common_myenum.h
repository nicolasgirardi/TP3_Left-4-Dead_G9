#ifndef CLIENT_MYENUM_H
#define CLIENT_MYENUM_H

enum Type_of_character : std::uint8_t {
    jumper = 0x01,
    soldier1 = 0x02,
    soldier2 = 0x03,
    soldier3 = 0x04,
    spear = 0x05,
    venom = 0x06,
    witch = 0x07,
    zombie = 0x08,
    explot = 0x09,
    smok = 0x0A
};

inline Type_of_character get_character(uint8_t id) {
    switch (id) {
        case 0x01:
            return jumper;
        case 0x02:
            return soldier1;
        case 0x03:
            return soldier2;
        case 0x04:
            return soldier3;
        case 0x05:
            return spear;
        case 0x06:
            return venom;
        case 0x07:
            return witch;
        case 0x08:
            return zombie;
        case 0x09:
            return zombie;
        case 0x0A:
            return zombie;
        default:
            return zombie;
    }
}





enum Type_of_AMB : std::uint8_t {
    alta = 0x00,
    baja = 0x01,
    modificacion = 0x02
};

inline Type_of_AMB get_AMB(uint8_t id) {
    switch (id) {
        case 0x00:
            return alta;
        case 0x01:
            return baja;
        case 0x02:
            return modificacion;
        default:
            return modificacion;
    }
};

enum Type_of_map : std::uint8_t {
    war1_bright = 0x00,
    war1_pale = 0x01,
    war2_bright = 0x02,
    war2_pale = 0x03,
    war3_bright = 0x04,
    war3_pale = 0x05,
    war4_bright = 0x06,
    war4_pale = 0x07
};

inline Type_of_map get_map(uint8_t id) {
    switch (id) {
        case 0x00:
            return war1_bright;
        case 0x01:
            return war1_pale;
        case 0x02:
            return war2_bright;
        case 0x03:
            return war2_pale;
        case 0x04:
            return war3_bright;
        case 0x05:
            return war3_pale;
        case 0x06:
            return war4_bright;
        case 0x07:
            return war4_pale;
        default:
            return war1_bright;
    }
}

enum Type_of_action : std::uint8_t {
    attack = 0x00,
    attack_1 = 0x01,
    attack_2 = 0x02,
    attack_3 = 0x03,
    bite = 0x04,
    dead = 0x05,
    eating = 0x06,
    explotion = 0x07,
    fall = 0x08,
    grenade = 0x09,
    hurt = 0x0A,
    idle = 0x0B,
    jump = 0x0C,
    protect = 0x0D,
    recharge = 0x0E,
    run = 0x0F,
    run_attack = 0x10,
    scream = 0x11,
    smoke = 0x12,
    shot_1 = 0x13,
    shot_2 = 0x14,
    walk = 0x15,
    fin = 0x16
};

inline Type_of_action get_action(uint8_t id) {
    switch (id) {
        case 0x00:
            return attack;
        case 0x01:
            return attack_1;
        case 0x02:
            return attack_2;
        case 0x03:
            return attack_3;
        case 0x04:
            return bite;
        case 0x05:
            return dead;
        case 0x06:
            return eating;
        case 0x07:
            return explotion;
        case 0x08:
            return fall;
        case 0x09:
            return grenade;
        case 0x0A:
            return hurt;
        case 0x0B:
            return idle;
        case 0x0C:
            return jump;
        case 0x0D:
            return protect;
        case 0x0E:
            return recharge;
        case 0x0F:
            return run;
        case 0x10:
            return run_attack;
        case 0x11:
            return scream;
        case 0x12:
            return smoke;
        case 0x13:
            return shot_1;
        case 0x14:
            return shot_2;
        case 0x15:
            return walk;
        case 0x16:
            return fin;
        default:
            return idle;
    }
}

#endif