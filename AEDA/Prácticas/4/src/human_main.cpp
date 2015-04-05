#include "human.hpp"

#include <iostream>

int main(void)
{
    dra::human testSubject;
    
    testSubject.name() = "Cave";
    testSubject.surname() = "Johnson";
    testSubject.dni() = 48905505;
    testSubject.number() = 4258899642;
    
    std::cout << testSubject << std::endl;
    
    return 0;
}