#include <iostream>
#include <stdexcept>
#include <algorithm>

#include <SDL.h>

#include "SDL2pp/SDL.hh"
#include "SDL2pp/AudioDevice.hh"
#include "SDL2pp/AudioSpec.hh"
#include "SDL2pp/Wav.hh"
#include "SDL2pp/SDL2pp.hh"
#include "../include/common_animation.h"

void Animation::reset_local_frame(uint32_t& frame){
    global_frame = frame;
}