#pragma once

#include "nodo_temp.hpp"
#include "lista.hpp"


#include <iostream>

using namespace std;

namespace AEDA
{
    template<class T>
    class stack_t{
    private:
        lista_t lista_;
    public:
        virtual ~stack_t(void);
        void push(const T& dato)
        {
            nodo_t_temp_t<T>* aux = new nodo_t_temp_t<T>(dato);
            lista_.insert_first(aux);
        }
        T pop(void)
        {
            nodo_t_temp_t<T>* aux = lista_.extract_first();
            T dato(aux->get_dato());
            delete aux;
            return dato;
        }
        bool empty(void)
        {
            return lista_.empty();
        }
        
    }
}