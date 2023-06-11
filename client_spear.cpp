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
#include "client_spear.h"
#include "client_center.h"
#include "client_myenum.h"

Spear::Spear(int pos_x,int pos_y,int width,int height,std::vector<SDL2pp::Texture*>& texture,uint32_t frame,int ID):
    attack_1(frame,texture[0],1,4),
    attack_2(frame,texture[1],1,4),
    dead(frame,texture[2],1,5),
    fall(frame,texture[3],1,6),
    hurt(frame,texture[4],1,3),
    idle(frame,texture[5],1,7),
    protect(frame,texture[6],1,2),
    run(frame,texture[7],1,6),
    run_attack(frame,texture[81],1,5),
    walk(frame,texture[9],1,7)
{
    this->pos_x = pos_x;
    this->pos_y = (height * ((7*200) + pos_y )) / (200*8);
    this->width = width;
    this->height = height;
    current_animation = &idle;
    my_id = ID;
}
void Spear::copy(int& center,SDL2pp::Renderer* renderer,uint32_t& frame){
    int new_x = pos_x - center + (width/2) - 64; //el 64 hay que definirlo de alguna forma mejor
    current_animation->copy(frame,new_x,pos_y,renderer,invert);
}
void Spear::change_action(myenum::Type_of_action& code,uint32_t& frame){
    Animation* next_animation = current_animation;
    switch(code){
        case(myenum::attack_1):
            next_animation = &attack_1;
            break;
        case(myenum::attack_2):
            next_animation = &attack_2;
            break;
        case(myenum::dead):
            next_animation = &dead;
            break;
        case(myenum::fall):
            next_animation = &fall;
            break;
        case(myenum::hurt):
            next_animation = &hurt;
            break;
        case(myenum::idle):
            next_animation = &idle;
            break;
        case(myenum::protect):
            next_animation = &protect;
            break;
        case(myenum::run):
            next_animation = &run;
            break;
        case(myenum::run_attack):
            next_animation = &run_attack;
            break;
        case(myenum::walk):
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