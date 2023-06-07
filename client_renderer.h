#ifndef CLIENT_RENDERER_H
#define CLIENT_RENDERER_H
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
#include "client_sprite.h"
#include <memory>

class Renderer {
    private:
    int width;
    int height;
    std::vector<std::shared_ptr<Sprite>> all_sprites;

    public:
    Renderer(int width, int height);

    
};
#endif
