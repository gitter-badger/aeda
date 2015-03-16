#ifndef _NUMBER_HPP_
#define _NUMBER_HPP_

#include <iostream>

namespace dra{
    class number;
}

class dra::number{
protected:
    virtual std::ostream& toStream(std::ostream& os) const=0;
    virtual std::istream& fromStream(std::istream& is)=0;
};

#endif