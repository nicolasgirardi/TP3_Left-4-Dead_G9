#ifndef LEFT4DEAD_SENDER_SERVER_H
#define LEFT4DEAD_SENDER_SERVER_H


#include <atomic>
#include "../../common_libs/common_queue.h"
#include "user_action.h"
#include "../../common_libs/common_thread.h"

class SenderServer : public Thread {
private:
    Protocol& protocol;
    ProtectedQueue<UserAction>& userActions;
    std::atomic<bool>& isRunning;

public:
    SenderServer(Queue<UserAction>& userActions, Protocol& protocol, std::atomic<bool>& isRunning);

    void run() override;

    void stop();

    ~SenderServer();

    SenderServer(const SenderServer&) = delete;
    SenderServer& operator=(const SenderServer&) = delete;

    SenderServer(SenderServer&& other) = delete;
    SenderServer& operator=(SenderServer&& other) = delete;
};


#endif // LEFT4DEAD_SENDER_SERVER_H
