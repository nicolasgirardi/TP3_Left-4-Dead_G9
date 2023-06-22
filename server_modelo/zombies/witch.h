#ifndef WITCH_H_
#define WITCH_H_

#include <string>

class Witch {
 private:
    int max_x;
    int max_y;
    int x;
    int y;
    int vida = 50;
 public:
        Witch(int max_x, int max_y);
        int get_x();
        int get_y();
        int get_vida();
        ~Witch();
        bool esta_vivo();
        void recibir_danio(int danio);
        std::string serializar();
};

#endif  // WITCH_H_
