#ifndef LEFT4DEAD_CLIENT_H
#define LEFT4DEAD_CLIENT_H


#include <atomic>
#include "../../common/include/Thread.h"
#include "UserAction.h"
#include "../../common/include/ProtectedQueue.h"
#include "../../common/include/Protocol.h"
#include "GameUpdate.h"

class Client {
 private:
    std::atomic<bool> isRunning;
    Protocol protocol;
    ProtectedQueue <UserAction> userActions;
    ProtectedQueue <GameUpdate> updates;

 public:
    explicit Client(std::string port);
    void init();

    Client(const Client&) = delete;
    Client& operator=(const Client&) = delete;
    ~Client() = default;
};


#endif //LEFT4DEAD_CLIENT_H
