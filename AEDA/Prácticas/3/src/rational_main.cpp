#include <iostream>

#include "rational.hpp"

int main(void)
{
    dra::rational aux1(14,-314);
    
    dra::rational aux2(13,-314);
    
    bool logic = aux1 >= aux2;
    
    std::cout << logic << std::endl;
    
    return 0;
}