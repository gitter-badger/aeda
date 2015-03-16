#include <iostream>

#include "natural.hpp"

int main(void)
{
    dra::number* ptr = new dra::natural(9);
    
    std::cout << *ptr << std::endl;
    
    delete ptr;
    
    return 0;
}

