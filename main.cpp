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
	int pos1 = 0;
	int pos2 = 50;
	int speed1 = 2;
	int speed2 = 4;
	myenum::Type_of_action action1 = myenum::walk;
	myenum::Type_of_action action2 = myenum::run;
	Message message(1,action1,pos1,75,soldier1,alta);
	queue.push(message);
	message = Message(2,action2,pos2,125,soldier2,alta);
	queue.push(message);
	for(int i = 0;i<400;i++){
		if(i == 100){
			speed2 = 0;
			action2 = myenum::idle;
		}
		if(i == 200){
			speed2 = 2;
			action2 = myenum::walk;
		}
		if(i == 300){
			speed1 = -2;
			speed2 = -2;
		}
		pos1 = pos1 + speed1;
		pos2 = pos2 + speed2;
		Message message(1,action1,pos1,75,soldier1,modificacion);
		queue.push(message);
		message = Message(2,action2,pos2,125,soldier2,modificacion);
		queue.push(message);
		SDL_Delay(40);
	}
	queue.close();
	my_renderer->join();
	delete my_renderer;
	return 0;
}