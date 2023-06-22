#ifndef CLIENT_MYENUM_H
#define CLIENT_MYENUM_H

enum Type_of_character {jumper, soldier1,soldier2,soldier3,spear,venom,witch,zombie,explotion,smoke};

enum Type_of_AMB {alta,baja,modificacion};

enum Type_of_map {war1_bright,war1_pale,war2_bright,war2_pale,war3_bright,war3_pale,war4_bright,war4_pale}

namespace myenum{

enum Type_of_action {attack,
                    attack_1,
                    attack_2,
                    attack_3,
                    bite,
                    dead,
                    eating,
                    explotion,
                    fall,
                    grenade,
                    hurt,
                    idle,
                    jump,
                    protect,
                    recharge,
                    run,
                    run_attack,
                    scream,
                    smoke,
                    shot_1,
                    shot_2,
                    walk};
}
#endif