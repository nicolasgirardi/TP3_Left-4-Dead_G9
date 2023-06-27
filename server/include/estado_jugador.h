#ifndef ESTADO_JUGADOR_H_
#define ESTADO_JUGADOR_H_

#include "../../common_libs/include/common_personaje.h"

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

#endif  // ESTADO_JUGADOR_H_
