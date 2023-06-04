#include "../include/receiver_update.h"
#include "../../common/include/LibError.h"

ReceiverUpdate::ReceiverUpdate(Protocol& protocol, ProtectedQueue<GameUpdate>& updates)
 : protocol(protocol), updates(updates), running(true) {}

void ReceiverUpdate::run() {
    try {
        GameUpdate update;
        while (this->running) {
            update = this->protocol.receiveUpdate(std::ref(update));
            this->updates.push(update);
        }
    } catch (const LibError &e) {
        std::cout << e.what() << std::endl;
    }
}




