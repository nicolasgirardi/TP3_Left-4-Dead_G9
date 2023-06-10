#ifndef SERVER_CODES_H
#define SERVER_CODES_H
#include <iostream>

class Codes{
    private:
    uint32_t counter;
    
    public:
    Codes();

    uint32_t new_code();
};
#endif
