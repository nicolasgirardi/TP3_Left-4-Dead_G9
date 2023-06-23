#include <iostream>

#include <SDL.h>

#include <SDL2pp/SDL.hh>
#include <SDL2pp/AudioDevice.hh>
#include <SDL2pp/AudioSpec.hh>
#include <SDL2pp/Wav.hh>
#include <SDL2pp/SDL2pp.hh>
#include "../include/client_scenario.h"
#include "../include/client_war1.h"
#include "../include/client_war2.h"
#include "../include/client_war3.h"
#include "../include/client_war4.h"
#include "../include/client_character.h"
#include "../include/client_soldier1.h"
#include "../include/client_soldier2.h"
#include "../include/client_soldier3.h"
#include "../include/client_jumper.h"
#include "../include/client_spear.h"
#include "../include/client_venom.h"
#include "../include/client_witch.h"
#include "../include/client_zombie.h"
#include "../include/client_explotion.h"
#include "../include/client_smoke.h"
#include "../include/client_center.h"
#include "../include/client_myrenderer.h"
#include "../include/client_textureholder.h"
#include "../include/client_constants.h"
#include <memory>
#include <fstream>
#include "../../common_libs/include/common_queue.h"
#include "../include/client_message.h"
#include "../include/client_myenum.h"

using namespace SDL2pp;
using namespace paths;

