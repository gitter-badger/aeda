#ifndef _HASH_TABLE_HPP_
#define _HASH_TABLE_HPP_

#include <iostream>

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
    hash_index_t hash(dra::key*);
    
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
    if(table != nullptr)
        delete[] table;
    std::cout << "Destruyo la tabla" << std::endl;
}

void dra::hash_table::insert(dra::key* my_key)
{
    bool logic = table[0]->insert(my_key);
    std::cout << "Se pudo insertar? " << logic << std::endl;
}

std::ostream& dra::hash_table::toStream(std::ostream& os)
{
    for(int i = 0; i < bucket_n_; i++){
        std::cout << "Bucket " << i <<  ": " << std::endl;
        table[i]->toStream(std::cout);
    }
}

#endif