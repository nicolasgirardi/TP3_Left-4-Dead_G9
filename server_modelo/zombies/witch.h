#ifndef LEFT4DEAD_WITCH_H
#define LEFT4DEAD_WITCH_H

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


#endif //LEFT4DEAD_WITCH_H
