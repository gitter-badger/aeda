#ifndef _KEY_HUMAN_HPP_
#define _KEY_HUMAN_HPP_

#include "common.hpp"
#include "key.hpp"
#include "human.hpp"

namespace dra{
    class key_human;
}

class dra::key_human:public dra::key{
protected:
    dra::human* human_ptr_;
public:
    key_human(void);
    key_human(dra::human*);
    virtual ~key_human(void);
};

dra::key_human::key_human(void):
human_ptr_(nullptr)
{}

dra::key_human::key_human(dra::human* ptr):
human_ptr_(ptr)
{}

dra::key_human::~key_human(void)
{
    if(human_ptr_ != nullptr)
        delete human_ptr_;
}

#endif