#include <iostream>
#include "server_queue.h"
#include "server_message.h"
#include "server_allqueues.h"
#include "server_game.h"
#include "server_gamelogic.h"

Game::Game(uint32_t code,Queue<Message>* new_queue): main_queue(2000){
    this->code = code;
    this->queues.add_queue(new_queue);
    game_logic = new Gamelogic(&this->main_queue,&this->queues);
    game_logic->start();
}
bool Game::is_game(uint32_t code){
    return this->code == code;
}
void Game::add_queue(Queue<Message>* new_queue){
    queues.add_queue(new_queue);
}
void Game::remove_queue(Queue<Message>* old_queue){
    queues.remove_queue(old_queue);
}
void Game::broadcast(Message broadast){
    main_queue.push(broadast);
}
uint32_t Game::get_code(){
    return this->code;
}
void Game::end(){
    main_queue.close();
    game_logic->join();
}
Game::~Game(){
    delete game_logic;
}
