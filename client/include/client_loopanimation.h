#ifndef CLIENT_LOOPANIMATION_H
#define CLIENT_LOOPANIMATION_H

#include <iostream>
#include <stdexcept>
#include <algorithm>

#include <SDL.h>

#include <SDL2pp/SDL.hh>
#include <SDL2pp/AudioDevice.hh>
#include <SDL2pp/AudioSpec.hh>
#include <SDL2pp/Wav.hh>
#include <SDL2pp/SDL2pp.hh>
#include "../../common_libs/include/common_animation.h"

class LoopAnimation: public Animation{
    public:
    LoopAnimation(uint32_t frame,SDL2pp::Texture* texture,uint32_t time_between_frames,uint32_t number_of_frames,uint32_t size);

    void copy(uint32_t& frame,int& x,int& y,SDL2pp::Renderer* renderer,SDL_RendererFlip& invert);

    //void reset_local_frame(uint32_t frame);

};
#endif