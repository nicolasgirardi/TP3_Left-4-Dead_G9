#include <iostream>
#include <stdexcept>
#include <algorithm>

#include <SDL.h>

#include <SDL2pp/SDL.hh>
#include <SDL2pp/AudioDevice.hh>
#include <SDL2pp/AudioSpec.hh>
#include <SDL2pp/Wav.hh>
#include <SDL2pp/SDL2pp.hh>
#include "../include/client_scenario.h"
#include "../include/client_war2.h"

War2::War2(int width,int height,std::vector<std::string>& textures,SDL2pp::Renderer* renderer): 
	sky(*renderer,textures[0]),
	house4(*renderer,textures[1]),
	house3(*renderer,textures[2]),
	house2(*renderer,textures[3]),
	house1(*renderer,textures[4]),
	wall(*renderer,textures[5]),
	road(*renderer,textures[6])
{
    x = width;
    y = height;
}
void War2::copy(int center, SDL2pp::Renderer* renderer){
    renderer->Copy(sky,SDL2pp::Rect(0,0,1920,1080),SDL2pp::Rect(0,0,x,y));
	renderer->Copy(house4,SDL2pp::Rect(0,0,1920,1080),SDL2pp::Rect(-center_scenario(center/32),0,x,y));
	renderer->Copy(house4,SDL2pp::Rect(0,0,1920,1080),SDL2pp::Rect(x-center_scenario(center/32),0,x,y));
	renderer->Copy(house3,SDL2pp::Rect(0,0,1920,1080),SDL2pp::Rect(-center_scenario(center/16),0,x,y));
	renderer->Copy(house3,SDL2pp::Rect(0,0,1920,1080),SDL2pp::Rect(x-center_scenario(center/16),0,x,y));
	renderer->Copy(house2,SDL2pp::Rect(0,0,1920,1080),SDL2pp::Rect(-center_scenario(center/8),0,x,y));
	renderer->Copy(house2,SDL2pp::Rect(0,0,1920,1080),SDL2pp::Rect(x-center_scenario(center/8),0,x,y));
	renderer->Copy(house1,SDL2pp::Rect(0,0,1920,1080),SDL2pp::Rect(-center_scenario(center/4),0,x,y));
	renderer->Copy(house1,SDL2pp::Rect(0,0,1920,1080),SDL2pp::Rect(x-center_scenario(center/4),0,x,y));
	renderer->Copy(wall,SDL2pp::Rect(0,0,1920,1080),SDL2pp::Rect(-center_scenario(center/2),0,x,y));
	renderer->Copy(wall,SDL2pp::Rect(0,0,1920,1080),SDL2pp::Rect(x-center_scenario(center/2),0,x,y));
	renderer->Copy(road,SDL2pp::Rect(0,0,1920,1080),SDL2pp::Rect(-center_scenario(center),0,x,y));
	renderer->Copy(road,SDL2pp::Rect(0,0,1920,1080),SDL2pp::Rect(x-center_scenario(center),0,x,y));
}