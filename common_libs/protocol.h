#ifndef LEFT4DEADUI_PROTOCOL_H
#define LEFT4DEADUI_PROTOCOL_H

#include "../client/include/user_action.h"
#include "common_socket.h"
#include "../client/include/game_update.h"

class Protocol {
private:
    Socket socket;
    bool wasClosed;
    void sendByte(uint8_t byte);
    void sendFourBytes(int32_t param1);
    uint8_t recvByte();
    uint16_t recvTwoBytes();
    uint32_t recvFourBytes();
public:
    Protocol();
    Protocol(Socket&& peer);
    void sendAction(const UserAction& action);
    void receiveUpdate(GameUpdate& update);
    void closeConection();
    std::string recibir_inicio_partida();
    std::string create();
    std::string recibir_nombre_partida();
    uint32_t recibir_codigo_partida();

    void enviar_codigo_partida(uint32_t codigoPartida);
};


#endif // LEFT4DEADUI_PROTOCOL_H
