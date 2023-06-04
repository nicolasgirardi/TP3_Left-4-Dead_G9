#ifndef LEFT4DEAD_CLIENT_H
#define LEFT4DEAD_CLIENT_H


#include <atomic>
#include "../../common/include/Thread.h"
#include "user_action.h"
#include "../../common/include/ProtectedQueue.h"
#include "../../common_libs/protocol.h"
#include "game_update.h"

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
