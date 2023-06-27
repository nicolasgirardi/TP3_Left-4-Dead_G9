#include <iostream>
#include "../include/common_center.h"

Center::Center(){
    sum = 0;
    num = 0;
}
void Center::add_participation(int& value){
    sum = sum + value;
    num++;
}

void Center::add_participation(int& value,int& weight){
    sum = sum + value;
    num = num + weight;
}

int Center::center_value(){
    if(num > 0)
        return sum/num;
    else
        return 0;
}