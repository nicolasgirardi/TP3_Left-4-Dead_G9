#include <iostream>
#include <stdexcept>
#include <algorithm>

#include <SDL.h>

#include <SDL2pp/SDL.hh>
#include <SDL2pp/AudioDevice.hh>
#include <SDL2pp/AudioSpec.hh>
#include <SDL2pp/Wav.hh>
#include <SDL2pp/SDL2pp.hh>
#include "client_Textureholder.h"
#include <vector>

Texture_holder::Texture_holder(SDL2pp::Renderer* renderer,std::vector<std::string>& paths) 
{
    for(int i =0; i< (int) paths.size();i++)
        textures.push_back(SDL2pp::Texture(*renderer,paths[i]));
}
std::vector<SDL2pp::Texture*> Texture_holder::all_textures(){
    std::vector<SDL2pp::Texture*> all_textures;
    for(int i =0; i< (int) textures.size();i++)
        all_textures.push_back(&textures[i]);
    return all_textures;
}