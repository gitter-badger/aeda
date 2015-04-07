#ifndef _HASH_TABLE_HPP_
#define _HASH_TABLE_HPP_

#include <iostream>
#include <time.h>

#include "common.hpp"
#include "bucket.hpp"
#include "key.hpp"
#include <cstdlib>
#include <unistd.h>

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
    void insert(dra::key*); // test de comentario para el atom

    dra::hash_index_t hash(dra::key*);
    dra::hash_index_t hash_module(dra::key*);
    dra::hash_index_t hash_plus(dra::key*);
    dra::hash_index_t hash_pseudo_random(dra::key*);

    dra::hash_index_t probe(dra::key*, unsigned);
    dra::hash_index_t linear_probing(dra::key*, unsigned);
    dra::hash_index_t quadratic_probing(dra::key*, unsigned);
    dra::hash_index_t double_hashing_probing(dra::key*, unsigned);
    dra::hash_index_t re_hashing_probing(dra::key*, unsigned);

    std::ostream& toStream(std::ostream& os);
};

dra::hash_table::hash_table(dra::bucket_n_t bucket_n, dra::cells_n_t cells_n, dra::hash_m_t hash_m, dra::probe_m_t probe_m):
bucket_n_(bucket_n),
cells_n_(cells_n),
hash_m_(hash_m),
probe_m_(probe_m)
{
    table = new bucket*[bucket_n_];
    for(int i = 0; i < bucket_n_; i++)
        table[i] = new bucket(cells_n_);
}

dra::hash_table::~hash_table(void)
{
    for(int i = 0; i < bucket_n_; i++)
        if(table[i] != nullptr)
            delete table[i];
    if(table != nullptr)
        delete[] table;
}

void dra::hash_table::insert(dra::key* my_key)
{
    if(!table[hash(my_key)]->insert(my_key)){
        std::cout << "No se ha podido insertar la clave " << my_key->value() << " en el bucket "  << hash(my_key) << std::endl;
        std::cout << "Comenzando tecnica de exploracion." << std::endl;
        int i = 0;
        while(1){
            hash_index_t new_bucket = probe(my_key, i);
            std::cout << "Vamos a ver si esta en el bucket " << new_bucket << std::endl;
            if(table[new_bucket]->search(nullptr)){
                std::cout << "Se ha encontrado una celda candidata, insertando" << std::endl;
                table[new_bucket]->insert(my_key);
                break;
            }
            else
                i++;
        }
    }
    else{
        std::cout << "Se ha insertado la clave " << my_key->value() << " en el bucket " << hash(my_key) << std::endl;
    }
}

dra::hash_index_t dra::hash_table::hash(dra::key* my_key)
{
    switch(hash_m_){
        case 1: return hash_module(my_key);
        case 2: return hash_plus(my_key);
        case 3: return hash_pseudo_random(my_key);
        default: std::cerr << "Bad hash code" << std::endl; exit(1);
    }
}

dra::hash_index_t dra::hash_table::hash_module(dra::key* my_key)
{
    std::cout << "Hasheando con modulo" << std::endl;
    return my_key->value() % bucket_n_;
}

dra::hash_index_t dra::hash_table::hash_plus(dra::key* my_key)
{
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

dra::hash_index_t dra::hash_table::probe(dra::key* my_key, unsigned i)
{
    switch(probe_m_){
        case 1: return linear_probing(my_key, i);
        case 2: return quadratic_probing(my_key, i);
        case 3: return double_hashing_probing(my_key, i);
        case 4: return re_hashing_probing(my_key, i);
    }
}

dra::hash_index_t dra::hash_table::linear_probing(dra::key* my_key, unsigned i)
{
    return (hash(my_key)+i) % bucket_n_;
}

dra::hash_index_t dra::hash_table::quadratic_probing(dra::key* my_key, unsigned i)
{
    return (hash(my_key)+(i*i)) % bucket_n_;
}

dra::hash_index_t dra::hash_table::double_hashing_probing(dra::key* my_key, unsigned i)
{
    std::cout << "Valor de la i = " << i << std::endl;
    hash_index_t aux = (hash(my_key) + i*hash_pseudo_random(my_key)) % bucket_n_;

    std::cout << "Valor del double_hashing_probing = " << aux << std::endl;

    sleep(1);

    return aux;
}

dra::hash_index_t dra::hash_table::re_hashing_probing(dra::key*, unsigned i)
{
    return (i) %  bucket_n_;
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
