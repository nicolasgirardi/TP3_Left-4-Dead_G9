#ifndef CLIENT_VENOM_H
#define CLIENT_VENOM_H

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
#include "../../common_libs/include/common_center.h"
#include "../../common_libs/include/common_myenum.h"

class Venom: public Character {
    private:
    LoopAnimation attack_1;
    LoopAnimation attack_2;
    SingleAnimation dead;
    LoopAnimation hurt;
    LoopAnimation idle;
    LoopAnimation jump;
    LoopAnimation run;
    LoopAnimation walk;

    public:
    Venom(int pos_x,int pos_y,int width,int height,std::vector<SDL2pp::Texture*>& texture,uint32_t frame,int ID);

    void copy(int& center,SDL2pp::Renderer* renderer,uint32_t& frame);

    void change_action(myenum::Type_of_action& code,uint32_t& frame);

    void change_position(int& x,int& y);

    void add_to_center(Center& center);
    

};
#endif