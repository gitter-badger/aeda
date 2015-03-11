#pragma once

#include "nodo.hpp"

#include <iostream>

using namespace std;

namespace AEDA
{
    template<class T>
    class nodo_t_temp_t: public nodo_t
    {
        private:
        T dato_;
        public:
        nodo_t_temp_t(const T& dato):
        nodo_t(),
        dato_(dato){}
        
        virtual nodo_t_temp_t(void)
        {}
        
        virtual ostream& toStream(ostream os)
        {
            os << dato_;
            return os;
        }
        
        T& get_dato(void)
        {
            return dato_;
        }
        T get_dato(void) const
        {
            return dato_;
        }
    };
}