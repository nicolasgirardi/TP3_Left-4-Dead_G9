#ifndef CLIENT_SCENARIO_H
#define CLIENT_SCENARIO_H

#include <iostream>
#include <stdexcept>
#include <algorithm>

#include <SDL.h>

#include <SDL2pp/SDL.hh>
#include <SDL2pp/AudioDevice.hh>
#include <SDL2pp/AudioSpec.hh>
#include <SDL2pp/Wav.hh>
#include <SDL2pp/SDL2pp.hh>


class Scenario{
    protected:
    int x;
    int y;

    public:
    Scenario(){};

    virtual void copy(int center,SDL2pp::Renderer* renderer) = 0;
    virtual ~Scenario(){};
    int center_scenario(int value);

    Scenario(const Scenario&) = delete;
    Scenario& operator=(const Scenario&) = delete;

    Scenario(Scenario&& other) = delete;
    Scenario& operator=(Scenario&& other) = delete;

};
#endif
