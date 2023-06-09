#include <iostream>

#include <SDL.h>

#include <SDL2pp/SDL.hh>
#include <SDL2pp/AudioDevice.hh>
#include <SDL2pp/AudioSpec.hh>
#include <SDL2pp/Wav.hh>
#include <SDL2pp/SDL2pp.hh>
#include "client_scenario.h"
#include "client_war1.h"
#include "client_war2.h"
#include "client_war3.h"
#include "client_war4.h"
#include "client_character.h"
#include "client_soldier1.h"
#include "client_soldier2.h"
#include "client_center.h"
#include "client_renderer.h"
#include "client_textureholder.h"
#include "client_constants.h"
#include <memory>
#include <fstream>

using namespace SDL2pp;
using namespace paths;

MyRenderer::MyRenderer(int width, int height,int map,int ID/*,Queue<Message>* queue*/){
    this->width = width;
    this->height = height;
    this->my_map = map;
    this->my_id = ID;
    //this->my_queue = queue;
}

void MyRenderer::run(){
    try {
	SDL sdl(SDL_INIT_AUDIO | SDL_INIT_VIDEO);
	std::fstream report;
	report.open("report.csv",std::ofstream::out);
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
			width, height,
			SDL_WINDOW_RESIZABLE);

	// Create accelerated video renderer with default driver
	Renderer renderer(window, -1, SDL_RENDERER_ACCELERATED);
	/*
	Texture sprites9(renderer,"../resources/Soldier_1/Run.png");
	Texture sprites10(renderer,"../resources/Soldier_2/Run.png");
	*/
	uint32_t frame = 0;
	int pos1 = 400;
	int pos2 = 450;
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
	std::vector<std::string> soldier_type_2 = {
		Soldier_2_Attack,
		Soldier_2_Dead,
		Soldier_2_Grenade,
		Soldier_2_Hurt,
		Soldier_2_Idle,
		Soldier_2_Recharge,
		Soldier_2_Run,
		Soldier_2_Shot_1,
		Soldier_2_Shot_2,
		Soldier_2_Walk
	};
	std::vector<std::string> soldier_type_3 = {
		Soldier_3_Attack,
		Soldier_3_Dead,
		Soldier_3_Grenade,
		Soldier_3_Hurt,
		Soldier_3_Idle,
		Soldier_3_Recharge,
		Soldier_3_Run,
		Soldier_3_Shot_1,
		Soldier_3_Shot_2,
		Soldier_3_Walk
	};
	std::vector<std::string> enemy_jumper = {
		Jumper_Attack_1,
		Jumper_Attack_2,
		Jumper_Attack_3,
		Jumper_Dead,
		Jumper_Eating,
		Jumper_Hurt,
		Jumper_Idle,
		Jumper_Jump,
		Jumper_Run,
		Jumper_Walk
	};
	std::vector<std::string> enemy_spear = {
		Spear_Attack_1,
		Spear_Attack_2,
		Spear_Dead,
		Spear_Fall,
		Spear_Hurt,
		Spear_Idle,
		Spear_Protect,
		Spear_Run,
		Spear_Run_attack,
		Spear_Walk
	};
	std::vector<std::string> enemy_venom = {
		Venom_Attack1,
		Venom_Attack2,
		Venom_Dead,
		Venom_Hurt,
		Venom_Idle,
		Venom_Jump,
		Venom_Run,
		Venom_Walk
	};
	std::vector<std::string> enemy_witch = {
		Witch_Attack_1,
		Witch_Attack_2,
		Witch_Attack_3,
		Witch_Dead,
		Witch_Hurt,
		Witch_Idle,
		Witch_Jump,
		Witch_Run,
		Witch_Scream,
		Witch_Walk
	};
	std::vector<std::string> enemy_zombie = {
		Zombie_Attack_1,
		Zombie_Attack_2,
		Zombie_Attack_3,
		Zombie_Bite,
		Zombie_Dead,
		Zombie_Hurt,
		Zombie_Idle,
		Zombie_Jump,
		Zombie_Run,
		Zombie_Walk
	};
	Texture_holder soldier1_textures(&renderer,soldier_type_1);
	Texture_holder soldier2_textures(&renderer,soldier_type_2);
	Texture_holder soldier3_textures(&renderer,soldier_type_3);
	Texture_holder spear_textures(&renderer,enemy_spear);
	Texture_holder jumper_textures(&renderer,enemy_jumper);
	Texture_holder venom_textures(&renderer,enemy_venom);
	Texture_holder witchm_textures(&renderer,enemy_witch);
	Texture_holder zombie_textures(&renderer,enemy_zombie);
	std::vector<Texture*> textures_s1 = soldier1_textures.all_textures();
	std::vector<Texture*> textures_s2 = soldier2_textures.all_textures();
	std::unique_ptr<Character> soldier1(new Soldier1(pos1,50,960,720,textures_s1,frame));
	std::unique_ptr<Character> soldier2(new Soldier2(pos2,60,960,720,textures_s2,frame));
	std::vector<std::string> textures;
	get_map_paths(textures);

	// Clear screen
    
	Scenario* scenario;
    switch(my_map){
        case(2):
        case(3):
            scenario =new War2(width,height,textures,&renderer);
            break;
        case(4):
        case(5):
            scenario =new War3(width,height,textures,&renderer);
            break;
        case(6):
        case(7):
            scenario =new War4(width,height,textures,&renderer);
            break;
        default:
            scenario =new War1(width,height,textures,&renderer);
            break;
    }
	std::unique_ptr<Scenario> my_scenario(scenario);
	dev.Pause(false);
	int frame_rate = 1000/60;
	soldier1.get()->change_action(6,frame);
	soldier2.get()->change_action(9,frame);
	int speed1 = 8;
	int speed2 = 4;
	// Render our image, stretching it to the whole window
	for(int j = 0;j<200;j++){
		auto start = std::chrono::high_resolution_clock::now();
		//time = tiempo_actual(ms)
		if(j ==  50){
			speed1 = 0;
			soldier1.get()->change_action(4,frame);
		}
		if(j == 100){
			speed1 = 4;
			soldier1.get()->change_action(9,frame);
		}
		if(j == 150){
			speed1 = -2;
			speed2 = -2;
		}
		pos1 = pos1+speed1;
		pos2 = pos2+speed2;
		soldier1.get()->set_position(pos1,0);
		soldier2.get()->set_position(pos2,0);
		Center center;
		soldier1.get()->add_to_center(center);
		soldier2.get()->add_to_center(center);
		renderer.Clear();
		
		my_scenario.get()->copy(center.center_value(),&renderer);
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
		frame = frame + 1 + (time/frame_rate);
		int delay = frame_rate - (time % frame_rate);
		// Sound plays after this call
		report << (time/frame_rate) << "," << (time + delay) << std::endl;
		SDL_Delay(delay);
	}
	// Play for 5 seconds, after which everything is stopped and closed
	//SDL_Delay(10000);
} catch (std::exception& e) {
	std::cerr << "Error: " << e.what() << std::endl;
}
}
void MyRenderer::get_map_paths(std::vector<std::string>& textures){
    switch(my_map){
        case(1):
	        textures.push_back(backgrounds_War1_Pale_sky);
	        textures.push_back(backgrounds_War1_Pale_sun);
	        textures.push_back(backgrounds_War1_Pale_ruins);
	        textures.push_back(backgrounds_War1_Pale_house3);
	        textures.push_back(backgrounds_War1_Pale_houses2);
	        textures.push_back(backgrounds_War1_Pale_houses1);
	        textures.push_back(backgrounds_War1_Pale_fence);
	        textures.push_back(backgrounds_War1_Pale_road);
            break;
        case(2):
	        textures.push_back(backgrounds_War2_Bright_sky);
	        textures.push_back(backgrounds_War2_Bright_houses4);
	        textures.push_back(backgrounds_War2_Bright_houses3);
	        textures.push_back(backgrounds_War2_Bright_houses2);
	        textures.push_back(backgrounds_War2_Bright_houses1);
	        textures.push_back(backgrounds_War2_Bright_wall);
	        textures.push_back(backgrounds_War2_Bright_road);
            break;
        case(3):
	        textures.push_back(backgrounds_War2_Pale_sky);
	        textures.push_back(backgrounds_War2_Pale_houses4);
	        textures.push_back(backgrounds_War2_Pale_houses3);
	        textures.push_back(backgrounds_War2_Pale_houses2);
	        textures.push_back(backgrounds_War2_Pale_houses1);
	        textures.push_back(backgrounds_War2_Pale_wall);
	        textures.push_back(backgrounds_War2_Pale_road);
            break;
        case(4):
	        textures.push_back(backgrounds_War3_Bright_sky_sun);
	        textures.push_back(backgrounds_War3_Bright_houses3);
	        textures.push_back(backgrounds_War3_Bright_houses2);
	        textures.push_back(backgrounds_War3_Bright_trees);
	        textures.push_back(backgrounds_War3_Bright_house_fountain);
	        textures.push_back(backgrounds_War3_Bright_fence);
	        textures.push_back(backgrounds_War3_Bright_road);
            break;
        case(5):
	        textures.push_back(backgrounds_War3_Pale_sky_sun);
	        textures.push_back(backgrounds_War3_Pale_houses3);
	        textures.push_back(backgrounds_War3_Pale_houses2);
	        textures.push_back(backgrounds_War3_Pale_trees);
	        textures.push_back(backgrounds_War3_Pale_house_fountain);
	        textures.push_back(backgrounds_War3_Pale_fence);
	        textures.push_back(backgrounds_War3_Pale_road);
            break;
        case(6):
	        textures.push_back(backgrounds_War4_Bright_sky);
	        textures.push_back(backgrounds_War4_Bright_moon);
	        textures.push_back(backgrounds_War4_Bright_houses4);
	        textures.push_back(backgrounds_War4_Bright_houses3);
	        textures.push_back(backgrounds_War4_Bright_houses2);
	        textures.push_back(backgrounds_War4_Bright_houses1);
	        textures.push_back(backgrounds_War4_Bright_wall);
	        textures.push_back(backgrounds_War4_Bright_road);
            break;
        case(7):
	        textures.push_back(backgrounds_War4_Pale_sky);
	        textures.push_back(backgrounds_War4_Pale_moon);
	        textures.push_back(backgrounds_War4_Pale_houses4);
	        textures.push_back(backgrounds_War4_Pale_houses3);
	        textures.push_back(backgrounds_War4_Pale_houses2);
	        textures.push_back(backgrounds_War4_Pale_houses1);
	        textures.push_back(backgrounds_War4_Pale_wall);
	        textures.push_back(backgrounds_War4_Pale_road);
            break;
        default:
	        textures.push_back(backgrounds_War1_Bright_sky);
	        textures.push_back(backgrounds_War1_Bright_sun);
	        textures.push_back(backgrounds_War1_Bright_ruins);
	        textures.push_back(backgrounds_War1_Bright_house3);
	        textures.push_back(backgrounds_War1_Bright_houses2);
	        textures.push_back(backgrounds_War1_Bright_houses1);
	        textures.push_back(backgrounds_War1_Bright_fence);
	        textures.push_back(backgrounds_War1_Bright_road);
            break;
    }

}