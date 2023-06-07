#include <iostream>

#include <SDL.h>

#include <SDL2pp/SDL.hh>
#include <SDL2pp/AudioDevice.hh>
#include <SDL2pp/AudioSpec.hh>
#include <SDL2pp/Wav.hh>
#include <SDL2pp/SDL2pp.hh>
#include "client_scenario.h"
#include "client_war1.h"
#include "client_character.h"
#include "client_soldier1.h"
#include "client_center.h"
#include "client_renderer.h"
#include <memory>

Renderer::Renderer(int width,int height){
    this->width = width;
    this height = height;
    std::fstream path;
    std::string name;
    path.open("../resources/paths");
    while(std::getline(path,name)){
        all_sprites.push_back()
    }

}