#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <arpa/inet.h>
#include <cstring>

#include "client_parsing.h"
#include "common_socket.h"
#include "client_protocol.h"

void Parsing::parse_command(std::string& command,Protocol& protocol){
    std::string word;
    std::stringstream com(command);
    com >> word;
    if (word.compare("create") == 0){
        com >> word;
        protocol.create_game(word);
        }
    if (word.compare("join") == 0){
        uint32_t code;
        com >> code;
        protocol.join_game(code);
    }
    if (word.compare("broadcast") == 0){
        com >> word;
        protocol.broadcast(word);
        }
    if (word.compare("start") == 0){
        com >> word;
        protocol.broadcast(word);
        }
}
