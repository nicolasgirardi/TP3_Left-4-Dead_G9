#include "../include/Client.h"

int main (int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Invalid args, must be: ./client <PORT>." << std::endl;
        return 1;
    }
    Client client;
    client.start();
    try {
        cliente.init();
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }

    return 0;
}
