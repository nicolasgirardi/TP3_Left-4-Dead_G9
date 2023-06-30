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
#include "../include/client_loopanimation.h"
#include "../include/client_singleanimation.h"
#include "../include/client_noloopanimation.h"
#include "../include/client_soldier2.h"
#include "../../common_libs/include/common_center.h"
#include "../../common_libs/include/common_myenum.h"

Soldier2::Soldier2(int pos_x,int pos_y,int width,int height,std::vector<SDL2pp::Texture*>& texture,uint32_t frame,int ID,uint32_t ammo,uint32_t hp):
    attack(frame,texture[0],4,4,128),
    dead(frame,texture[1],5,4,128),
    grenade(frame,texture[2],3,16,128,texture[4],3,9,128),
    hurt(frame,texture[3],3,3,128),
    idle(frame,texture[4],3,9,128),
    Recharge(frame,texture[5],2,7,128,texture[4],3,9,128),
    run(frame,texture[6],2,8,128),
    shot_1(frame,texture[7],2,4,128),
    shot_2(frame,texture[8],2,4,128),
    walk(frame,texture[9],3,8,128)
{
    this->pos_x = pos_x;
    this->pos_y = (height * ((7*200) + pos_y )) / (200*8);
    this->width = width;
    this->height = height;
    current_animation = &idle;
    this->invert = SDL_FLIP_NONE;
    my_id = ID;
    this->ammo = ammo;
    this->hp = hp;
}
void Soldier2::copy(int& center,SDL2pp::Renderer* renderer,uint32_t& frame){
    int new_x = pos_x - center + (width/2) - 64; //el 64 hay que definirlo de alguna forma mejor
    current_animation->copy(frame,new_x,pos_y,renderer,invert);
}
void Soldier2::change_action(Type_of_action& code,uint32_t& frame){
    Animation* next_animation = current_animation;
    switch(code){
        case(Type_of_action::attack):
            next_animation = &attack;
            break;
        case(Type_of_action::dead):
            next_animation = &dead;
            break;
        case(Type_of_action::grenade):
            next_animation = &grenade;
            break;
        case(Type_of_action::hurt):
            next_animation = &hurt;
            break;
        case(Type_of_action::idle):
            next_animation = &idle;
            break;
        case(Type_of_action::recharge):
            next_animation = &Recharge;
            break;
        case(Type_of_action::run):
            next_animation = &run;
            break;
        case(Type_of_action::shot_1):
            next_animation = &shot_1;
            break;
        case(Type_of_action::shot_2):
            next_animation = &shot_2;
            break;
        case(Type_of_action::walk):
            next_animation = &walk;
            break;
    }
    if(next_animation != current_animation){
        current_animation = next_animation;
        current_animation->reset_local_frame(frame);
    }
        
}
void Soldier2::add_to_center(Center& center){
    center.add_participation(pos_x);
}