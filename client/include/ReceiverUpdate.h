#ifndef LEFT4DEAD_RECEIVERUPDATE_H
#define LEFT4DEAD_RECEIVERUPDATE_H


#include "../../common/include/Thread.h"
#include "../../common/include/Socket.h"
#include "GameUpdate.h"
#include "../../common/include/ProtectedQueue.h"
#include "../../common/include/Protocol.h"

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


#endif //LEFT4DEAD_RECEIVERUPDATE_H
