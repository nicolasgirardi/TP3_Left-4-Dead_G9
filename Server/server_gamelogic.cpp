#include <iostream>
#include "server_thread.h"
#include "server_game.h"
#include "server_queue.h"
#include "server_message.h"

Gamelogic::Gamelogic(Queue<Message>* main_queue,Allqueues* all_queues){
    pop_queue = main_queue;
    pushing_queues = all_queues;
}

void Gamelogic::run(){
    try {
        while (true){
            Message content = pop_queue->pop();
            if (logic(content) == 0)
                pushing_queues->push(content);
        }
    }
    catch (std::exception &e){}
}
int Gamelogic::logic(Message& message){
    if (message.get_code() == 3){
        message.change_code(4);
        return 0;
    }
    return 1;
}
