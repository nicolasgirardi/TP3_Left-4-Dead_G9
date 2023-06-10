#include <iostream>
#include "server_allgames.h"
#include "server_queue.h"
#include "server_codes.h"
#include "server_game.h"
#include "server_message.h"

Game* Allgames::create_game(Queue<Message>* my_queue){
    std::unique_lock<std::mutex> lck(m);
    Game* new_game = new Game(code_generator.new_code(),my_queue);
    games.push_back(new_game);
    return new_game;
}
Game* Allgames::joing_game(uint32_t code,Queue<Message>* my_queue){
    std::unique_lock<std::mutex> lck(m);
    for (int i = 0; i<(int)games.size(); i++){
        if (games[i]->is_game(code)){
            games[i]->add_queue(my_queue);
            return games[i];
        }
    }
    return nullptr;
}
void Allgames::end(){
    for (int i = 0; i<(int)games.size(); i++){
        games[i]->end();
    }
}
Allgames::~Allgames(){
    for (int i = 0; i<(int)games.size(); i++){
        delete games[i];
    }
}
