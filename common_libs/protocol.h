#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <thread>
#include <cstdint>
#include <vector>
#include <string>
#include <netinet/in.h>
#include "common_socket.h"
#include "evento_usuario.h"
#include "../server_modelo/eventos/evento.h"

class Protocol {
private:
    Socket socket;
    bool wasClosed;
    void sendByte(uint8_t byte);
    void sendCuatroBytes(int32_t param1);
    uint8_t recvByte();
    uint16_t recvDosBytes();
    uint32_t recvCuatroBytes();
    std::string recvData(std::vector<char>& buff);
public:
    Protocol(Socket&& peer);
    void sendEvento(const EventoUsuario& evento);
    void cerrarConexion();
    std::string recibir_inicio_partida();
    std::string recibir_nombre_partida();
    uint32_t recibir_codigo_partida();
    void enviar_codigo_partida(uint32_t codigoPartida);
    void enviar_evento(Evento *evento);
};

#endif // PROTOCOL_H
