#ifndef CLIENT_ANIMATION_H
#define CLIENT_ANIMATION_H

#include <iostream>
#include <stdexcept>
#include <algorithm>

#include <SDL.h>

#include <SDL2pp/SDL.hh>
#include <SDL2pp/AudioDevice.hh>
#include <SDL2pp/AudioSpec.hh>
#include <SDL2pp/Wav.hh>
#include <SDL2pp/SDL2pp.hh>

class Animation{
    protected:
    SDL2pp::Texture* animation;
    uint32_t global_frame;
    uint32_t total_frames;
    uint32_t frame_rate;
    uint32_t size;

    public:
    Animation(){};

    virtual void copy(uint32_t& frame,int& x,int& y,SDL2pp::Renderer* renderer,SDL_RendererFlip& invert) = 0; 

    void reset_local_frame(uint32_t& frame);

};
#endif