MyRenderer::MyRenderer(int width, int height,Type_of_map map,int ID,Queue<Message>* queue){
    this->width = width;
    this->height = height;
    this->my_map = map;
    this->my_id = ID;
    this->my_queue = queue;
	frame = 0;
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
	texture_paths();

	Texture_holder jumper_textures(&renderer,enemy_jumper);
	all_textures.push_back(&jumper_textures);
	Texture_holder soldier1_textures(&renderer,soldier_type_1);
	all_textures.push_back(&soldier1_textures);
	Texture_holder soldier2_textures(&renderer,soldier_type_2);
	all_textures.push_back(&soldier2_textures);
	Texture_holder soldier3_textures(&renderer,soldier_type_3);
	all_textures.push_back(&soldier3_textures);
	Texture_holder spear_textures(&renderer,enemy_spear);
	all_textures.push_back(&spear_textures);	
	Texture_holder venom_textures(&renderer,enemy_venom);
	all_textures.push_back(&venom_textures);
	Texture_holder witchm_textures(&renderer,enemy_witch);
	all_textures.push_back(&witchm_textures);
	Texture_holder zombie_textures(&renderer,enemy_zombie);
	all_textures.push_back(&zombie_textures);
	Texture_holder explotion_textures(&renderer,explotion_effect);
	all_textures.push_back(&explotion_textures);
	Texture_holder smoke_textures(&renderer,smoke_effect);
	all_textures.push_back(&smoke_textures);

	std::vector<std::string> textures;
	get_map_paths(textures);

	// Clear screen
    
	Scenario* scenario;
    switch(my_map){
        case(war2_bright):
        case(war2_pale):
            scenario =new War2(width,height,textures,&renderer);
            break;
        case(war3_bright):
        case(war3_pale):
            scenario =new War3(width,height,textures,&renderer);
            break;
        case(war4_bright):
        case(war4_pale):
            scenario =new War4(width,height,textures,&renderer);
            break;
        default:
            scenario =new War1(width,height,textures,&renderer);
            break;
    }
	std::unique_ptr<Scenario> my_scenario(scenario);
	dev.Pause(false);
	int frame_rate = 1000/30;
	Message message = my_queue->pop();
	update_characters(message);
	bool playing = true;
	while(playing){
		auto start = std::chrono::high_resolution_clock::now();
		try{
			while(my_queue->try_pop(message))
				update_characters(message);
			Center center;
			calculate_center(center);
			int num_center = center.center_value();
			renderer.Clear();
			my_scenario.get()->copy(num_center,&renderer);
			copy_characters(num_center,&renderer);
			renderer.Present();
			auto end = std::chrono::high_resolution_clock::now();
			int time = static_cast<int>(std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count());
			frame = frame + 1 + (time/frame_rate);
			int delay = frame_rate - (time % frame_rate);
			SDL_Delay(delay);
		}
		catch(std::runtime_error& e){
			playing = false;
		}
	}
} catch (std::exception& e) {
	std::cerr << "Error: " << e.what() << std::endl;
}
}
void MyRenderer::get_map_paths(std::vector<std::string>& textures){
    switch(my_map){
        case(war1_pale):
	        textures.push_back(backgrounds_War1_Pale_sky);
	        textures.push_back(backgrounds_War1_Pale_sun);
	        textures.push_back(backgrounds_War1_Pale_ruins);
	        textures.push_back(backgrounds_War1_Pale_house3);
	        textures.push_back(backgrounds_War1_Pale_houses2);
	        textures.push_back(backgrounds_War1_Pale_houses1);
	        textures.push_back(backgrounds_War1_Pale_fence);
	        textures.push_back(backgrounds_War1_Pale_road);
            break;
        case(war2_bright):
	        textures.push_back(backgrounds_War2_Bright_sky);
	        textures.push_back(backgrounds_War2_Bright_houses4);
	        textures.push_back(backgrounds_War2_Bright_houses3);
	        textures.push_back(backgrounds_War2_Bright_houses2);
	        textures.push_back(backgrounds_War2_Bright_houses1);
	        textures.push_back(backgrounds_War2_Bright_wall);
	        textures.push_back(backgrounds_War2_Bright_road);
            break;
        case(war2_pale):
	        textures.push_back(backgrounds_War2_Pale_sky);
	        textures.push_back(backgrounds_War2_Pale_houses4);
	        textures.push_back(backgrounds_War2_Pale_houses3);
	        textures.push_back(backgrounds_War2_Pale_houses2);
	        textures.push_back(backgrounds_War2_Pale_houses1);
	        textures.push_back(backgrounds_War2_Pale_wall);
	        textures.push_back(backgrounds_War2_Pale_road);
            break;
        case(war3_bright):
	        textures.push_back(backgrounds_War3_Bright_sky_sun);
	        textures.push_back(backgrounds_War3_Bright_houses3);
	        textures.push_back(backgrounds_War3_Bright_houses2);
	        textures.push_back(backgrounds_War3_Bright_trees);
	        textures.push_back(backgrounds_War3_Bright_house_fountain);
	        textures.push_back(backgrounds_War3_Bright_fence);
	        textures.push_back(backgrounds_War3_Bright_road);
            break;
        case(war3_pale):
	        textures.push_back(backgrounds_War3_Pale_sky_sun);
	        textures.push_back(backgrounds_War3_Pale_houses3);
	        textures.push_back(backgrounds_War3_Pale_houses2);
	        textures.push_back(backgrounds_War3_Pale_trees);
	        textures.push_back(backgrounds_War3_Pale_house_fountain);
	        textures.push_back(backgrounds_War3_Pale_fence);
	        textures.push_back(backgrounds_War3_Pale_road);
            break;
        case(war4_bright):
	        textures.push_back(backgrounds_War4_Bright_sky);
	        textures.push_back(backgrounds_War4_Bright_moon);
	        textures.push_back(backgrounds_War4_Bright_houses4);
	        textures.push_back(backgrounds_War4_Bright_houses3);
	        textures.push_back(backgrounds_War4_Bright_houses2);
	        textures.push_back(backgrounds_War4_Bright_houses1);
	        textures.push_back(backgrounds_War4_Bright_wall);
	        textures.push_back(backgrounds_War4_Bright_road);
            break;
        case(war4_pale):
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
void MyRenderer::update_characters(Message& message){
	Type_of_AMB abm = message.get_amb();
	switch(abm){
		case(alta):
			add_character(message);
			break;
		case(baja):
			remove_character(message);
			break;
		case(modificacion):
			modify_character(message);
			break;
	}
}
void MyRenderer::add_character(Message& message){
	Character* new_character;
	std::vector<Texture*> textures;
	Type_of_character type = message.get_type();
	switch(type){
		case(jumper):
			textures = all_textures[0]->all_textures();
			new_character = new Jumper(message.get_x(),message.get_y(),width,height,textures,frame,message.get_id());
			break;
		case(soldier1):
			textures = all_textures[1]->all_textures();
			new_character = new Soldier1(message.get_x(),message.get_y(),width,height,textures,frame,message.get_id(),message.get_ammo(),message.get_hp());
			break;
		case(soldier2):
			textures = all_textures[2]->all_textures();
			new_character = new Soldier2(message.get_x(),message.get_y(),width,height,textures,frame,message.get_id(),message.get_ammo(),message.get_hp());
			break;
		case(soldier3):
			textures = all_textures[3]->all_textures();
			new_character = new Soldier3(message.get_x(),message.get_y(),width,height,textures,frame,message.get_id(),message.get_ammo(),message.get_hp());
			break;
		case(spear):
			textures = all_textures[4]->all_textures();
			new_character = new Spear(message.get_x(),message.get_y(),width,height,textures,frame,message.get_id());
			break;
		case(venom):
			textures = all_textures[5]->all_textures();
			new_character = new Venom(message.get_x(),message.get_y(),width,height,textures,frame,message.get_id());
			break;
		case(witch):
			textures = all_textures[6]->all_textures();
			new_character = new Witch(message.get_x(),message.get_y(),width,height,textures,frame,message.get_id());
			break;
		case(zombie):
			textures = all_textures[7]->all_textures();
			new_character = new Zombie(message.get_x(),message.get_y(),width,height,textures,frame,message.get_id());
			break;
		case(explotion):
			textures = all_textures[8]->all_textures();
			new_character = new Explotion(message.get_x(),message.get_y(),width,height,textures,frame,message.get_id());
			break;
		case(smoke):
			textures = all_textures[9]->all_textures();
			new_character = new Smoke(message.get_x(),message.get_y(),width,height,textures,frame,message.get_id());
			break;
	}
	if(new_character != nullptr)
		all_characters.push_back(new_character);
}
void MyRenderer::modify_character(Message& message){
	bool found = false;
	int i = 0;
	int id = message.get_id();
	while(!found && i< all_characters.size()){
		if(all_characters[i]->is(id)){
			int x = message.get_x();
			int y = message.get_y();
			myenum::Type_of_action action = message.get_action();
			all_characters[i]->set_position(x,y);
			all_characters[i]->change_action(action,frame);
			found = true;
		}
		else
			i++;
	}
}
void MyRenderer::remove_character(Message& message){
	bool found = false;
	int i = 0;
	int id = message.get_id();
	while(!found && i< all_characters.size()){
		if(all_characters[i]->is(id)){
			delete all_characters[i];
			all_characters.erase(all_characters.begin()+i);
			found = true;
	}
		else
			i++;
	}
}
void MyRenderer::calculate_center(Center& center){
	for(int i = 0;i<all_characters.size();i++){
		all_characters[i]->add_to_center(center);
	}
}
void MyRenderer::copy_characters(int& center,Renderer* renderer){
	for(int i = 0;i<all_characters.size();i++){
		all_characters[i]->copy(center,renderer,frame);
	}
}
void MyRenderer::texture_paths(){
	soldier_type_1.push_back(Soldier_1_Attack);
	soldier_type_1.push_back(Soldier_1_Dead);
	soldier_type_1.push_back(Soldier_1_Grenade);
	soldier_type_1.push_back(Soldier_1_Hurt);
	soldier_type_1.push_back(Soldier_1_Idle);
	soldier_type_1.push_back(Soldier_1_Recharge);
	soldier_type_1.push_back(Soldier_1_Run);
	soldier_type_1.push_back(Soldier_1_Shot_1);
	soldier_type_1.push_back(Soldier_1_Shot_2);
	soldier_type_1.push_back(Soldier_1_Walk);
	
	soldier_type_2.push_back(Soldier_2_Attack);
	soldier_type_2.push_back(Soldier_2_Dead);
	soldier_type_2.push_back(Soldier_2_Grenade);
	soldier_type_2.push_back(Soldier_2_Hurt);
	soldier_type_2.push_back(Soldier_2_Idle);
	soldier_type_2.push_back(Soldier_2_Recharge);
	soldier_type_2.push_back(Soldier_2_Run);
	soldier_type_2.push_back(Soldier_2_Shot_1);
	soldier_type_2.push_back(Soldier_2_Shot_2);
	soldier_type_2.push_back(Soldier_2_Walk);
	
	soldier_type_3.push_back(Soldier_3_Attack);
	soldier_type_3.push_back(Soldier_3_Dead);
	soldier_type_3.push_back(Soldier_3_Grenade);
	soldier_type_3.push_back(Soldier_3_Hurt);
	soldier_type_3.push_back(Soldier_3_Idle);
	soldier_type_3.push_back(Soldier_3_Recharge);
	soldier_type_3.push_back(Soldier_3_Run);
	soldier_type_3.push_back(Soldier_3_Shot_1);
	soldier_type_3.push_back(Soldier_3_Shot_2);
	soldier_type_3.push_back(Soldier_3_Walk);
	
	enemy_jumper.push_back(Jumper_Attack_1);
	enemy_jumper.push_back(Jumper_Attack_2);
	enemy_jumper.push_back(Jumper_Attack_3);
	enemy_jumper.push_back(Jumper_Dead);
	enemy_jumper.push_back(Jumper_Eating);
	enemy_jumper.push_back(Jumper_Hurt);
	enemy_jumper.push_back(Jumper_Idle);
	enemy_jumper.push_back(Jumper_Jump);
	enemy_jumper.push_back(Jumper_Run);
	enemy_jumper.push_back(Jumper_Walk);
	
	enemy_spear.push_back(Spear_Attack_1);
	enemy_spear.push_back(Spear_Attack_2);
	enemy_spear.push_back(Spear_Dead);
	enemy_spear.push_back(Spear_Fall);
	enemy_spear.push_back(Spear_Hurt);
	enemy_spear.push_back(Spear_Idle);
	enemy_spear.push_back(Spear_Protect);
	enemy_spear.push_back(Spear_Run);
	enemy_spear.push_back(Spear_Run_attack);
	enemy_spear.push_back(Spear_Walk);
	
	enemy_venom.push_back(Venom_Attack1);
	enemy_venom.push_back(Venom_Attack2);
	enemy_venom.push_back(Venom_Dead);
	enemy_venom.push_back(Venom_Hurt);
	enemy_venom.push_back(Venom_Idle);
	enemy_venom.push_back(Venom_Jump);
	enemy_venom.push_back(Venom_Run);
	enemy_venom.push_back(Venom_Walk);
	
	enemy_witch.push_back(Witch_Attack_1);
	enemy_witch.push_back(Witch_Attack_2);
	enemy_witch.push_back(Witch_Attack_3);
	enemy_witch.push_back(Witch_Dead);
	enemy_witch.push_back(Witch_Hurt);
	enemy_witch.push_back(Witch_Idle);
	enemy_witch.push_back(Witch_Jump);
	enemy_witch.push_back(Witch_Run);
	enemy_witch.push_back(Witch_Scream);
	enemy_witch.push_back(Witch_Walk);
	
	enemy_zombie.push_back(Zombie_Attack_1);
	enemy_zombie.push_back(Zombie_Attack_2);
	enemy_zombie.push_back(Zombie_Attack_3);
	enemy_zombie.push_back(Zombie_Bite);
	enemy_zombie.push_back(Zombie_Dead);
	enemy_zombie.push_back(Zombie_Hurt);
	enemy_zombie.push_back(Zombie_Idle);
	enemy_zombie.push_back(Zombie_Jump);
	enemy_zombie.push_back(Zombie_Run);
	enemy_zombie.push_back(Zombie_Walk);

	explotion_effect.push_back(Soldier_1_Explosion);

	smoke_effect.push_back(Soldier_3_Smoke);
}
MyRenderer::~MyRenderer(){
	for(int i = 0;i<all_characters.size();i++){
		delete all_characters[i];
	}
}
