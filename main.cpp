/*
  libSDL2pp - C++11 bindings/wrapper for SDL2
  Copyright (C) 2013-2015 Dmitry Marakasov <amdmi3@amdmi3.ru>

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
*/

#include <iostream>
#include <stdexcept>
#include <algorithm>

#include <SDL.h>

#include <SDL2pp/SDL.hh>
#include <SDL2pp/AudioDevice.hh>
#include <SDL2pp/AudioSpec.hh>
#include <SDL2pp/Wav.hh>
#include <SDL2pp/SDL2pp.hh>
#include "client_scenario.h"
#include "client_war1.h"
#include "client_character.h"
#include "client_soldier1.h"
#include "client_textureholder.h"
#include "client_center.h"
#include "client_constants.h"
#include <chrono>
#include <memory>

using namespace SDL2pp;

using namespace paths;

int foo(int value){
	if(value<800)
		return value;
	else
		return(foo(value-800));
}
int main(int, char*[]) try {
	SDL sdl(SDL_INIT_AUDIO | SDL_INIT_VIDEO);

	Wav wav("../resources/Music/StartMenu.wav");
	Uint8* wav_pos = wav.GetBuffer();

	// Open audio device
	AudioDevice dev(NullOpt, 0, wav.GetSpec(), [&wav, &wav_pos](Uint8* stream, int len) {
				// Fill provided buffer with wave contents
				Uint8* stream_pos = stream;
				Uint8* stream_end = stream + len;

				while (stream_pos < stream_end) {
					Uint8* wav_end = wav.GetBuffer() + wav.GetLength();

					size_t copylen = std::min(wav_end - wav_pos, stream_end - stream_pos);

					std::copy(wav_pos, wav_pos + copylen, stream_pos);
					stream_pos += copylen;
					wav_pos += copylen;
					if (wav_pos >= wav_end)
						wav_pos = wav.GetBuffer();
				}
			}
		);
	Window window("Left 4 Dead",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			960, 720,
			SDL_WINDOW_RESIZABLE);

	// Create accelerated video renderer with default driver
	Renderer renderer(window, -1, SDL_RENDERER_ACCELERATED);
	/*
	Texture sprites9(renderer,"../resources/Soldier_1/Run.png");
	Texture sprites10(renderer,"../resources/Soldier_2/Run.png");
	*/
	uint32_t frame = 0;
	int pos1 = 450;
	int pos2 = 400;
	std::vector<std::string> soldier_type_1 = {
		Soldier_1_Attack,
		Soldier_1_Dead,
		Soldier_1_Grenade,
		Soldier_1_Hurt,
		Soldier_1_Idle,
		Soldier_1_Recharge,
		Soldier_1_Run,
		Soldier_1_Shot_1,
		Soldier_1_Shot_2,
		Soldier_1_Walk
	};
	Texture_holder soldier1_textures(&renderer,soldier_type_1);
	std::vector<Texture*> textures_s1 = soldier1_textures.all_textures();
	std::unique_ptr<Character> soldier1(new Soldier1(pos1,50,960,720,textures_s1,frame));
	std::unique_ptr<Character> soldier2(new Soldier1(pos2,60,960,720,textures_s1,frame));
	std::vector<std::string> textures;
	textures.push_back(backgrounds_War1_Pale_sky);
	textures.push_back(backgrounds_War1_Pale_sun);
	textures.push_back(backgrounds_War1_Pale_ruins);
	textures.push_back(backgrounds_War1_Pale_house3);
	textures.push_back(backgrounds_War1_Pale_houses2);
	textures.push_back(backgrounds_War1_Pale_houses1);
	textures.push_back(backgrounds_War1_Pale_fence);
	textures.push_back(backgrounds_War1_Pale_road);

	// Clear screen
	std::unique_ptr<Scenario> scenary(new War1(960,720,textures,&renderer));
	dev.Pause(false);
	int frame_rate = 1000/60;
	soldier1.get()->change_action(6,frame);
	soldier2.get()->change_action(9,frame);
	int speed1 = 8;
	int speed2 = 4;
	// Render our image, stretching it to the whole window
	auto start = std::chrono::high_resolution_clock::now();
	for(int j = 0;j<400;j++){
		auto start = std::chrono::high_resolution_clock::now();
		//time = tiempo_actual(ms)
		if(j ==  100){
			speed1 = 0;
			soldier1.get()->change_action(4,frame);
		}
		if(j == 200){
			speed1 = 4;
			soldier1.get()->change_action(9,frame);
		}
		if(j == 300){
			speed1 = -2;
			speed2 = -2;
		}
		pos1 = pos1+speed1;
		pos2 = pos2+speed2;
		soldier1.get()->set_position(pos1,50);
		soldier2.get()->set_position(pos2,60);
		Center center;
		soldier1.get()->add_to_center(center);
		soldier2.get()->add_to_center(center);
		renderer.Clear();
		
		scenary.get()->copy(center.center_value(),&renderer);
		/*
		int val = 128*(j%8);
		renderer.Copy(sprites9,Rect(val,64,128,64),Rect(pos1 -i+344,680,96,48));
		int k =720-72;
		renderer.Copy(sprites10,Rect(val,64,128,64),Rect(pos2 -i+344,k,128,64));
		*/
		soldier1.get()->copy(center.center_value(),&renderer,frame);
		soldier2.get()->copy(center.center_value(),&renderer,frame);
		frame = frame + 1;
		// Show rendered frame
		renderer.Present();
		auto end = std::chrono::high_resolution_clock::now();
		int time = static_cast<int>(std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count());
		std::cout << "tardó en procesar todo " << time << " milisegundos" << std::endl;
		frame = frame + 1 + (time/frame_rate);
		int delay = frame_rate - (time % frame_rate);
		std::cout << "iteracion " << j << " avanza " << 1 + (time/frame_rate) << " frames" << std::endl;
		// Sound plays after this call
		SDL_Delay(delay);
	}
	// Play for 5 seconds, after which everything is stopped and closed
	//SDL_Delay(10000);
	
	return 0;
} catch (std::exception& e) {
	std::cerr << "Error: " << e.what() << std::endl;
	return 1;
}
