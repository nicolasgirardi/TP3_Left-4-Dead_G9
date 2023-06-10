#ifndef SERVER_RECIEVER_H
#define SEVER_RECIEVER_H
#include <iostream>
#include "server_thread.h"
#include "server_queue.h"
#include "server_game.h"
#include "common_socket.h"
#include "server_allgames.h"
#include "server_message.h"

class Reciever: public Thread {
    private:
    Socket skt;
    Queue<Message> my_queue;
    Game* my_game;
    Thread* my_sender;
    Allgames* allgames;
    bool* close;
        
    public:
    Reciever(Socket& socket,Allgames* games,bool* status);

    void run() override;

    void finish();
    
    ~Reciever();

    private:
    int first_communication();
};
#endif
