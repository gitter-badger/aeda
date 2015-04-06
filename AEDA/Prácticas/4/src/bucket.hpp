#ifndef _BUCKET_HPP_
#define _BUCKET_HPP_

#include "common.hpp"
#include "key.hpp"

template<class T>
class dra::bucket{
private:
    T dummy;
public:
    bucket(bucket_n_t);
    bool search(key<T> x);
    bool insert(key<T> x);
};

#endif