#include "vector.hpp"
#include "simplelinkedlist.hpp"
#include "stack.hpp"
#include "queue.hpp"
#include "natural.hpp"
#include "integer.hpp"
#include "rational.hpp"
#include "real.hpp"
#include "complex.hpp"

int main(void)
{
    dra::stack<dra::number*> test;
    
    dra::number* ptr1 = new dra::natural(4);
    dra::number* ptr2 = new dra::integer(-5);
    dra::number* ptr3 = new dra::rational(4,9);
    dra::number* ptr4 = new dra::real(9.124);
    dra::number* ptr5 = new dra::complex(2.423, 13.1234);
    
    
    test.push(ptr1);
    test.push(ptr2);
    test.push(ptr3);
    test.push(ptr4);
    test.push(ptr5);
    
    
    
    while(!test.empty()){
        ptr1 = test.top();
        test.pop();
        std::cout << *ptr1 << std::endl;
    }
}