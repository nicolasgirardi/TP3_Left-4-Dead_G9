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
#include "client_noloopanimation.h"

NoLoopAnimation::NoLoopAnimation (uint32_t frame,SDL2pp::Texture* texture1,
                    uint32_t time_between_frames1,uint32_t number_of_frames1,
                    SDL2pp::Texture* texture2,
                    uint32_t time_between_frames2,uint32_t number_of_frames2){
    animation = texture1;
    global_frame = frame;
    total_frames = number_of_frames1;
    frame_rate = time_between_frames1;
    total_frames2 = number_of_frames2;
    frame_rate2 = time_between_frames2;

}
void NoLoopAnimation::copy(uint32_t& frame,int& x,int& y,SDL2pp::Renderer* renderer,SDL_RendererFlip& invert){
    uint32_t local_frame = (frame - global_frame) / frame_rate;
    if  (local_frame < total_frames) {
    //global_frame = frame;
        int val = 128 *(local_frame % total_frames);
        double angle = 0;
        renderer->Copy(*animation,SDL2pp::Rect(val,0,128,128),SDL2pp::Rect(x,y-64,64,64),0.0,SDL2pp::NullOpt,invert);
    } else {
        local_frame = (frame - global_frame) / frame_rate2;
        int val = 128 *(local_frame % total_frames2);
        double angle = 0;
        renderer->Copy(*animation,SDL2pp::Rect(val,0,128,128),SDL2pp::Rect(x,y-64,64,64),0.0,SDL2pp::NullOpt,invert);
    }
}