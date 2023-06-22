#ifndef RECEIVER_UPDATE_H
#define RECEIVER_UPDATE_H


#include "../../common/include/Thread.h"
#include "../../common/include/Socket.h"
#include "game_update.h"
#include "../../common/include/ProtectedQueue.h"
#include "../../common_libs/protocol.h"

class ReceiverUpdate : public Thread {
private:
    Protocol& protocol;
    bool running;
    ProtectedQueue<GameUpdate>& updates;

public:
    ReceiverUpdate(Protocol& protocol, ProtectedQueue<GameUpdate>& updates);
    ~ReceiverUpdate();
    void run() override;
    void stop();

};


#endif // RECEIVER_UPDATE_H
