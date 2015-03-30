#ifndef _HASH_TABLE_HPP_
#define _HASH_TABLE_HPP_

#include "common.hpp"
#include "bucket.hpp"

namespace dra{
    template<class T> class hash_table;
}

template<class T>
class dra::hash_table{
private:
    T* table;
public:
    hash_table(cells_n, bucket_n, hash_mode, explore_mode);
};

#endif