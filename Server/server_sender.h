#ifndef SERVER_SENDER_H
#define SERVER_SENDER_H

#include "common_socket.h"
#include "server_thread.h"
#include "server_queue.h"
#include "server_sender.h"

class Sender: public Thread{
    private:
    Socket* skt;
    Queue<Message>* my_queue;
    bool close;
    public:
    Sender(Socket* socket,Queue<Message>* queue);

    void run() override;
};
#endif
