#include <utility>

#include "../include/Client.h"
#include "../include/SenderServer.h"
#include "../include/ReceiverUpdate.h"

Client::Client(std::string port) : protocol(std::move(port)), isRunning(true) {}

void Client::init() {
    SenderServer senderServer(std::ref(userActions), std::ref(protocol), std::ref(isRunning));
    ReceiverUpdate receiverUpdate(std::ref(protocol), std::ref(updates));
    senderServer.start();
    receiverUpdate.start();

    receiverUpdate.join();
    senderServer.join();
}


