#include <iostream>

#include "integer.hpp"

int main(void)
{
    dra::number* ptr = new dra::integer(-9);
    
    std::cout << *ptr << std::endl;
    
    delete ptr;
    
    return 0;
}

