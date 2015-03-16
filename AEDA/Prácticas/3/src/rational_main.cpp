#include <iostream>

#include "rational.hpp"

int main(void)
{
    dra::rational test(16,5);
    
    dra::rational other(16,9);
    
    std::cout << other << " - " << test << std::endl;
    
    
    dra::rational othero(other-test);
    
    std::cout << othero << std::endl;
    
    return 0;
}