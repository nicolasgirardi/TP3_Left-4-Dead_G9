#ifndef LEFT4DEAD_SENDERSERVER_H
#define LEFT4DEAD_SENDERSERVER_H


#include <atomic>
#include "../../common/include/Thread.h"
#include "../../common/include/Protocol.h"
#include "../../common/include/ProtectedQueue.h"
#include "UserAction.h"

class SenderServer : public Thread {
private:
    Protocol& protocol;
    ProtectedQueue<UserAction>& userActions;
    std::atomic<bool>& isRunning;

public:
    SenderServer(ProtectedQueue<UserAction>& userActions, Protocol& protocol, std::atomic<bool>& isRunning);

    void run() override;

    void stop();

    ~SenderServer();

    SenderServer(const SenderServer&) = delete;
    SenderServer& operator=(const SenderServer&) = delete;

    SenderServer(SenderServer&& other) = delete;
    SenderServer& operator=(SenderServer&& other) = delete;
};


#endif // LEFT4DEAD_SENDERSERVER_H
