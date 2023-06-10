#include <iostream>
#include "server_codes.h"
Codes::Codes(){
    counter = 0;
}

uint32_t Codes::new_code(){
    uint32_t valid_code = counter;
    counter++;
    return valid_code;
}
