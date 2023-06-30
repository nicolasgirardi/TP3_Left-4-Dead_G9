#ifndef SERVER_CLIENTE_HANDLER_H
#define SERVER_CLIENTE_HANDLER_H


#include <atomic>
#include "../../common_libs/include/common_thread.h"
#include "../../common_libs/include/common_socket.h"
#include "../../common_libs/include/common_queue.h"
#include "partida.h"
#include "server_reciever.h"
#include "lista_partida.h"
#include "../../common_libs/include/common_thread.h"
#include "../../common_libs/include/common_queue.h"
#include "../../common_libs/include/common_socket.h"
#include "partida.h"
#include "../../common_libs/include/eventos/evento.h"
#include "../../common_libs/include/eventos/creador_eventos.h"
#include "./server_reciever.h"
#include "../../common_libs/include/common_protocolo.h"
#include "../../common_libs/include/common_estado_juego.h"

#define CREAR "crear"
#define JOIN "join"

class ClienteHandler : public Thread {
private:
    bool running;
    bool keep_running;
    int id;
    Protocolo protocolo;
    ListaPartidas* partidas;
    Partida* partida;
    Queue<EstadoJuego> mensajes;
    Queue<Evento*>* queueJuego;
    std::atomic<bool> esDuenio;
    Juego* juego;
    int idPersonajeElegido;

public:
    ClienteHandler(Socket socket, ListaPartidas* partidas, int id);
    ~ClienteHandler();
    Queue<EstadoJuego>* get_mensajes();
    bool is_running();
    void run() override;
    void stop();
    void create_reciever(Queue<Evento*>& queue);
    uint32_t iniciar_partida();
    uint32_t crearPartida();
    uint32_t joinPartida(uint32_t codigoPartida);
};

#endif // SERVER_CLIENTE_HANDLER_H
