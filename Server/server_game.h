#ifndef SERVER_GAME_H
#define SERVER_GAME_H
#include <iostream>
#include "server_queue.h"
#include "server_thread.h"
#include "server_message.h"
#include "server_allqueues.h"
#include "server_gamelogic.h"

class Game{
    private:
    Queue<Message> main_queue;
    uint32_t code;
    Allqueues queues;
    Thread* game_logic;
   
    public:
    Game(uint32_t code,Queue<Message>* new_queue);

    bool is_game(uint32_t code);

    void add_queue(Queue<Message>* new_queue);

    void remove_queue(Queue<Message>* old_queue);

    void broadcast(Message broadast);

    uint32_t get_code();

    void end();
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;

    ~Game();
};
#endif
