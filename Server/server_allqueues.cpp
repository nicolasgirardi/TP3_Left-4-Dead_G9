#include <iostream>
#include "server_queue.h"
#include "server_message.h"
#include "server_allqueues.h"

void Allqueues::add_queue(Queue<Message>* new_queue){
    std::unique_lock<std::mutex> lck(m);
    queues.push_back(new_queue);
}
void Allqueues::remove_queue(Queue<Message>* old_queue){
    std::unique_lock<std::mutex> lck(m);
    int i = 0;
    bool finished = false;
    while (i < (int) queues.size() && !finished){
        if (queues[i] == old_queue){
            queues.erase(queues.begin()+i);
            finished = true;
        }
        i++;
    }
}
void Allqueues::push(Message content){
    std::unique_lock<std::mutex> lck(m);
    for (uint32_t i = 0; i<queues.size(); i++){
        try{
            queues[i]->push(content);
        }
        catch(std::exception &e){}
    }
}
