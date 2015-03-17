#include <iostream>
#include "complex.hpp"

int main(void)
{
    dra::complex test(1,7);
    dra::complex test2(7,2);
    
    std::cout << test << std::endl;
    std::cout << test2 << std::endl;
    
    dra::complex test3;
    
    test3 = test2 * test;
    
    std::cout << test3 << std::endl;
}