#include <iostream>
#include "server_thread.h"
#include "server_codes.h"
#include "common_socket.h"
#include "server_game.h"
#include "server_listening.h"
#include "server_queue.h"
#include "common_liberror.h"
#include "server_client.h"


Listening::Listening(Socket* skt){
    socket = skt;
}

void Listening::run(){
    try {
        while (true){
            Socket temp = socket->accept();
            Client* new_client = new Client(temp,&games);
            clients.push_back(new_client);
            new_client->start();
        }
    }
    catch (std::exception &e){}
    for (int i = 0; i <(int)clients.size(); i++){
        clients[i]->join();
    }
    games.end();
}
Listening::~Listening(){
    for (int i = 0; i <(int)clients.size(); i++){
        delete clients[i];
    }
}
