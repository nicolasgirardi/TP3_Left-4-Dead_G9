#ifndef SERVER_ALLGAME_H
#define SERVER_ALLGAME_H
#include <iostream>
#include "server_queue.h"
#include "server_codes.h"
#include "server_game.h"
#include "server_message.h"
#include <vector>

class Allgames{
    private:
    std::vector<Game*> games;
    Codes code_generator;
    std::mutex m;

    public:
    Game* create_game(Queue<Message>* myqueue);

    Game* joing_game(uint32_t code,Queue<Message>* myqueue);

    void end();

    ~Allgames();
};
#endif
