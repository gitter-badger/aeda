#ifndef _KEY_HPP_
#define _KEY_HPP_

#define UNINITIALIZED_KEY 65535
#define MIN_KEY_VALUE 0
#define MAX_KEY_VALUE 65534

#include "common.hpp"

namespace dra{
    class key;
    typedef unsigned key_t;
    typedef unsigned key_sz_t;
}

class dra::key{
protected:
    dra::key_sz_t sz_;
    dra::key_t key_;
public:
    key(dra::key_sz_t);
    virtual ~key(void);
    dra::key_t value(void) const;
    virtual void generate_key(void)=0;
};

dra::key::key(dra::key_sz_t sz):
sz_(sz),
key_(UNINITIALIZED_KEY)
{}

dra::key::~key(void)
{}

dra::key_t dra::key::value(void) const
{
    return key_;
}

#endif