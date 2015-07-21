#include <iostream>

#include "integer.hpp"

int main(void)
{
    dra::integer test1(-2147483644);
    
    dra::integer test2(-1);
    
    dra::integer test3;
    
    test3 = test1 - test2;
    
    std::cout << test3 << std::endl;
    
    return 0;
}

