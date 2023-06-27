#include "../include/server_cliente_handler.h"

ClienteHandler::ClienteHandler(Socket socket, ListaPartidas* partidas, int id) :
        protocolo(std::move(socket)), partidas(partidas), running(true), keep_running(true), id(id),
        mensajes(20), esDuenio(false), juego(nullptr) {}

ClienteHandler::~ClienteHandler() {}

bool ClienteHandler::is_running() {
    return running;
}

void ClienteHandler::run() {
    uint32_t codigoPartida = CODIGO_INVALIDO;
    while (codigoPartida == CODIGO_INVALIDO) {
        codigoPartida = iniciar_partida();
        protocolo.enviar_codigo_partida(codigoPartida);
    }
    Partida& partida = partidas->getPartida(codigoPartida);
    Reciever reciever(std::ref(protocolo), partida.getQueueJuego(), idPersonajeElegido);
    reciever.start();
    if (esDuenio) {
        while (!partida.isFull()){}
        juego = new Juego(partida.getClientes(), partida.getPersonajes(), partida.getModo(),
                          partida.getQueueJuego());
        juego->start();
    }
    while(partida.getRunning()) {
        std::string msg = mensajes.pop();
        protocolo.enviar_estado_juego(msg);
    }
    if (juego != nullptr) {
        protocolo.enviar_estado_juego("FIN");
        juego->stop();
        juego->join();
        delete juego;
    }
    reciever.join();
    running = false;
}

uint32_t ClienteHandler::iniciar_partida() {
    uint32_t codigoPartida;
    std::string inicio_partida = protocolo.recibir_inicio_partida();
    if (inicio_partida == CREAR) {
        codigoPartida = crearPartida();
    } else if (inicio_partida == JOIN) {
        codigoPartida = protocolo.recibir_codigo_partida();
        joinPartida(codigoPartida);
    } else {
        return CODIGO_INVALIDO;
    }
    return codigoPartida;
}

void ClienteHandler::stop() {
    keep_running = false;
    // Fuerzo a un cierre total del socket
    //socketshutdown(2);
    //socket.close();
    //reciever.stop();
    //reciever.join();
}


uint32_t ClienteHandler::crearPartida() {
    std::string nombrePartida = protocolo.recibir_nombre();
    uint8_t modo = protocolo.recibir_modo();
    Personaje personaje = protocolo.recibir_personaje();

    int idPartida = partidas->addPartida(nombrePartida, modo);
    Partida& partida = partidas->getPartida(idPartida);
    partida.addClient(std::ref(mensajes), id, personaje);
    esDuenio = true;
    idPersonajeElegido = personaje.get_id();
    return idPartida;
}

uint32_t ClienteHandler::joinPartida(uint32_t codigoPartida) {
    try {
        Partida &partida = partidas->getPartida(codigoPartida);
        Personaje personaje = protocolo.recibir_personaje();
        idPersonajeElegido = personaje.get_id();
        partida.addClient(std::ref(mensajes), id, personaje);
        return partida.getId();
    } catch (std::exception& e) {
        return CODIGO_INVALIDO;
    }
}
