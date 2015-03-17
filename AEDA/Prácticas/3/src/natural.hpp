#ifndef _NATURAL_HPP_
#define _NATURAL_HPP_

#include <iostream>

#include "number.hpp"
#include "exceptions.hpp"
//#include "debug.hpp"

#define NAT_MIN_VAL 0
#define NAT_MAX_VAL 4294967295

namespace dra{
	typedef long unsigned int natural_t;
	class natural;
}

class dra::natural: public dra::number{
private:
    dra::natural_t number_;
public:
    //================================== Constructores, destructores y operador=
    natural(void);
    natural(long long int);
    natural(const natural&);
    natural& operator=(const natural&);
    ~natural(void);
    //=================================================== Operadores artiméticos
    dra::natural operator+(const dra::natural& nat) const;
    dra::natural operator-(const dra::natural& nat) const;
    dra::natural operator*(const dra::natural& nat) const;
    dra::natural operator/(const dra::natural& nat) const;
    dra::natural operator%(const dra::natural& nat) const;
    //==================================== Operadores de incremento y decremento
    void operator++(int);
    void operator--(int);
    //====================================== Operadores de asignación compuestos
    dra::natural operator+=(const dra::natural& nat);
    dra::natural operator-=(const dra::natural& nat);
    dra::natural operator*=(const dra::natural& nat);
    dra::natural operator/=(const dra::natural& nat);
    dra::natural operator%=(const dra::natural& nat);
    //======================================================= Operadores lógicos
    bool operator!(void) const;
    bool operator&&(const dra::natural& nat) const;
    bool operator||(const dra::natural& nat) const;
    //================================================== Operadores relacionales
    bool operator==(const dra::natural& nat) const;
	bool operator!=(const dra::natural& nat) const;
	bool operator<(const dra::natural& nat) const;
	bool operator>(const dra::natural& nat) const;
	bool operator<=(const dra::natural& nat) const;
	bool operator>=(const dra::natural& nat) const;
	//======================================================= Conversión de tipo
	explicit operator dra::natural_t();
    //====================================================================== E/S
    std::ostream& toStream(std::ostream& os) const;
    std::istream& fromStream(std::istream& is);
};

//==============================================================================
//====================================== Constructores, destructores y operador=
//==============================================================================
dra::natural::natural(void):
number_(0)
{}

dra::natural::natural(long long int num):
number_(0)
{
    if(num < NAT_MIN_VAL)
        throw exception::underflow_error("Can't handle negative naturals");
    if(num > NAT_MAX_VAL)
        throw exception::overflow_error("Exceeded 'NAT_MAX_VAL'");
    number_ = num;
}

dra::natural::natural(const natural& nat)
{
    number_ = nat.number_; //Se podría poner *this=nat
}

dra::natural& dra::natural::operator=(const natural& nat)
{
    number_ = nat.number_;
}

dra::natural::~natural(void)
{}

//==============================================================================
//======================================================= Operadores artiméticos
//==============================================================================
dra::natural dra::natural::operator+(const dra::natural& nat) const
{
    if((number_ + nat.number_) > NAT_MAX_VAL)
        throw exception::overflow_error("Exceeded 'NAT_MAX_VAL' in operator '+'");
    return number_ + nat.number_;
}

dra::natural dra::natural::operator-(const dra::natural& nat) const
{
    if((number_ - nat.number_) > number_)
        throw exception::underflow_error("Can't handle negative naturals in operator '-'");
    return number_ - nat.number_;
}

dra::natural dra::natural::operator*(const dra::natural& nat) const
{
    if((number_ * nat.number_) > NAT_MAX_VAL)
        throw exception::overflow_error("Exceeded 'NAT_MAX_VAL' in operator '*'");
    return number_ * nat.number_;
}

dra::natural dra::natural::operator/(const dra::natural& nat) const
{
    if(nat == 0)
        throw exception::overflow_error("Divide by zero in operator '/'");
    return number_ / nat.number_;
}

dra::natural dra::natural::operator%(const dra::natural& nat) const
{
    if(nat == 0)
        throw exception::overflow_error("Divide by zero in operator '%'");
    return number_ % nat.number_;
}

//==============================================================================
//======================================== Operadores de incremento y decremento
//==============================================================================
void dra::natural::operator++(int)
{
    if((number_ + 1) > NAT_MAX_VAL)
        throw exception::overflow_error("Exceeded 'NAT_MAX_VAL' in operator '++'");
    number_++;
}

void dra::natural::operator--(int)
{
    if((number_ -1) > number_)
        throw exception::underflow_error("Can't handle negative naturals in operator '--'");
    number_--;
}
//==============================================================================
//========================================== Operadores de asignación compuestos
//==============================================================================
dra::natural dra::natural::operator+=(const dra::natural& nat)
{
    if((number_ + nat.number_) > NAT_MAX_VAL)
        throw exception::overflow_error("Exceeded 'NAT_MAX_VAL' in operator '+='");
    return number_ += nat.number_;
}

dra::natural dra::natural::operator-=(const dra::natural& nat)
{
    if((number_ - nat.number_) > number_)
        throw exception::underflow_error("Can't handle negative naturals in operator '-='");
    return number_ -= nat.number_;
}

dra::natural dra::natural::operator*=(const dra::natural& nat)
{
    if((number_ * nat.number_) > NAT_MAX_VAL)
        throw exception::overflow_error("Exceeded 'NAT_MAX_VAL' in operator '*='");
    return number_ *= nat.number_;
}

dra::natural dra::natural::operator/=(const dra::natural& nat)
{
    if(nat == 0)
        throw exception::overflow_error("Divide by zero in operator '/='");
    return number_ /= nat.number_;
}

dra::natural dra::natural::operator%=(const dra::natural& nat)
{
    if(nat == 0)
        throw exception::overflow_error("Divide by zero in operator '%='");
    return number_ %= nat.number_;
}
//==============================================================================
//=========================================================== Operadores lógicos
//==============================================================================
bool dra::natural::operator!(void) const
{
    return !number_;
}

bool dra::natural::operator&&(const dra::natural& nat) const
{
    return number_ && nat.number_;
}

bool dra::natural::operator||(const dra::natural& nat) const
{
    return number_ || nat.number_;
}

//==============================================================================
//====================================================== Operadores relacionales
//==============================================================================
bool dra::natural::operator==(const dra::natural& nat) const
{
    return number_ == nat.number_;
}

bool dra::natural::operator!=(const dra::natural& nat) const
{
    return number_ != nat.number_;
}

bool dra::natural::operator<(const dra::natural& nat) const
{
    return number_ < nat.number_;
}

bool dra::natural::operator>(const dra::natural& nat) const
{
    return number_ > nat.number_;
}

bool dra::natural::operator<=(const dra::natural& nat) const
{
    return number_ <= nat.number_;
}

bool dra::natural::operator>=(const dra::natural& nat) const
{
    return number_ >= nat.number_;
}

//==============================================================================
//=========================================================== Conversión de tipo
//==============================================================================
dra::natural::operator dra::natural_t()
{
    return number_;
}

//==============================================================================
//========================================================================== E/S
//==============================================================================
std::ostream& dra::natural::toStream(std::ostream& os) const
{
    os << number_;
    return os;
}

std::istream& dra::natural::fromStream(std::istream& is)
{
    is >> number_;
    return is;
}

std::ostream& operator<<(std::ostream& os, dra::natural nat)
{
    nat.toStream(os);
    return os;
}

std::istream& operator>>(std::istream& is, dra::natural nat)
{
    nat.fromStream(is);
    return is;
}

#endif