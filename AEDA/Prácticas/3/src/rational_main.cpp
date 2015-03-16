#include <iostream>

#include "rational.hpp"

int main(void)
{
    dra::rational aux1(1565,14566);
    dra::rational aux2(6556,3);
    dra::rational aux3(12678,4);
    dra::rational aux4;
    
    std::cout << "Voy a hacer la operacion" << std::endl;
    
    aux4 = aux1 + aux2 - aux3;
    
    return 0;
}