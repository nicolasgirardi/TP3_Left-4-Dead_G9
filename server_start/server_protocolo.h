#ifndef SERVER_PROTOCOLO_H
#define SERVER_PROTOCOLO_H

#include <string.h>
#include <list>

#include "./../common_libs/common_thread.h"
#include "./../common_libs/common_socket.h"
#include "./../common_libs/common_queue.h"
#include "./../server_modelo/eventos/evento.h"
#include "./../server_modelo/partida.h"
#include "./../server_modelo/estado_jugador.h"

//0x01 create + 8bits con largo del nombre + string
//0x02 join + 32bits del codigo
//0x03 move + 2 coordenadas en 2 variables de 32bits con signo
//0x04 stop movecommon_libs/common_protocolo
//0x05 shoot
//0x06 stop shoot
//0x07 bomb + 1 coordenada en 1 variable de 32bits con signo para la direccion
//0x08 strike


class Protocolo{
 private:
    Socket* socket;
    Queue<Evento*>* queue;
    int id;

 public:
    explicit Protocolo(Socket* socket, Queue<Evento*>* queue, int id);
    ~Protocolo();
    uint8_t recibir_codigo();
    std::string recibir_nombre();
    uint32_t recibir_codigo_partida();
    std::pair<int32_t, int32_t> recibir_coordenadas();
    void enviar_codigo_partida(uint32_t codigo);
    void enviar_estado_juego(std::string estado);

    std::string create();
    uint32_t join();
    std::pair<int32_t, int32_t> move();
};

#endif  // SERVER_PROTOCOLO_H