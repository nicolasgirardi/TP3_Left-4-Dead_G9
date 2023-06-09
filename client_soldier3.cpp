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
#include "client_soldier3.h"
#include "client_center.h"

Soldier3::Soldier3(int pos_x,int pos_y,int width,int height,std::vector<SDL2pp::Texture*>& texture,uint32_t frame,int ID):
    attack(frame,texture[0],1,5),
    dead(frame,texture[1],1,5),
    grenade(frame,texture[2],1,8),
    hurt(frame,texture[3],1,4),
    idle(frame,texture[4],1,7),
    Recharge(frame,texture[5],1,8),
    run(frame,texture[6],1,6),
    shot_1(frame,texture[7],1,4),
    shot_2(frame,texture[81],1,4),
    walk(frame,texture[9],1,8)
{
    this->pos_x = pos_x;
    this->pos_y = (height * ((7*200) + pos_y )) / (200*8);
    this->width = width;
    this->height = height;
    current_animation = &idle;
    my_id = ID;
}
void Soldier3::copy(int center,SDL2pp::Renderer* renderer,uint32_t frame){
    int new_x = pos_x - center + (width/2) - 64; //el 64 hay que definirlo de alguna forma mejor
    current_animation->copy(frame,new_x,pos_y,renderer,invert);
}
void Soldier3::change_action(int code,uint32_t frame){
    Animation* next_animation = current_animation;
    switch(code){
        case(0):
            next_animation = &attack;
            break;
        case(1):
            next_animation = &dead;
            break;
        case(2):
            next_animation = &grenade;
            break;
        case(3):
            next_animation = &hurt;
            break;
        case(4):
            next_animation = &idle;
            break;
        case(5):
            next_animation = &Recharge;
            break;
        case(6):
            next_animation = &run;
            break;
        case(7):
            next_animation = &shot_1;
            break;
        case(8):
            next_animation = &shot_2;
            break;
        case(9):
            next_animation = &walk;
            break;
    }
    if(next_animation != current_animation){
        current_animation = next_animation;
        current_animation->reset_local_frame(frame);
    }
        
}
void Soldier3::add_to_center(Center& center){
    center.add_participation(pos_x);
}