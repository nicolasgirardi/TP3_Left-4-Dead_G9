#ifndef CLIENT_SINGLEANIMATION_H
#define CLIENT_SINGLEANIMATION_H

#include <iostream>
#include <stdexcept>
#include <algorithm>

#include <SDL.h>

#include <SDL2pp/SDL.hh>
#include <SDL2pp/AudioDevice.hh>
#include <SDL2pp/AudioSpec.hh>
#include <SDL2pp/Wav.hh>
#include <SDL2pp/SDL2pp.hh>
#include "client_animation.h"

class SingleAnimation: public Animation{
    public:
    SingleAnimation(uint32_t frame,SDL2pp::Texture* texture,uint32_t time_between_frames,uint32_t number_of_frames);

    void copy(uint32_t frame,int x,int y,SDL2pp::Renderer* renderer,int invert);

    //void reset_local_frame(uint32_t frame);

};
#endif