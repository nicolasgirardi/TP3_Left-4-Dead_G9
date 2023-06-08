#ifndef CLIENT_TEXTUREHOLDER_H
#define CLIENT_TEXTUREHOLDER_H

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

class Texture_holder{
    private:

    std::vector<SDL2pp::Texture> textures;

    public:
    Texture_holder(SDL2pp::Renderer* renderer,std::vector<std::string>& paths);
    
    std::vector<SDL2pp::Texture*> all_textures();
};
#endif