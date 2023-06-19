#ifndef CLIENT_CHARACTER_H
#define CLIENT_CHARACTER_H

#include <iostream>
#include <stdexcept>
#include <algorithm>

#include <SDL.h>

#include <SDL2pp/SDL.hh>
#include <SDL2pp/AudioDevice.hh>
#include <SDL2pp/AudioSpec.hh>
#include <SDL2pp/Wav.hh>
#include <SDL2pp/SDL2pp.hh>
#include "client_animation.h"
#include "client_center.h"
#include "client_myenum.h"

class Character{
    protected:
    int width;
    int height;
    int pos_x;
    int pos_y;
    int my_id;
    SDL_RendererFlip invert;
    Animation* current_animation;
    uint32_t hp;
    uint32_t ammo;

    public:
    Character(){};

    virtual void copy(int& center,SDL2pp::Renderer* renderer,uint32_t& frame) = 0;
    void set_position(int& horizontal,int& vertical);
    int get_vertical();
    virtual void add_to_center(Center& center) = 0;
    virtual void change_action(myenum::Type_of_action& code,uint32_t& frame) = 0;
    bool is(int& another_id);
    void set_hp(uint32_t hp);
    void set_ammo(uint32_t ammo);
    uint32_t get_hp();
    uint32_t get_ammo();
    virtual ~Character(){};

    Character(const Character&) = delete;
    Character& operator=(const Character&) = delete;

    Character(Character&& other) = delete;
    Character& operator=(Character&& other) = delete;

};
#endif