#ifndef EVENTO_MOVER_H_
#define EVENTO_MOVER_H_

#include "evento.h"

class EventoMover : public Evento {
    private:
        int x;
        int y;

    public:
        EventoMover(int id_personaje, int x, int y);
        ~EventoMover();
        void ejecutar(Personaje* personaje);
};

#endif // EVENTO_MOVER_H_