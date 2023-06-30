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
#include "../include/client_spear.h"
#include "../../common_libs/include/common_center.h"
#include "../../common_libs/include/common_myenum.h"

Spear::Spear(int pos_x,int pos_y,int width,int height,std::vector<SDL2pp::Texture*>& texture,uint32_t frame,int ID):
    attack_1(frame,texture[0],4,4,128),
    attack_2(frame,texture[1],4,4,128),
    dead(frame,texture[2],4,5,128),
    fall(frame,texture[3],4,6,128),
    hurt(frame,texture[4],3,3,128),
    idle(frame,texture[5],3,7,128),
    protect(frame,texture[6],4,2,128),
    run(frame,texture[7],2,6,128),
    run_attack(frame,texture[81],2,5,128),
    walk(frame,texture[9],3,7,128)
{
    this->pos_x = pos_x;
    this->pos_y = (height * ((7*200) + pos_y )) / (200*8);
    this->width = width;
    this->height = height;
    current_animation = &idle;
    this->invert = SDL_FLIP_NONE;
    my_id = ID;
}
void Spear::copy(int& center,SDL2pp::Renderer* renderer,uint32_t& frame){
    int new_x = pos_x - center + (width/2) - 64; //el 64 hay que definirlo de alguna forma mejor
    current_animation->copy(frame,new_x,pos_y,renderer,invert);
}
void Spear::change_action(Type_of_action& code,uint32_t& frame){
    Animation* next_animation = current_animation;
    switch(code){
        case(Type_of_action::attack_1):
            next_animation = &attack_1;
            break;
        case(Type_of_action::attack_2):
            next_animation = &attack_2;
            break;
        case(Type_of_action::dead):
            next_animation = &dead;
            break;
        case(Type_of_action::fall):
            next_animation = &fall;
            break;
        case(Type_of_action::hurt):
            next_animation = &hurt;
            break;
        case(Type_of_action::idle):
            next_animation = &idle;
            break;
        case(Type_of_action::protect):
            next_animation = &protect;
            break;
        case(Type_of_action::run):
            next_animation = &run;
            break;
        case(Type_of_action::run_attack):
            next_animation = &run_attack;
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
void Spear::add_to_center(Center& center){
    //center.add_participation(0,0);
}