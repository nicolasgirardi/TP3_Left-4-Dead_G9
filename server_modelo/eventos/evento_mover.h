#ifndef LEFT4DEAD_EVENTO_MOVER_H_
#define LEFT4DEAD_EVENTO_MOVER_H_

#include "evento.h"

class EventoMover : public Evento {
    private:
        int x;
        int y;

    public:
        EventoMover(int id_personaje, int x, int y);
        ~EventoMover() override;
        void ejecutar(Personaje* personaje) override;
};

#endif // LEFT4DEAD_EVENTO_MOVER_H_