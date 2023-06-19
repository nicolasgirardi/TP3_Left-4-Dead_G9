#ifndef CLIENT_WAR2_H
#define CLIENT_WAR2_H

#include <iostream>
#include <stdexcept>
#include <algorithm>

#include <SDL.h>

#include <SDL2pp/SDL.hh>
#include <SDL2pp/AudioDevice.hh>
#include <SDL2pp/AudioSpec.hh>
#include <SDL2pp/Wav.hh>
#include <SDL2pp/SDL2pp.hh>
#include "client_scenario.h"


class War2: public Scenario{
    private:
    SDL2pp::Texture sky;
    SDL2pp::Texture house4;
    SDL2pp::Texture house3;
    SDL2pp::Texture house2;
    SDL2pp::Texture house1;
    SDL2pp::Texture wall;
    SDL2pp::Texture road;

    public:
    War2(int width,int height,std::vector<std::string>& textures,SDL2pp::Renderer* renderer);

    void copy(int center,SDL2pp::Renderer* renderer);

};
#endif