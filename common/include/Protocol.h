#ifndef LEFT4DEADUI_PROTOCOL_H
#define LEFT4DEADUI_PROTOCOL_H

#include "Socket.h"
#include "../../client/include/UserAction.h"
#include "../../client/include/GameUpdate.h"

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
