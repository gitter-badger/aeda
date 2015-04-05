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
    
    std::cout << *testSubject << ", direccion de memoria: " << testSubject << std::endl;
    
    dra::key_human_dni test_key(50, testSubject);
    
    std::cout << "Clave: " << test_key.value() << std::endl;
    
    return 0;
}