#ifndef _HASH_TABLE_HPP_
#define _HASH_TABLE_HPP_

#include "common.hpp"
#include "bucket.hpp"

template<class T>
class dra::hash_table{
private:
    T* table;
public:
    hash_table(dra::cells_n_t, dra::bucket_n_t, dra::hash_m_t, dra::explore_m_t);
    hash_index_t hash(dra::key*);
};

#endif