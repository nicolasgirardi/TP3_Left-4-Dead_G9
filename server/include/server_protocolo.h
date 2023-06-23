#ifndef SERVER_PROTOCOLO_H
#define SERVER_PROTOCOLO_H

#include <string.h>
#include <list>

#include "../../common_libs/include/common_thread.h"
#include "../../common_libs/include/common_socket.h"
#include "../../common_libs/include/common_queue.h"
#include "eventos/evento.h"
#include "partida.h"
#include "estado_jugador.h"
#include "../../common_libs/include/common_message.h"
#include "server_cliente_enum.h"

class Protocolo {
private:
    Socket* socket;
    Queue<Evento*>* queue;
    int id;
    bool wasClosed;
    uint16_t recvDosBytes();
    uint32_t recvCuatroBytes();
    uint8_t recvByte();

public:
    explicit Protocolo(Socket* socket, Queue<Evento*>* queue, int id);
    ~Protocolo();
    uint8_t recibir_codigo();
    std::string recibir_nombre();
    uint32_t recibir_codigo_partida();
    std::pair<int32_t, int32_t> recibir_coordenadas();
    void enviar_codigo_partida(uint32_t codigo);
    void enviar_estado_juego(std::string estado);
    Message recibir_estado_juego();

    uint32_t join();
    std::pair<int32_t, int32_t> move();
    std::string recibir_inicio_partida();

    Evento *recibir_evento(int& idPersonaje);
};

#endif //SERVER_PROTOCOLO_H
