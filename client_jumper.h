#ifndef CLIENT_JUMPER_H
#define CLIENT_JUMPER_H

#include <iostream>
#include <stdexcept>
#include <algorithm>

#include <SDL.h>

#include <SDL2pp/SDL.hh>
#include <SDL2pp/AudioDevice.hh>
#include <SDL2pp/AudioSpec.hh>
#include <SDL2pp/Wav.hh>
#include <SDL2pp/SDL2pp.hh>
#include "client_character.h"
#include "client_animation.h"
#include "client_loopanimation.h"
#include "client_singleanimation.h"
#include "client_center.h"


class Jumper: public Character {
    private:
    LoopAnimation attack_1;
    LoopAnimation attack_2;
    LoopAnimation attack_3;
    SingleAnimation dead;
    LoopAnimation eating;
    LoopAnimation hurt;
    LoopAnimation idle;
    LoopAnimation jump;
    LoopAnimation run;
    LoopAnimation walk;

    public:
    Jumper(int pos_x,int pos_y,int width,int height,std::vector<SDL2pp::Texture*>& texture,uint32_t frame);

    void copy(int center,SDL2pp::Renderer* renderer,uint32_t frame);

    void change_action(int code,uint32_t frame);

    void change_position(int x,int y);

    void add_to_center(Center& center);
    

};
#endif