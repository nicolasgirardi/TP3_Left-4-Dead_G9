#ifndef SERVER_LISTENING_H
#define SERVER_LISTENING_H
#include <iostream>
#include "server_thread.h"
#include "server_codes.h"
#include "common_socket.h"
#include "server_game.h"
#include "server_queue.h"
#include "server_allgames.h"
#include "server_client.h"
#include <vector>

class Listening: public Thread{
    private:
    Socket* socket;
    Allgames games;
    std::vector<Client*> clients;
        
    
    public:
    explicit Listening(Socket* skt);

    void run() override;

    ~Listening();
};
#endif
