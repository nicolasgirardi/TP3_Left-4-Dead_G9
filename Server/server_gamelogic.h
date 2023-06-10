#ifndef SERVER_GAMELOGIC_H
#define SERVER_GAMELOGIC_H

#include <iostream>
#include "server_thread.h"
#include "server_game.h"
#include "server_queue.h"
#include "server_message.h"

class Gamelogic: public Thread{
    private:
    Queue<Message>* pop_queue;
    Allqueues* pushing_queues;

    public:
    Gamelogic(Queue<Message>* main_queue,Allqueues* all_queues);

    void run() override;
    private:
    int logic(Message& message);
};
#endif
