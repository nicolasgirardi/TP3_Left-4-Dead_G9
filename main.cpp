#include <iostream>
#include <stdexcept>
#include <algorithm>

#include <SDL.h>

#include <SDL2pp/SDL.hh>
#include <SDL2pp/AudioDevice.hh>
#include <SDL2pp/AudioSpec.hh>
#include <SDL2pp/Wav.hh>
#include <SDL2pp/SDL2pp.hh>
#include "client_renderer.h"
#include <chrono>
#include "client_queue.h"
#include <memory>


int main(int, char*[]){
	Thread* my_renderer;
	my_renderer = new MyRenderer(960,720,1,1);
	my_renderer->start();
	my_renderer->join();
	delete my_renderer;
	return 0;
}