#ifndef LEFT4DEADUI_PROTOCOL_H
#define LEFT4DEADUI_PROTOCOL_H

#include "../client/include/user_action.h"
#include "common_socket.h"
#include "../client/include/game_update.h"

class Protocol {
private:
    Socket socket;
    bool wasClosed;
public:
    Protocol(std::string port);
    void sendAction(const UserAction& action);
    void sendByte(uint8_t byte);
    void sendFourBytes(int32_t param1);

    void receiveUpdate(GameUpdate& update);

    uint8_t recvByte();

    int32_t recvFourBytes();

    void closeConection();
};


#endif // LEFT4DEADUI_PROTOCOL_H
