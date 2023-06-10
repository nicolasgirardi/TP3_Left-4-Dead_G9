#include "client_client.h"
#include "client_protocol.h"
#include <exception>
#include "common_socket.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

#include "common_liberror.h"
#include "client_parsing.h"

Client::Client(char* server,char* port): socket(server,port) {}
    

void Client::process_commands(){
    bool close = false;
    std::string command,word;
    while (!close){
        std::getline(std::cin,command);
        std::stringstream com(command);
        com >> word;
        if (word.compare("read") == 0){
            int times;
            com >> times;
            for (int i = 0; i<times; i++){
                this->receive_broadcast(&close);
            }
        }
        if (word.compare("leave") == 0){
                close = true;
            }
        if (word.compare("create") == 0){
            this->send(command,&close);
            this->receive_create(&close);
        }
        if (word.compare("join") == 0){
            this->send(command,&close);
            this->receive_join(&close);
        }
        if (word.compare("broadcast") == 0)
            this->send(command,&close);
    }
    socket.close();
}
void Client::receive_broadcast(bool* close){
    std::string broadcasted;
    Protocol protocol;
    protocol.receive_read(socket,close,broadcasted);
    std::cout << "Broadcasted: " << broadcasted << std::endl; 
}
void Client::receive_join(bool* close){
    uint8_t code;
    Protocol protocol;
    code = protocol.receive_join(socket,close);
    if (code == 0)
        std::cout << "Joined to match: " << (int) code << std::endl;
    else
        std::cout << "Match does not exist: " << (int) code << std::endl;
}
void Client::receive_create(bool* close){
    uint32_t code;
    Protocol protocol;
    code = protocol.receive_create(socket,close);
    std::cout << "Created match: " << code << std::endl;
}
void Client::send(std::string& command,bool* close){
    Protocol protocol;
    Parsing parsing;
    parsing.parse_command(command,protocol);
    protocol.send(&socket,close);
}
