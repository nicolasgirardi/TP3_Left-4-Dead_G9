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
#include "client_jumper.h"
#include "client_center.h"

Jumper::Jumper(int pos_x,int pos_y,int width,int height,std::vector<SDL2pp::Texture*>& texture,uint32_t frame):
    attack_1(frame,texture[0],1,4),
    attack_2(frame,texture[1],1,4),
    attack_3(frame,texture[2],1,4),
    dead(frame,texture[3],1,5),
    eating(frame,texture[4],1,11),
    hurt(frame,texture[5],1,5),
    idle(frame,texture[6],1,9),
    jump(frame,texture[7],1,6),
    run(frame,texture[81],1,8),
    walk(frame,texture[9],1,10)
{
    this->pos_x = pos_x;
    this->pos_y = pos_y;
    x = width;
    y = height;
    current_animation = &idle;
}
void Jumper::copy(int center,SDL2pp::Renderer* renderer,uint32_t frame){
    int new_x = pos_x - center + (x/2) - 64; //el 64 hay que definirlo de alguna forma mejor
    int new_y = (y*4/5) + (pos_y*y/500) - 64; //el 100 es el maximo y
    current_animation->copy(frame,new_x,new_y,renderer,invert);
}
void Jumper::change_action(int code,uint32_t frame){
    Animation* next_animation = current_animation;
    switch(code){
        case(0):
            next_animation = &attack_1;
            break;
        case(1):
            next_animation = &attack_2;
            break;
        case(2):
            next_animation = &attack_3;
            break;
        case(3):
            next_animation = &dead;
            break;
        case(4):
            next_animation = &eating;
            break;
        case(5):
            next_animation = &hurt;
            break;
        case(6):
            next_animation = &idle;
            break;
        case(7):
            next_animation = &jump;
            break;
        case(8):
            next_animation = &run;
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
void Jumper::add_to_center(Center& center){
    center.add_participation(0,0);
}