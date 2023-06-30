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
#include "../include/client_smoke.h"
#include "../../common_libs/include/common_center.h"
#include "../../common_libs/include/common_myenum.h"

Smoke::Smoke(int pos_x,int pos_y,int width,int height,std::vector<SDL2pp::Texture*>& texture,uint32_t frame,int ID):
    idle(frame,texture[0],1,1,128),
    smoke(frame,texture[0],2,22,128,texture[0],1,1,128)
{
    this->pos_x = pos_x;
    this->pos_y = (height * ((7*200) + pos_y )) / (200*8);
    this->width = width;
    this->height = height;
    this->invert = SDL_FLIP_NONE;
    current_animation = &idle;
    my_id = ID;
}
void Smoke::copy(int& center,SDL2pp::Renderer* renderer,uint32_t& frame){
    int new_x = pos_x - center + (width/2) - 64; //el 64 hay que definirlo de alguna forma mejor
    current_animation->copy(frame,new_x,pos_y,renderer,invert);
}
void Smoke::change_action(Type_of_action& code,uint32_t& frame){
    Animation* next_animation = current_animation;
    switch(code){
        case(Type_of_action::smoke):
            next_animation = &smoke;
            break;
        case(Type_of_action::idle):
            next_animation = &idle;
            break;
    }
    if(next_animation != current_animation){
        current_animation = next_animation;
        current_animation->reset_local_frame(frame);
    }
        
}
void Smoke::add_to_center(Center& center){
    //center.add_participation(0,0);
}