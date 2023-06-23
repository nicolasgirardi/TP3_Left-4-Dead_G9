#ifndef JUMPER_H_
#define JUMPER_H_

#include <list>
#include "../personaje.h"

class Jumper {
    private:
        int x;
        int y;
        int vida = 20;
        float velocidad = 1;
    
        public:
            Jumper(int x, int y);
            int get_x();
            int get_y();
            int get_vida();
            int get_velocidad();
            ~Jumper();
            void mover(std::list<Personaje*> personajes);
            bool esta_vivo();
            void recibir_danio(int danio);
};

#endif  // JUMPER_H_