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
    
    dra::queue<int> myqueue3 = {1,5,3,6,4,2,1};
    TRACE(myqueue3.size());
    
    myqueue3 = myqueue2;
    TRACE(myqueue3.size());
    
    cout << myqueue3 << endl;
    
    TRACE(myqueue3.front());
    TRACE(myqueue3.rear());
    
    return 0;
}