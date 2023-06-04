// Se encarga de la comunicacion con el cliente.
// Recibe los create y los join.

// En un principio es el encargado de recibir los create/join y devolver los mensajes correspondientes
// Cuando arranca el juego se convierte en el reciever

#ifndef SERVER_CLIENTE_HANDLER_H
#define SERVER_CLIENTE_HANDLER_H

#include "./../common_libs/common_thread.h"
#include "./../common_libs/common_queue.h"

#include "./../server_modelo/eventos/evento.h"
#include "./../server_modelo/eventos/creador_eventos.h"

class ClienteHandler : public Thread {
 private:
    bool running;
    bool keep_running;
    Queue<Evento*>* queue;
    CreadorEventos creador;

 public:
    explicit ClienteHandler(Queue<Evento*>* queue);
    void run() override;
    void stop();
};

#endif