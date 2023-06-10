#include <iostream>
#include <sys/socket.h>
#include "common_socket.h"
#include "server_thread.h"
#include "server_codes.h"
#include "server_listening.h"
#include "server_server.h"
#include "unistd.h"

Server::Server(char* service): socket(service){}

void Server::run(){
    //std::cout << "corriendo thread" << std::endl;
    Listening* listening = new Listening(&socket);

    listening->start();
    
    char quit;
    //std::cout <<"estoy esperando a que me cierren" << std::endl;
    std::cin >> quit;
    while (quit != 'q'){
        //std::cout <<"letra incorrecta" << std::endl;
        std::cin >> quit;
    }
    socket.shutdown(2);
    socket.close();
    listening->join();
    delete listening;
}
