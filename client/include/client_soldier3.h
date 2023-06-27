#ifndef CLIENT_SOLDIER3_H
#define CLIENT_SOLDIER3_H

#include <iostream>
#include <stdexcept>
#include <algorithm>

#include <SDL.h>

#include <SDL2pp/SDL.hh>
#include <SDL2pp/AudioDevice.hh>
#include <SDL2pp/AudioSpec.hh>
#include <SDL2pp/Wav.hh>
#include <SDL2pp/SDL2pp.hh>
#include "../../common_libs/include/common_character.h"
#include "../../common_libs/include/common_animation.h"
#include "client_loopanimation.h"
#include "client_singleanimation.h"
#include "client_noloopanimation.h"
#include "../../common_libs/include/common_center.h"
#include "../../common_libs/include/common_myenum.h"


class Soldier3: public Character {
    private:
    LoopAnimation attack;
    SingleAnimation dead;
    NoLoopAnimation grenade;
    LoopAnimation hurt;
    LoopAnimation idle;
    NoLoopAnimation Recharge;
    LoopAnimation run;
    LoopAnimation shot_1;
    LoopAnimation shot_2;
    LoopAnimation walk;

    public:
    Soldier3(int pos_x,int pos_y,int width,int height,std::vector<SDL2pp::Texture*>& texture,uint32_t frame,int ID,uint32_t ammo,uint32_t hp);

    void copy(int& center,SDL2pp::Renderer* renderer,uint32_t& frame);

    void change_action(myenum::Type_of_action& code,uint32_t& frame);

    void change_position(int& x,int& y);

    void add_to_center(Center& center);
    

};
#endif