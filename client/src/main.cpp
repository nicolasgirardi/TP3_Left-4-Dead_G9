#include <iostream>
#include <stdexcept>
#include <algorithm>

#include <SDL.h>

#include <SDL2pp/SDL.hh>
#include <SDL2pp/AudioDevice.hh>
#include <SDL2pp/AudioSpec.hh>
#include <SDL2pp/Wav.hh>
#include <SDL2pp/SDL2pp.hh>
#include "../include/client_myrenderer.h"
#include <chrono>
#include "../include/client_myenum.h"
#include "../../common_libs/include/common_thread.h"
#include "../../common_libs/include/common_queue.h"
#include <memory>
#include "../../common_libs/include/common_message.h"


int main(int, char*[]){
	Thread* my_renderer;
	Queue<Message> queue(2000);
	my_renderer = new MyRenderer(960,720,war1_pale,1,&queue);
	my_renderer->start();
	myenum::Type_of_action action1 = myenum::walk;
	Type_of_character type = soldier3;
	Message message(3,myenum::idle,400,0,soldier3,alta,50,200);
	queue.push(message);
	Message message1(1,myenum::idle,400,100,soldier3,alta,50,200);
	queue.push(message1);
	//Message message2(2,myenum::idle,200,100,smoke,alta,50,200);
	//queue.push(message2);
	for(int i = 0;i<400;i++){
		Message message2(3,myenum::idle,400,i/2,soldier3,modificacion,50,200);
		queue.push(message2);
		SDL_Delay(20);
	}
	queue.close();
	my_renderer->join();
	delete my_renderer;
	return 0;
}