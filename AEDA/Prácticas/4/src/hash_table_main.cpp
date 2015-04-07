
#include <iostream>
#include <time.h>
#include "hash_table.hpp"
#include "human.hpp"
#include "key_human.hpp"
#include "key_human_dni.hpp"


int main(void)
{
    
    
    
    dra::hash_table test(10, 2, 1, 3);
    
    dra::human* testSubject;
    
    srand(time(NULL));
    
    for(int i = 0; i < 10; i++){
        
        testSubject = new dra::human;
    
        testSubject->name() = "Cave";
        testSubject->surname() = "Johnson";
        testSubject->dni() = rand() % 50000000 +30000000;
        testSubject->number() = 4258899642;
    
        dra::key_human_dni* ptr= new dra::key_human_dni(testSubject);
    
        test.insert(ptr);
        
        srand(testSubject->dni());
    }
    
    std::cout << test << std::endl;
    
    std::cout << "Vamos bien" << std::endl;
}