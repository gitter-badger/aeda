#ifndef _HASH_TABLE_HPP_
#define _HASH_TABLE_HPP_

#include <iostream>
#include <time.h>

#include "common.hpp"
#include "bucket.hpp"
#include "key.hpp"
#include <cstdlib>

class dra::hash_table{
private:
    dra::cells_n_t cells_n_;
    dra::bucket_n_t bucket_n_;
    dra::hash_m_t hash_m_;
    dra::probe_m_t probe_m_;
    
    dra::bucket** table;
public:
    hash_table(dra::cells_n_t, dra::bucket_n_t, dra::hash_m_t, dra::probe_m_t);
    ~hash_table(void);
    void insert(dra::key*);
    
    dra::hash_index_t hash(dra::key*);
    dra::hash_index_t hash_module(dra::key*);
    dra::hash_index_t hash_plus(dra::key*);
    dra::hash_index_t hash_pseudo_random(dra::key*);
    
    dra::hash_index_t probe(dra::key*, dra::hash_index_t);
    dra::hash_index_t linear_probing(dra::key*, dra::hash_index_t);
    dra::hash_index_t quadratic_probing(dra::key*, dra::hash_index_t);
    dra::hash_index_t double_hashing_probing(dra::key*, dra::hash_index_t);
    dra::hash_index_t re_hashing_probing(dra::key*, dra::hash_index_t);
    
    std::ostream& toStream(std::ostream& os);
};

dra::hash_table::hash_table(dra::bucket_n_t bucket_n, dra::cells_n_t cells_n, dra::hash_m_t hash_m, dra::probe_m_t probe_m):
bucket_n_(bucket_n),
cells_n_(cells_n),
hash_m_(hash_m),
probe_m_(probe_m)
{
    std::cout << "Voy a construir una tabla de punteros a bucket, " << bucket_n_ << ", y cada uno de tamano "  << cells_n_ << std::endl;
    table = new bucket*[bucket_n_];
    for(int i = 0; i < bucket_n_; i++){
        std::cout << "Entro en el for para declarar los buckets, #" << i+1 << std::endl;
        table[i] = new bucket(cells_n_);
    }
}

dra::hash_table::~hash_table(void)
{
    for(int i = 0; i < bucket_n_; i++)
        if(table[i] != nullptr)
            delete table[i];
    if(table != nullptr)
        delete[] table;
    std::cout << "Destruyo la tabla" << std::endl;
}

void dra::hash_table::insert(dra::key* my_key)
{
    dra::key* aux = nullptr;
    table[probe(aux, hash(my_key))]->insert(my_key);
}

dra::hash_index_t dra::hash_table::hash(dra::key* my_key)
{
    switch(hash_m_){
        case 1: return hash_module(my_key);
        case 2: return hash_plus(my_key);
        case 3: return hash_pseudo_random(my_key);
        default: break;
    }
}

dra::hash_index_t dra::hash_table::hash_module(dra::key* my_key)
{
    std::cout << "Hasheando con modulo" << std::endl;
    return my_key->value() % bucket_n_;
}

dra::hash_index_t dra::hash_table::hash_plus(dra::key* my_key)
{
    std::cout << "Hasheando con suma" << std::endl;
    int aux = my_key->value();
    int sum = 0;
    while (aux != 0)
   {
        int remainder = aux % 10;
        sum += remainder;
        aux = aux / 10;
   }
   return sum % bucket_n_;
}

dra::hash_index_t dra::hash_table::hash_pseudo_random(dra::key* my_key)
{
    srand(my_key->value());
    return rand() % bucket_n_;
}

dra::hash_index_t dra::hash_table::probe(dra::key* my_key, dra::hash_index_t index)
{
    switch(probe_m_){
        case 1: return linear_probing(my_key, index);
        case 2: break;
        case 3: break;
        case 4: break;
    }
}

dra::hash_index_t dra::hash_table::linear_probing(dra::key* my_key, dra::hash_index_t index)
{
    if(my_key == nullptr){
        std::cout << "Voy a buscar una clave vacia en " << index << std::endl;
    }
    else{
        std::cout << "Voy a buscar la clave " << my_key->value() << " en " << index << std::endl;
    }
    
    dra::hash_index_t eindex = index;
    while(1)
    {
        std::cout << "Vamos a ver si esta en " << eindex << std::endl;
        if(table[index]->search(my_key))
            return eindex;
        else{
            std::cout << "No se encontro la clave en el bucket " << eindex << ", asi que pruebo en el ";
            index++;
            eindex = index % bucket_n_;
            std::cout << eindex << std::endl;
        }
    }
}

dra::hash_index_t dra::hash_table::quadratic_probing(dra::key* my_key, hash_index_t index)
{
    
}

dra::hash_index_t dra::hash_table::double_hashing_probing(dra::key* my_key, hash_index_t index)
{
    
}

dra::hash_index_t dra::hash_table::re_hashing_probing(dra::key*, dra::hash_index_t index)
{
    
}

std::ostream& dra::hash_table::toStream(std::ostream& os)
{
    for(int i = 0; i < bucket_n_; i++){
        std::cout << "Bucket " << i <<  ": " << std::endl;
        table[i]->toStream(std::cout);
    }
}

std::ostream& operator<<(std::ostream& os, dra::hash_table& table)
{
    table.toStream(os);
    return os;
}

#endif