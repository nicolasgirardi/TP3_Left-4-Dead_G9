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
#include "client_singleanimation.h"

SingleAnimation::SingleAnimation(uint32_t frame,SDL2pp::Texture* texture,uint32_t time_between_frames,uint32_t number_of_frames,uint32_t size){
    animation = texture;
    global_frame = frame;
    total_frames = number_of_frames;
    frame_rate = time_between_frames;
    this->size = size;
}
void SingleAnimation::copy(uint32_t& frame,int& x,int& y,SDL2pp::Renderer* renderer,SDL_RendererFlip& invert){
    uint32_t local_frame = (frame - global_frame) / frame_rate;
    if  (local_frame < total_frames) {
        int val = size *(local_frame % total_frames);
        double angle = 0;
        renderer->Copy(*animation,SDL2pp::Rect(val,0,size,size),SDL2pp::Rect(x,y-size,size,size),0.0,SDL2pp::NullOpt,invert);
    } else {
        int val = size * (total_frames - 1);
        double angle = 0;
        renderer->Copy(*animation,SDL2pp::Rect(val,0,size,size),SDL2pp::Rect(x,y-size,size,size),0.0,SDL2pp::NullOpt,invert);
    }
}