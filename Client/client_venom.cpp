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
#include "client_venom.h"
#include "client_center.h"
#include "client_myenum.h"

Venom::Venom(int pos_x,int pos_y,int width,int height,std::vector<SDL2pp::Texture*>& texture,uint32_t frame,int ID):
    attack_1(frame,texture[0],1,8),
    attack_2(frame,texture[1],1,14),
    dead(frame,texture[2],1,6),
    hurt(frame,texture[3],1,3),
    idle(frame,texture[4],1,7),
    jump(frame,texture[5],1,9),
    run(frame,texture[6],1,8),
    walk(frame,texture[7],1,6)
{
    this->pos_x = pos_x;
    this->pos_y = (height * ((7*200) + pos_y )) / (200*8);
    this->width = width;
    this->height = height;
    current_animation = &idle;
    my_id = ID;
}
void Venom::copy(int center,SDL2pp::Renderer* renderer,uint32_t frame){
    int new_x = pos_x - center + (width/2) - 64; //el 64 hay que definirlo de alguna forma mejor
    current_animation->copy(frame,new_x,pos_y,renderer,invert);
}
void Venom::change_action(myenum::Type_of_action code,uint32_t frame){
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
void Venom::add_to_center(Center& center){
    center.add_participation(0,0);
}