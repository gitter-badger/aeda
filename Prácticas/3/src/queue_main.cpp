#include <iostream>

#include "queue.hpp"

using namespace std;

int main(void)
{
    dra::queue<int> myqueue0;
    TRACE(myqueue0.size());
    
    dra::queue<int> myqueue1(5);
    TRACE(myqueue1.size());
    
    dra::queue<int> myqueue2(myqueue1);
    TRACE(myqueue2.size());
    
    dra::queue<int> myqueue3 = {66,5,3,6,4,2,99};
    TRACE(myqueue3.size());
    
    SAY("llego");
    
    cout << myqueue3 << endl;
    
    SAY("Voy a hacer el front");
    TRACE(myqueue3.front());
    SAY("Voy a hacer el rear");
    TRACE(myqueue3.rear());
    SAY("llego");
    
    return 0;
}