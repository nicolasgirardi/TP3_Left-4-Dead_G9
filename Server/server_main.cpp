#include <iostream>
#include <thread>
#include "common_socket.h"
#include "server_server.h"
#include "server_thread.h"


int main(int argc,char* argv[]){
    if (argc != 2){
        std::cout << "bad program call, expected " << argv[0];
        std::cout << "<servicename/port>" << std::endl;
        return -1;
    }
    Server server(argv[1]);

    server.run();

    return 0;
}
