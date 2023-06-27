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
#include "../include/client_jumper.h"
#include "../../common_libs/include/common_center.h"
#include "../../common_libs/include/common_myenum.h"

Jumper::Jumper(int pos_x,int pos_y,int width,int height,std::vector<SDL2pp::Texture*>& texture,uint32_t frame,int ID):
    attack_1(frame,texture[0],4,4,96),
    attack_2(frame,texture[1],4,4,96),
    attack_3(frame,texture[2],4,4,96),
    dead(frame,texture[3],4,5,96),
    eating(frame,texture[4],3,11,96),
    hurt(frame,texture[5],3,5,96),
    idle(frame,texture[6],2,9,96),
    jump(frame,texture[7],3,6,96),
    run(frame,texture[81],2,8,96),
    walk(frame,texture[9],3,10,96)
{
    this->pos_x = pos_x;
    this->pos_y = (height * ((7*200) + pos_y )) / (200*8);
    this->width = width;
    this->height = height;
    this->invert = SDL_FLIP_NONE;
    current_animation = &idle;
    my_id = ID;
}
void Jumper::copy(int& center,SDL2pp::Renderer* renderer,uint32_t& frame){
    int new_x = pos_x - center + (width/2) - 64; //el 64 hay que definirlo de alguna forma mejor
    current_animation->copy(frame,new_x,pos_y,renderer,invert);
}
void Jumper::change_action(myenum::Type_of_action& code,uint32_t& frame){
    Animation* next_animation = current_animation;
    switch(code){
        case(myenum::attack_1):
            next_animation = &attack_1;
            break;
        case(myenum::attack_2):
            next_animation = &attack_2;
            break;
        case(myenum::attack_3):
            next_animation = &attack_3;
            break;
        case(myenum::dead):
            next_animation = &dead;
            break;
        case(myenum::eating):
            next_animation = &eating;
            break;
        case(myenum::hurt):
            next_animation = &hurt;
            break;
        case(myenum::idle):
            next_animation = &idle;
            break;
        case(myenum::jump):
            next_animation = &jump;
            break;
        case(myenum::run):
            next_animation = &run;
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
void Jumper::add_to_center(Center& center){
    //center.add_participation(0,0);
}