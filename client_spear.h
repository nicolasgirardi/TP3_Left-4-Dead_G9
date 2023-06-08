#ifndef CLIENT_SPEAR_H
#define CLIENT_SPEAR_H

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
#include "client_center.h"


class Spear: public Character {
    private:
    Animation attack_1;
    Animation attack_2;
    Animation dead;
    Animation fall;
    Animation hurt;
    Animation idle;
    Animation protect;
    Animation run;
    Animation run_attack;
    Animation walk;

    public:
    Spear(int pos_x,int pos_y,int width,int height,std::vector<SDL2pp::Texture*>& texture,uint32_t frame);

    void copy(int center,SDL2pp::Renderer* renderer,uint32_t frame);

    void change_action(int code,uint32_t frame);

    void change_position(int x,int y);

    void add_to_center(Center& center);
    

};
#endif