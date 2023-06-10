#ifndef SERVER_ALLQUEUES_H
#define SERVER_ALLQUEUES_H
#include <iostream>
#include "server_queue.h"
#include "server_message.h"
#include <vector>

class Allqueues{
    private:
    std::vector<Queue<Message>*> queues;
    std::mutex m;

    public:
    void add_queue(Queue<Message>* new_queue);

    void remove_queue(Queue<Message>* new_queue);

    void push(Message content);
};
#endif
