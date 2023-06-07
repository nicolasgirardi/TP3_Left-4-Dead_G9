#ifndef CLIENT_SOLDIER1TEXTURES_H
#define CLIENT_SOLDIER1TEXTURES_H

#include <iostream>
#include <stdexcept>
#include <algorithm>

#include <SDL.h>

#include <SDL2pp/SDL.hh>
#include <SDL2pp/AudioDevice.hh>
#include <SDL2pp/AudioSpec.hh>
#include <SDL2pp/Wav.hh>
#include <SDL2pp/SDL2pp.hh>
#include <vector>

class Soldier1_Textures{
    private:
    SDL2pp::Texture attack;
    SDL2pp::Texture dead;
    SDL2pp::Texture grenade;
    SDL2pp::Texture hurt;
    SDL2pp::Texture idle;
    SDL2pp::Texture recharge;
    SDL2pp::Texture run;
    SDL2pp::Texture shot_1;
    SDL2pp::Texture shot_2;
    SDL2pp::Texture walk;

    public:
    Soldier1_Textures(SDL2pp::Renderer* renderer);

    std::vector<SDL2pp::Texture*> all_textures();

};
#endif