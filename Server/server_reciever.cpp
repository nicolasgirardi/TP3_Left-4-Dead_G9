#include <iostream>
#include "server_thread.h"
#include "server_queue.h"
#include "server_game.h"
#include "common_socket.h"
#include "server_reciever.h"
#include "server_protocol.h"
#include "server_allgames.h"
#include "server_message.h"
#include "server_sender.h"
#include "common_liberror.h"
#include <string>
#include <utility>

Reciever::Reciever(Socket& socket,Allgames* games,bool* status): 
                    skt(std::move(socket)), my_queue(2000){
    close = status;
    allgames = games;
    my_sender = nullptr;
    my_game = nullptr;
}

void Reciever::run(){
    //recibir del socket
    Protocol protocol;
    Message message;
    bool close2 = false;
    if (first_communication() == 0){
        try {
            while (!close2){
                message = protocol.receive(&skt,&close2);
                if (message.get_size() != 0)
                    my_game->broadcast(message);
                else
                    close2 = true;
            }
        }
        catch (std::exception &e){}
        my_game->remove_queue(&my_queue);
    }
    skt.close();
    my_queue.close();
    my_sender->join();
    delete my_sender;
}
void Reciever::finish(){
    skt.close();
}
int Reciever::first_communication(){
    Protocol protocol;
    uint8_t action = protocol.receive_action(&skt,close);
    std::string print;
    int result = 0;
    switch (action){
        case (1):{
            protocol.receive_name(&skt,close);
            my_game = allgames->create_game(&this->my_queue);
            protocol.send_code(&skt,close,my_game->get_code());
            print.assign("Created match: ");
            print += std::to_string(my_game->get_code());
            break;
        }
        case (2):
        {
            uint32_t code = protocol.receive_code(&skt,close);
            my_game = allgames->joing_game(code,&this->my_queue);
            uint8_t game_found = (my_game == nullptr);
            protocol.send_result(&skt,close,game_found);
            if (!game_found){
                print.assign("Joined to match: 0");
            }else{
                print.assign("Match does not exist: 1");
                *close = true;
                result = 1;
            }
            break;
        }
        default:
            //se envio cualquier cosa
            *close = true;
            result = 1;
    }
    std::cout << print << std::endl;
    my_sender = new Sender(&skt,&this->my_queue);
    my_sender->start();
    return result;
}
Reciever::~Reciever(){
}
