#ifndef CLIENT_NOLOOPANIMATION_H
#define CLIENT_NOLOOPANIMATION_H

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

class NoLoopAnimation: public Animation{
    private:
    SDL2pp::Texture* second_animation;
    uint32_t total_frames2;
    uint32_t frame_rate2;
    public:
    NoLoopAnimation (uint32_t frame,SDL2pp::Texture* texture1,
                    uint32_t time_between_frames1,uint32_t number_of_frames1,
                    SDL2pp::Texture* texture2,
                    uint32_t time_between_frames2,uint32_t number_of_frames2);

    void copy(uint32_t frame,int x,int y,SDL2pp::Renderer* renderer,int invert);

    //void reset_local_frame(uint32_t frame);

};
#endif