#include "nodo_temp.hpp"
#include "lista.hpp"

#include <iostream>

using namespace std;

int main(void)
{
    AEDA::list_t lista;
    
    for(int i = 0; i < 10; i++){
        AEDA::nodo_t_temp_t<int>* aux; = new AEDA::nodo_t_temp_t<int>(i);
        lista.insert_first(aux);
    }
    lista.toStream(cout);
}