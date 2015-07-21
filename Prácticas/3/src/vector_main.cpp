#include <iostream>

#include "vector.hpp"

using namespace std;

int main(void)
{
    dra::vector<int> myvec = {1,2,3,4,5};
    dra::vector<int> myvec2 = {6,7,8,9,10};
    
    cout << myvec << endl;
    cout << myvec2 << endl;
    
    
    cout << myvec << endl;
    cout << myvec2 << endl;
    
    
    return 0;
}