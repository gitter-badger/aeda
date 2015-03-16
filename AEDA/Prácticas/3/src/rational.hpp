#ifndef _rational_HPP_
#define _rational_HPP_

#include <iostream>

#include "number.hpp"
#include "integer.hpp"
#include "exceptions.hpp"
#include "debug.hpp"

#define MIN_VAL -2147483647
#define MAX_VAL 2147483647 

namespace dra{
	typedef dra::integer number_t; //no funca
	class rational;
}

class dra::rational: public dra::number{
private:
    dra::number_t number_; //aqui esta mal
public:
    //================================== Constructores, destructores y operador=
    rational(void);
    rational(long long int);
    rational(const rational&);
    rational& operator=(const rational&);
    ~rational(void);
    //=================================================== Operadores artiméticos
    dra::rational operator+(const dra::rational& nat) const;
    dra::rational operator-(const dra::rational& nat) const;
    dra::rational operator*(const dra::rational& nat) const;
    dra::rational operator/(const dra::rational& nat) const;
    dra::rational operator%(const dra::rational& nat) const;
    //==================================== Operadores de incremento y decremento
    void operator++(int);
    void operator--(int);
    //====================================== Operadores de asignación compuestos
    dra::rational operator+=(const dra::rational& nat);
    dra::rational operator-=(const dra::rational& nat);
    dra::rational operator*=(const dra::rational& nat);
    dra::rational operator/=(const dra::rational& nat);
    dra::rational operator%=(const dra::rational& nat);
    //======================================================= Operadores lógicos
    bool operator!(void) const;
    bool operator&&(const dra::rational& nat) const;
    bool operator||(const dra::rational& nat) const;
    //================================================== Operadores relacionales
    bool operator==(const dra::rational& nat) const;
	bool operator!=(const dra::rational& nat) const;
	bool operator<(const dra::rational& nat) const;
	bool operator>(const dra::rational& nat) const;
	bool operator<=(const dra::rational& nat) const;
	bool operator>=(const dra::rational& nat) const;
    //====================================================================== E/S
    std::ostream& toStream(std::ostream& os) const;
    std::istream& fromStream(std::istream& is);
};

//==============================================================================
//====================================== Constructores, destructores y operador=
//==============================================================================
dra::rational::rational(void):
number_(0)
{}

dra::rational::rational(long long int num):
number_(0)
{
    if(num < MIN_VAL)
        throw exception::underflow_error("Exceeded 'MIN_VAL'");
    if(num > MAX_VAL)
        throw exception::overflow_error("Exceeded 'MAX_VAL'");
    number_ = num;
}

dra::rational::rational(const rational& nat)
{
    number_ = nat.number_; //Se podría poner *this=nat
}

dra::rational& dra::rational::operator=(const rational& nat)
{
    number_ = nat.number_;
}

dra::rational::~rational(void)
{}

//==============================================================================
//======================================================= Operadores artiméticos
//==============================================================================
dra::rational dra::rational::operator+(const dra::rational& nat) const
{
    if((number_ + nat.number_) > MAX_VAL)
        throw exception::overflow_error("Exceeded 'MAX_VAL' in operator '+'");
    return number_ + nat.number_;
}

dra::rational dra::rational::operator-(const dra::rational& nat) const
{
    if((number_ - nat.number_) > number_)
        throw exception::underflow_error("Exceeded 'MIN_VAL'");
    return number_ - nat.number_;
}

dra::rational dra::rational::operator*(const dra::rational& nat) const
{
    if((number_ * nat.number_) > MAX_VAL)
        throw exception::overflow_error("Exceeded 'MAX_VAL' in operator '*'");
    return number_ * nat.number_;
}

dra::rational dra::rational::operator/(const dra::rational& nat) const
{
    if(nat == 0)
        throw exception::overflow_error("Divide by zero in operator '/'");
    return number_ / nat.number_;
}

dra::rational dra::rational::operator%(const dra::rational& nat) const
{
    if(nat == 0)
        throw exception::overflow_error("Divide by zero in operator '%'");
    return number_ % nat.number_;
}

//==============================================================================
//======================================== Operadores de incremento y decremento
//==============================================================================
void dra::rational::operator++(int)
{
    if((number_ + 1) > MAX_VAL)
        throw exception::overflow_error("Exceeded 'MAX_VAL' in operator '++'");
    number_++;
}

void dra::rational::operator--(int)
{
    if((number_ -1) > number_)
        throw exception::underflow_error("Can't handle negative rationals in operator '--'");
    number_--;
}
//==============================================================================
//========================================== Operadores de asignación compuestos
//==============================================================================
dra::rational dra::rational::operator+=(const dra::rational& nat)
{
    if((number_ + nat.number_) > MAX_VAL)
        throw exception::overflow_error("Exceeded 'MAX_VAL' in operator '+='");
    return number_ += nat.number_;
}

dra::rational dra::rational::operator-=(const dra::rational& nat)
{
    if((number_ - nat.number_) > number_)
        throw exception::underflow_error("Exceeded 'MIN_VAL'");
    return number_ -= nat.number_;
}

dra::rational dra::rational::operator*=(const dra::rational& nat)
{
    if((number_ * nat.number_) > MAX_VAL)
        throw exception::overflow_error("Exceeded 'MAX_VAL' in operator '*='");
    return number_ *= nat.number_;
}

dra::rational dra::rational::operator/=(const dra::rational& nat)
{
    if(nat == 0)
        throw exception::overflow_error("Divide by zero in operator '/='");
    return number_ /= nat.number_;
}

dra::rational dra::rational::operator%=(const dra::rational& nat)
{
    if(nat == 0)
        throw exception::overflow_error("Divide by zero in operator '%='");
    return number_ %= nat.number_;
}
//==============================================================================
//=========================================================== Operadores lógicos
//==============================================================================
bool dra::rational::operator!(void) const
{
    return !number_;
}

bool dra::rational::operator&&(const dra::rational& nat) const
{
    return number_ && nat.number_;
}

bool dra::rational::operator||(const dra::rational& nat) const
{
    return number_ || nat.number_;
}

//==============================================================================
//====================================================== Operadores relacionales
//==============================================================================
bool dra::rational::operator==(const dra::rational& nat) const
{
    return number_ == nat.number_;
}

bool dra::rational::operator!=(const dra::rational& nat) const
{
    return number_ != nat.number_;
}

bool dra::rational::operator<(const dra::rational& nat) const
{
    return number_ < nat.number_;
}

bool dra::rational::operator>(const dra::rational& nat) const
{
    return number_ > nat.number_;
}

bool dra::rational::operator<=(const dra::rational& nat) const
{
    return number_ <= nat.number_;
}

bool dra::rational::operator>=(const dra::rational& nat) const
{
    return number_ >= nat.number_;
}

//==============================================================================
//========================================================================== E/S
//==============================================================================
std::ostream& dra::rational::toStream(std::ostream& os) const
{
    os << number_;
    return os;
}

std::istream& dra::rational::fromStream(std::istream& is)
{
    is >> number_;
    return is;
}

std::ostream& operator<<(std::ostream& os, dra::rational nat)
{
    nat.toStream(os);
    return os;
}

std::istream& operator>>(std::istream& is, dra::rational nat)
{
    nat.fromStream(is);
    return is;
}

#endif