#include <iostream>

#include "natural.hpp"

int main(void)
{
    dra::natural test(4294967195);
    
    while(1){
        try{
            test++;
        }
        catch(...)
        {
            std::cerr << "Te pasaste de vueltas wey" << std::endl;
            break;
        }
    }
    
    test = 100;
    
    while(1){
        try{
            test--;
        }
        catch(...)
        {
            std::cerr << "Te pasaste de menos vueltas wey" << std::endl;
            break;
        }
    }

    
    return 0;
}

