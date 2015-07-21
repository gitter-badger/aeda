#pragma once

#include <cstdio>
#include <iostream>

using namespace std;

namespace AEDA
{
    class nodo_t{
    private:
        nodo_t* next_;
    public:
        nodo_t(void):
        next_(nullptr){}
        
        virtual ~nodo_t(void){}
        
        nodo_t* get_next(void)
        {
            return next_;
        }
        
        void set_next(nodo_t* next)
        {
            next_ = next;
        }
        
        virtual ostream& toStream(ostream& os)=0;
    };
}