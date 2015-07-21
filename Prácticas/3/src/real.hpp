#ifndef _real_HPP_
#define _real_HPP_

#include <iostream>
#include <cmath>

#include "number.hpp"
#include "exceptions.hpp"
//#include "debug.hpp"

#define REL_MIN_VAL -1.0e308
#define REL_MAX_VAL 1.0e308
#define REL_EPSILON 0.000001

namespace dra{
	typedef double real_t;
	class real;
}

class dra::real: public dra::number{
private:
    dra::real_t number_;
public:
    //================================== Constructores, destructores y operador=
    real(void);
    real(long double);
    real(const real&);
    real& operator=(const real&);
    ~real(void);
    //=================================================== Operadores artiméticos
    dra::real operator+(const dra::real& rel) const;
    dra::real operator-(const dra::real& rel) const;
    dra::real operator*(const dra::real& rel) const;
    dra::real operator/(const dra::real& rel) const;
    //==================================== Operadores de incremento y decremento
    void operator++(int);
    void operator--(int);
    //====================================== Operadores de asignación compuestos
    dra::real operator+=(const dra::real& rel);
    dra::real operator-=(const dra::real& rel);
    dra::real operator*=(const dra::real& rel);
    dra::real operator/=(const dra::real& rel);
    //================================================== Operadores relacionales
    bool operator==(const dra::real& rel) const;
	bool operator!=(const dra::real& rel) const;
	bool operator<(const dra::real& rel) const;
	bool operator>(const dra::real& rel) const;
	bool operator<=(const dra::real& rel) const;
	bool operator>=(const dra::real& rel) const;
	//======================================================= Conversión de tipo
	explicit operator dra::real_t();
    //====================================================================== E/S
    std::ostream& toStream(std::ostream& os) const;
    std::istream& fromStream(std::istream& is);
};

//==============================================================================
//====================================== Constructores, destructores y operador=
//==============================================================================
dra::real::real(void):
number_(0)
{}

dra::real::real(long double num):
number_(0)
{
    if(num < REL_MIN_VAL)
        throw exception::underflow_error("Exceeded 'REL_MIN_VAL'");
    if(num > REL_MAX_VAL)
        throw exception::overflow_error("Exceeded 'REL_MAX_VAL'");
    number_ = num;
}

dra::real::real(const real& rel)
{
    number_ = rel.number_; //Se podría poner *this=nat
}

dra::real& dra::real::operator=(const real& rel)
{
    number_ = rel.number_;
}

dra::real::~real(void)
{}

//==============================================================================
//======================================================= Operadores artiméticos
//==============================================================================
dra::real dra::real::operator+(const dra::real& rel) const
{
    if((number_ + rel.number_) > REL_MAX_VAL)
        throw exception::overflow_error("Exceeded 'REL_MAX_VAL' in operator '+'");
    return number_ + rel.number_;
}

dra::real dra::real::operator-(const dra::real& rel) const
{
    if((number_ - rel.number_) < REL_MIN_VAL)
        throw exception::underflow_error("Exceeded 'REL_MIN_VAL'");
    return number_ - rel.number_;
}

dra::real dra::real::operator*(const dra::real& rel) const
{
    if((number_ * rel.number_) > REL_MAX_VAL)
        throw exception::overflow_error("Exceeded 'REL_MAX_VAL' in operator '*'");
    return number_ * rel.number_;
}

dra::real dra::real::operator/(const dra::real& rel) const
{
    if(rel == 0)
        throw exception::overflow_error("Divide by zero in operator '/'");
    return number_ / rel.number_;
}

//==============================================================================
//======================================== Operadores de incremento y decremento
//==============================================================================
void dra::real::operator++(int)
{
    if((number_ + 1) > REL_MAX_VAL)
        throw exception::overflow_error("Exceeded 'REL_MAX_VAL' in operator '++'");
    number_++;
}

void dra::real::operator--(int)
{
    if((number_ -1) < REL_MIN_VAL)
        throw exception::underflow_error("Can't handle negative reals in operator '--'");
    number_--;
}

//==============================================================================
//========================================== Operadores de asignación compuestos
//==============================================================================
dra::real dra::real::operator+=(const dra::real& rel)
{
    if((number_ + rel.number_) > REL_MAX_VAL)
        throw exception::overflow_error("Exceeded 'REL_MAX_VAL' in operator '+='");
    return number_ += rel.number_;
}

dra::real dra::real::operator-=(const dra::real& rel)
{
    if((number_ - rel.number_) < REL_MIN_VAL)
        throw exception::underflow_error("Exceeded 'REL_MIN_VAL'");
    return number_ -= rel.number_;
}

dra::real dra::real::operator*=(const dra::real& rel)
{
    if((number_ * rel.number_) > REL_MAX_VAL)
        throw exception::overflow_error("Exceeded 'REL_MAX_VAL' in operator '*='");
    return number_ *= rel.number_;
}

dra::real dra::real::operator/=(const dra::real& rel)
{
    if(rel == 0)
        throw exception::overflow_error("Divide by zero in operator '/='");
    return number_ /= rel.number_;
}

//==============================================================================
//====================================================== Operadores relacionales
//==============================================================================
bool dra::real::operator==(const dra::real& rel) const
{
    return fabs(number_ - rel.number_) < REL_EPSILON;
}

bool dra::real::operator!=(const dra::real& rel) const
{
    return fabs(number_ - rel.number_) >= REL_EPSILON;
}

bool dra::real::operator<(const dra::real& rel) const
{
    return (number_ - rel.number_ < REL_EPSILON) && (fabs(number_-rel.number_) > REL_EPSILON);
}

bool dra::real::operator>(const dra::real& rel) const
{
    return (number_ - rel.number_ > REL_EPSILON) && (fabs(number_-rel.number_) > REL_EPSILON);
}

bool dra::real::operator<=(const dra::real& rel) const
{
    return (*this < rel) || (*this == rel);
}

bool dra::real::operator>=(const dra::real& rel) const
{
    return (*this > rel) || (*this == rel);
}

//==============================================================================
//=========================================================== Conversión de tipo
//==============================================================================
dra::real::operator dra::real_t()
{
    return number_;
}

//==============================================================================
//========================================================================== E/S
//==============================================================================
std::ostream& dra::real::toStream(std::ostream& os) const
{
    os << number_;
    return os;
}

std::istream& dra::real::fromStream(std::istream& is)
{
    is >> number_;
    return is;
}

std::ostream& operator<<(std::ostream& os, dra::real rel)
{
    rel.toStream(os);
    return os;
}

std::istream& operator>>(std::istream& is, dra::real rel)
{
    rel.fromStream(is);
    return is;
}

#endif