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
#include "client_center.h"

void Character::set_position(int& x,int& y){
    if (x < pos_x)
        invert = SDL_FLIP_HORIZONTAL;
    if (x > pos_x)
        invert = SDL_FLIP_NONE;
    if(x != pos_x)
        pos_x = x;
    if(y != pos_y)
        pos_y = (height * ((7*200) + y )) / (200*8);
}
int Character::get_vertical(){
    return pos_y;
}
bool Character::is(int& another_id){
    return my_id == another_id;
}
void Character::set_ammo(uint32_t ammo){
    this->ammo = ammo;
}
void Character::set_hp(uint32_t hp){
    this->hp = hp;
}
uint32_t Character::get_ammo(){
    return ammo;
}
uint32_t Character::get_hp(){
    return hp;
}