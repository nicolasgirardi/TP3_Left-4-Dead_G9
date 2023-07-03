#ifndef COMMON_PROTOCOLO_H_
#define COMMON_PROTOCOLO_H_

#include <cstdint>
#include <string>
#include <vector>
#include "common_socket.h"
#include "common_message.h"
#include "eventos/evento.h"
#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <functional>
#include "common_mensaje_cliente.h"
#include "eventos/creador_eventos.h"
#include "evento_usuario.h"
#include "common_estado_juego.h"
#include "common_myenum.h"

#define CODIGO_INVALIDO 0xFFFFFFFF

class Protocolo {
 private:
    Socket socket;
    bool wasClosed;
    void sendByte(uint8_t byte);
    void sendDosBytes(uint16_t dosBytes);
    void sendCuatroBytes(int32_t param1);
    int sendData(const std::string& data);

    uint8_t recvByte();
    uint16_t recvDosBytes();
    uint32_t recvCuatroBytes();
    std::string recvData();
    Message getMessage(std::string& estadoJuego);

 public:
    Protocolo(const std::string &hostname, const std::string &servname);
    explicit Protocolo(Socket socket);

    void enviar_codigo_partida(uint32_t codigoPartida);
    void enviar_estado_juego(EstadoJuego& estadoJuego);
    void enviar_inicio_partida(std::vector<std::string> inicioPartida);
    void enviar_info(std::string info);
    void enviar_evento(const EventoUsuario &eventoUsuario);

    Message recibir_estado_juego();
    std::string recibir_inicio_partida();
    Evento *recibir_evento(int& idPersonaje);
    Personaje recibir_personaje();
    uint32_t recibir_codigo_partida();
    uint8_t recibir_modo();
    std::string recibir_nombre();
    void cerrarConexion();
    ~Protocolo();

};
#endif // COMMON_PROTOCOLO_H_
