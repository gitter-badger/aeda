#ifndef _HUMAN_HPP_
#define _HUMAN_HPP_

#include <iostream>
#include <string>

namespace dra{
    class human;
    
    typedef std::string name_t;
    typedef std::string surname_t;
    typedef unsigned long dni_t;
    typedef unsigned long number_t;
}

class dra::human{
private:
    name_t name_;
    surname_t surname_;
    dni_t dni_;
    number_t number_;
public:
    dra::name_t& name(void);
    dra::name_t name(void) const;
    dra::surname_t& surname(void);
    dra::surname_t surname(void) const;
    dra::dni_t& dni(void);
    dra::dni_t dni(void) const;
    dra::number_t& number(void);
    dra::number_t number(void) const;
    
    std::ostream& toStream(std::ostream&);
};

dra::name_t& dra::human::name(void)
{
    return name_;
}

dra::name_t dra::human::name(void) const
{
    return name_;
}

dra::surname_t& dra::human::surname(void)
{
    return surname_;
}

dra::surname_t dra::human::surname(void) const
{
    return surname_;
}

dra::dni_t& dra::human::dni(void)
{
    return dni_;
}

dra::dni_t dra::human::dni(void) const
{
    return dni_;
}

dra::number_t& dra::human::number(void)
{
    return number_;
}

dra::number_t dra::human::number(void) const
{
    return number_;
}

std::ostream& dra::human::toStream(std::ostream& os)
{
    os << name_ << " " << surname_ << " (" << dni_ << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, dra::human person)
{
    person.toStream(os);
}

#endif