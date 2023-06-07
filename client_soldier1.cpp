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
#include "client_soldier1.h"
#include "client_center.h"

Soldier1::Soldier1(int pos_x,int pos_y,int width,int height,std::vector<SDL2pp::Texture*>& texture,uint32_t frame):
    attack(frame,texture[0],1,3),
    dead(frame,texture[1],1,4),
    grenade(frame,texture[2],1,9),
    hurt(frame,texture[3],1,3),
    idle(frame,texture[4],1,7),
    Recharge(frame,texture[5],1,13),
    run(frame,texture[6],1,8),
    shot_1(frame,texture[7],1,4),
    shot_2(frame,texture[81],1,4),
    walk(frame,texture[9],1,7)
{
    this->pos_x = pos_x;
    this->pos_y = pos_y;
    x = width;
    y = height;
    current_animation = &idle;
}
void Soldier1::copy(int center,SDL2pp::Renderer* renderer,uint32_t frame){
    int new_x = pos_x - center + (x/2) - 64; //el 64 hay que definirlo de alguna forma mejor
    int new_y = (y*4/5) + (pos_y*y/500) - 64; //el 100 es el maximo y
    current_animation->copy(frame,new_x,new_y,renderer,invert);
}
void Soldier1::change_action(int code,uint32_t frame){
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
void Soldier1::add_to_center(Center& center){
    center.add_participation(pos_x);
}