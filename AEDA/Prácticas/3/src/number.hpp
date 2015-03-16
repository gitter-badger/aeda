#ifndef _NUMBER_HPP_
#define _NUMBER_HPP_

#include <iostream>

namespace dra{
    class number;
}

class dra::number{
public:
    virtual std::ostream& toStream(std::ostream& os) const=0;
    virtual std::istream& fromStream(std::istream& is)=0;
};

std::ostream& operator<<(std::ostream& os, const dra::number& num)
{
    num.toStream(os);
    return os;
}

std::istream& operator>>(std::istream& is, dra::number& num)
{
    num.fromStream(is);
    return is;
}

#endif