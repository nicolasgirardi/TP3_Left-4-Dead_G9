#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cout << "Error: argumentos invalidos" << std::endl;
        return 1;
    }
    std::cout << "Client working" << std::endl;
}