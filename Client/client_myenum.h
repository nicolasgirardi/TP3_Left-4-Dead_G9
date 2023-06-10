#ifndef CLIENT_MYENUM_H
#define CLIENT_MYENUM_H

enum Type_of_character {jumper, soldier1,soldier2,soldier3,spear,venom,witch,zombie};

enum Type_of_AMB {alta,baja,modificacion};

namespace myenum{

enum Type_of_action {attack,
                    attack_1,
                    attack_2,
                    attack_3,
                    bite,
                    dead,
                    eating,
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
                    shot_1,
                    shot_2,
                    walk};
}
#endif