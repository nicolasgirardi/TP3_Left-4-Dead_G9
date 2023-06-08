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
#include "client_character.h"
#include "client_animation.h"
#include "client_center.h"


class Soldier3: public Character {
    private:
    Animation attack;
    Animation dead;
    Animation grenade;
    Animation hurt;
    Animation idle;
    Animation Recharge;
    Animation run;
    Animation shot_1;
    Animation shot_2;
    Animation walk;

    public:
    Soldier3(int pos_x,int pos_y,int width,int height,std::vector<SDL2pp::Texture*>& texture,uint32_t frame);

    void copy(int center,SDL2pp::Renderer* renderer,uint32_t frame);

    void change_action(int code,uint32_t frame);

    void change_position(int x,int y);

    void add_to_center(Center& center);
    

};
#endif