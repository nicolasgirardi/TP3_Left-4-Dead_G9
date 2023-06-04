#include "../include/sender_server.h"

SenderServer::SenderServer(Queue<UserAction> &userActions, Protocol &protocol, std::atomic<bool>& isRunning)
    : userActions(userActions), protocol(protocol), isRunning(isRunning){}

void SenderServer::run() {
    bool couldPop;
    while (this->isRunning) {
        UserAction userAction;
        couldPop = this->userActions.try_pop(std::ref(userAction));
        if (couldPop) {
            this->protocol.sendAction(std::ref(userAction));
        }
    }
}

void SenderServer::stop() {
    this->isRunning = false;
    this->protocol.closeConection();
}
