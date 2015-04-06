#ifndef _KEY_HPP_
#define _KEY_HPP_

#define UNINITIALIZED_KEY 65535
#define MIN_KEY_VALUE 0
#define MAX_KEY_VALUE 65534

#include "common.hpp"

namespace dra{
    class key;
    typedef unsigned long key_t;
}

class dra::key{
protected:
    dra::key_t key_;
public:
    key(void);
    virtual ~key(void);
    dra::key_t value(void) const;
    virtual void generate_key(void)=0;
};

dra::key::key(void):
key_(UNINITIALIZED_KEY)
{}

dra::key::~key(void)
{}

dra::key_t dra::key::value(void) const
{
    return key_;
}

#endif