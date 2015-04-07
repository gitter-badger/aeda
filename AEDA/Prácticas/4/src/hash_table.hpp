#ifndef _HASH_TABLE_HPP_
#define _HASH_TABLE_HPP_

#include <iostream>
#include <time.h>

#include "common.hpp"
#include "bucket.hpp"
#include "key.hpp"

class dra::hash_table{
private:
    dra::cells_n_t cells_n_;
    dra::bucket_n_t bucket_n_;
    dra::hash_m_t hash_m_;
    dra::explore_m_t explore_m_;
    
    dra::bucket** table;
public:
    hash_table(dra::cells_n_t, dra::bucket_n_t, dra::hash_m_t, dra::explore_m_t);
    ~hash_table(void);
    void insert(dra::key*);
    
    dra::hash_index_t hash(dra::key*);
    dra::hash_index_t hash_module(dra::key*);
    dra::hash_index_t hash_plus(dra::key*);
    dra::hash_index_t hash_pseudo_random(dra::key*);
    
    std::ostream& toStream(std::ostream& os);
};

dra::hash_table::hash_table(dra::bucket_n_t bucket_n, dra::cells_n_t cells_n, dra::hash_m_t hash_m, dra::explore_m_t explore_m):
bucket_n_(bucket_n),
cells_n_(cells_n),
hash_m_(hash_m),
explore_m_(explore_m)
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
    bool inserted = false;
    
    while(!inserted){
        inserted = table[hash(my_key)]->insert(my_key);
    }
    
    
    std::cout << "Se pudo insertar? " << inserted << std::endl;
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


std::ostream& dra::hash_table::toStream(std::ostream& os)
{
    for(int i = 0; i < bucket_n_; i++){
        std::cout << "Bucket " << i+1 <<  ": " << std::endl;
        table[i]->toStream(std::cout);
    }
}

std::ostream& operator<<(std::ostream& os, dra::hash_table& table)
{
    table.toStream(os);
    return os;
}

#endif