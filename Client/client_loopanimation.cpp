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
#include "client_loopanimation.h"

LoopAnimation::LoopAnimation(uint32_t frame,SDL2pp::Texture* texture,uint32_t time_between_frames,uint32_t number_of_frames){
    animation = texture;
    global_frame = frame;
    total_frames = number_of_frames;
    frame_rate = time_between_frames;
}
void LoopAnimation::copy(uint32_t frame,int x,int y,SDL2pp::Renderer* renderer,int invert){
    uint32_t local_frame = (frame - global_frame) / frame_rate;
    //global_frame = frame;
    int val = 128 *(local_frame % total_frames);
    double angle = 0;
    renderer->Copy(*animation,SDL2pp::Rect(val,0,128,128),SDL2pp::Rect(x,y-64,64,64),0.0,SDL2pp::NullOpt,invert);
}