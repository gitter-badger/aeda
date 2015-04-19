#ifndef _KEY_HUMAN_DNI_HPP_
#define _KEY_HUMAN_DNI_HPP_


#include "key.hpp"
#include "human.hpp"
#include "key_human.hpp"

namespace dra{
    class key_human_dni;
}

class dra::key_human_dni:public dra::key_human{
public:
    key_human_dni(dra::human*);
    virtual ~key_human_dni(void);
    virtual void generate_key(void);
};

dra::key_human_dni::key_human_dni(dra::human* ptr):
key_human(ptr)
{
    generate_key();
}

dra::key_human_dni::~key_human_dni(void)
{}

void dra::key_human_dni::generate_key(void)
{
    key_ = human_ptr_->dni();
}

#endif
