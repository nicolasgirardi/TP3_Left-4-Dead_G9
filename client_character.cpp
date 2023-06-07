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

void Character::set_position(int x,int y){
    if (x < pos_x)
        invert = SDL_FLIP_HORIZONTAL;
    if (x > pos_x)
        invert = SDL_FLIP_NONE;
    pos_x = x;
    pos_y = y;
}
int Character::get_vertical(){
    return pos_y;
}