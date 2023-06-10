#ifndef CLIENT_PARSING_H
#define CLIENT_PARSING_H
#include <string>
#include "client_protocol.h"
class Parsing{
    public:
    void parse_command(std::string& command,Protocol& protocol);
};
#endif
