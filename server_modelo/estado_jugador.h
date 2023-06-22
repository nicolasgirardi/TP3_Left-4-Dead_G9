#ifndef LEFT4DEAD_ESTADO_JUGADOR_H
#define LEFT4DEAD_ESTADO_JUGADOR_H

#include "personaje.h"

class EstadoJugador {
private:
    int id_soldado;
    int x;
    int y;
    int actualmente_disparando;
    int actualmente_moviendo;

public:
    EstadoJugador(Personaje* personaje);
    ~EstadoJugador();
    std::string serializar();
};


#endif //LEFT4DEAD_ESTADO_JUGADOR_H
