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
#include "../../common_libs/include/common_myenum.h"
#include "../../common_libs/include/common_thread.h"
#include "../../common_libs/include/common_queue.h"
#include <memory>
#include "../../common_libs/include/common_message.h"
#include "../../common_libs/include/common_protocolo.h"
#include "../include/client_server_reciever.h"
#include "../include/client_sdl_handler_event.h"
#include "../include/cliente_server_sender.h"

std::vector<std::string> getCommand(std::string basicString);

int main(int argc, char *argv[]){
    if (argc != 3) {
        std::cerr << "Argumentos invalidos: " << argv[0] << ". <ip/hostname server> <puerto/servicename>"
                  << std::endl;
        return 1;
    }
    Protocolo protocolo(argv[1], argv[2]);
    std::string command;
    std::vector<std::string> commands;
    while (true) {
        std::getline(std::cin, command); //escribir por consola crear <nombre_partida> <modo> / join <codigo_partida>
        commands = getCommand(command);
        if (commands.size() < 2 || commands.size() > 3) {
            std::cerr << "Error: comando invalido" << std::endl;
            return 1;
        }
        protocolo.enviar_inicio_partida(commands);
        std::string inicio = commands[0];
        std::getline(std::cin, command); // escribir por consola el soldado inicial (soldier1, soldier2, soldier3)
        protocolo.enviar_info(command, inicio);
        uint32_t gaming = protocolo.recibir_codigo_partida();
        if (gaming != CODIGO_INVALIDO) {
            break;
        }
        std::cerr << "Error: codigo de partida invalido" << std::endl;
    }

    Queue<Message> estadoDelJuego(2000);
    ServerReciever serverReciever(std::ref(protocolo), std::ref(estadoDelJuego));
    SDLHandlerEvent sdlHandlerEvent;
    ServerSender serverSender(std::ref(protocolo), std::ref(sdlHandlerEvent.get_eventos_usuario()));

    serverReciever.start();
    sdlHandlerEvent.start();
    serverSender.start();

	Thread* my_renderer;
	my_renderer = new MyRenderer(960,720,war1_pale,1,&estadoDelJuego);
	my_renderer->start();
	/*myenum::Type_of_action action1 = myenum::walk;
	Type_of_character type = soldier3;
	Message message(3,myenum::idle,300,75,soldier1,alta,50,200);
	queue.push(message);
	Message message1(1,myenum::idle,400,75,explotion,alta,50,200);
	queue.push(message1);
	Message message2(2,myenum::idle,200,100,smoke,alta,50,200);
	queue.push(message2);
	for(int i = 0;i<400;i++){
		if(i == 100){
			Message message1(1,myenum::explotion,400,75,explotion,modificacion,50,200);
			queue.push(message1);
			Message message2(2,myenum::smoke,200,100,smoke,modificacion,50,200);
			queue.push(message2);
		}
		if(i == 200){
			Message message1(1,myenum::explotion,400,75,explotion,baja,50,200);
			queue.push(message1);
			Message message2(2,myenum::smoke,200,100,smoke,baja,50,200);
			queue.push(message2);
		}
		SDL_Delay(20);
	}
	queue.close();*/
	my_renderer->join();
	delete my_renderer;
	return 0;
}

std::vector<std::string> getCommand(std::string command) {
    std::vector<std::string> commands;
    std::string commandName;
    std::string::size_type pos = command.find(' ');
    if (pos == std::string::npos) {
        commandName = command;
        commands.push_back(commandName);
    } else {
        commandName = command.substr(0, pos);
        commands.push_back(commandName);
        commands.push_back(command.substr(pos + 1));
    }
    return commands;
}