#ifndef CLIENT_WAR1_H
#define CLIENT_WAR1_H

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


class War4: public Scenario{
    private:
    SDL2pp::Texture sky;
    SDL2pp::Texture moon;
    SDL2pp::Texture ruins;
    SDL2pp::Texture house4;
    SDL2pp::Texture house3;
    SDL2pp::Texture house2;
    SDL2pp::Texture house1;
    SDL2pp::Texture wall;
    SDL2pp::Texture road;

    public:
    War4(int width,int height,std::vector<std::string>& textures,Renderer* renderer);

    void copy(int center,Renderer* renderer);

}