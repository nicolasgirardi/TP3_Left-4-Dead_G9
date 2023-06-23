#ifndef CLIENT_WAR3_H
#define CLIENT_WAR3_H

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


class War3: public Scenario{
    private:
    SDL2pp::Texture sky;
    SDL2pp::Texture house3;
    SDL2pp::Texture house2;
    SDL2pp::Texture trees;
    SDL2pp::Texture house1;
    SDL2pp::Texture fence;
    SDL2pp::Texture road;

    public:
    War3(int width,int height,std::vector<std::string>& textures,SDL2pp::Renderer* renderer);

    void copy(int center,SDL2pp::Renderer* renderer);

};
#endif
