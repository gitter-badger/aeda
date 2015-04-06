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
    
    
    dra::key* ptr = new dra::key_human_dni(testSubject);
    
    std::cout << ptr << std::endl;
    
    
    return 0;
}