#ifndef CLIENT_CENTER_H
#define CLIENT_CENTER_H

#include <iostream>

class Center{
    private:
    int sum;
    int num;

    public:
    Center();
    
    void add_participation(int& value);

    void add_participation(int& value,int& weight);

    int center_value();

};
#endif
