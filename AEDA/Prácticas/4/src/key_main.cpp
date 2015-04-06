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
    
    dra::key* ptr_key = new dra::key_human_dni(testSubject);
    
    std::cout << "Clave: " << ptr_key->value() << std::endl;
    
    delete ptr_key;
    
    return 0;
}