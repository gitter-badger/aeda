
#include <iostream>
#include "hash_table.hpp"
#include "human.hpp"
#include "key_human.hpp"
#include "key_human_dni.hpp"


int main(void)
{
    dra::hash_table test(20, 10, 1, 1);
    
    dra::human* testSubject = new dra::human;
    
    testSubject->name() = "Cave";
    testSubject->surname() = "Johnson";
    testSubject->dni() = 47905505;
    testSubject->number() = 4258899642;
    
    
    dra::key_human_dni* ptr= new dra::key_human_dni(testSubject);
    
    test.insert(ptr);
    
    test.toStream(std::cout);
    
    std::cout << "Vamos bien" << std::endl;
}