#include <iostream>
#include <stdexcept>
#include <algorithm>

#include <SDL.h>

#include <SDL2pp/SDL.hh>
#include <SDL2pp/AudioDevice.hh>
#include <SDL2pp/AudioSpec.hh>
#include <SDL2pp/Wav.hh>
#include <SDL2pp/SDL2pp.hh>
#include "client_myrenderer.h"
#include <chrono>
#include "client_myenum.h"
#include "common_thread.h"
#include "common_queue.h"
#include <memory>
#include "client_message.h"


int main(int, char*[]){
	Thread* my_renderer;
	Queue<Message> queue(2000);
	my_renderer = new MyRenderer(960,720,1,1,&queue);
	my_renderer->start();
	myenum::Type_of_action action1 = myenum::walk;
	Type_of_character type = soldier3;
	Message message(1,myenum::idle,400,75,type,alta);
	queue.push(message);
	Message message2(2,myenum::idle,200,100,soldier1,alta);
	queue.push(message2);
	for(int i = 0;i<2000;i++){
		if(i == 100){
			Message message(1,myenum::attack,400,75,type,modificacion);
			queue.push(message);
		}
		if(i == 200){
			Message message(1,myenum::attack_1,400,75,type,modificacion);
			queue.push(message);
		}
		if(i == 300){
			Message message(1,myenum::attack_2,400,75,type,modificacion);
			queue.push(message);
		}
		if(i == 400){
			Message message(1,myenum::attack_3,400,75,type,modificacion);
			queue.push(message);
		}
		if(i == 500){
			Message message(1,myenum::bite,400,75,type,modificacion);
			queue.push(message);
		}
		if(i == 600){
			Message message(1,myenum::dead,400,75,type,modificacion);
			queue.push(message);
		}
		if(i == 700){
			Message message(1,myenum::eating,400,75,type,modificacion);
			queue.push(message);
		}
		if(i == 800){
			Message message(1,myenum::fall,400,75,type,modificacion);
			queue.push(message);
		}
		if(i == 900){
			Message message(1,myenum::grenade,400,75,type,modificacion);
			queue.push(message);
		}
		
		if(i == 1200){
			Message message(1,myenum::protect,400,75,type,modificacion);
			queue.push(message);
		}
		if(i == 1300){
			Message message(1,myenum::recharge,400,75,type,modificacion);
			queue.push(message);
		}
		if(i == 1400){
			Message message(1,myenum::run,400,75,type,modificacion);
			queue.push(message);
		}
		if(i == 1500){
			Message message(1,myenum::run_attack,400,75,type,modificacion);
			queue.push(message);
		}
		if(i == 1600){
			Message message(1,myenum::scream,400,75,type,modificacion);
			queue.push(message);
		}
		if(i == 1700){
			Message message(1,myenum::shot_1,400,75,type,modificacion);
			queue.push(message);
		}
		if(i == 1800){
			Message message(1,myenum::shot_2,400,75,type,modificacion);
			queue.push(message);
		}
		if(i == 1900){
			Message message(1,myenum::walk,400,75,type,modificacion);
			queue.push(message);
		}
		SDL_Delay(20);
	}
	queue.close();
	my_renderer->join();
	delete my_renderer;
	return 0;
}