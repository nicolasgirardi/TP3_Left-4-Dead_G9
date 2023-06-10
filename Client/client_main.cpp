#include <iostream>

#include "client_client.h"

int main(int argc,char* argv[]){
    if (argc != 3){
        std::cout << "bad program call, expected " << argv[0];
        std::cout << "<hostname server/ip> <servicename/port>" << std::endl;
        return -1;
    }
    Client client = Client(argv[1],argv[2]);

    client.process_commands();
    return 0;
}
