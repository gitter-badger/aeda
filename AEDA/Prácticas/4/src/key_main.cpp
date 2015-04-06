#include "key.hpp"
#include "key_human.hpp"
#include "key_human_dni.hpp"

int main(void)
{
    dra::human* testSubject = new dra::human;
    
    testSubject->name() = "Cave";
    testSubject->surname() = "Johnson";
    testSubject->dni() = 47905505;
    testSubject->number() = 4258899642;
    
    
    dra::key_human_dni key_1(testSubject);
    
    unsigned long hasher = key_1.value();
    
    std::cout << hasher << std::endl;
    
    
    return 0;
}