#ifndef DNI
#define DNI

#include "random.h"

namespace dra
{

class dni{
private:
    unsigned long dni_;
public:
    dni(void);
    dni(unsigned long dni);
    ~dni(void);

    unsigned long& value(void);
    unsigned long value(void) const;
    
    bool operator==(const dni scd) const;
    bool operator!=(const dni scd) const;
    bool operator<(const dni scd) const;
    bool operator>(const dni scd) const;
    bool operator<=(const dni scd) const;
    bool operator>=(const dni scd) const;
    
    std::ostream& toStream(std::ostream& os) const;
};

dni::dni()
{
    srand(dra::rand());
    dni_ = rand() % 50000000 +30000000;
}

dni::dni(unsigned long int dni):
    dni_(dni)
{}

dni::~dni()
{}

unsigned long& dni::value()
{
    return dni_;
}

unsigned long dni::value() const
{
    return dni_;
}

bool dni::operator==(const dni scd) const
{
    return dni_ == scd.dni_;
}

bool dni::operator!=(const dni scd) const
{
    return dni_ != scd.dni_;
}

bool dni::operator<(const dni scd) const
{
    return dni_ < scd.dni_;
}

bool dni::operator>(const dni scd) const
{
    return dni_ > scd.dni_;
}

bool dni::operator<=(const dni scd) const
{
    return dni_ <= scd.dni_;
}

bool dni::operator>=(const dni scd) const
{
    return dni_ >= scd.dni_;
}

std::ostream& dni::toStream(std::ostream& os) const
{
    os << dni_;
    return os;
}

}

std::ostream& operator<<(std::ostream& os, dra::dni scd)
{
	scd.toStream(os);
	return os;
}

#endif // DNI

