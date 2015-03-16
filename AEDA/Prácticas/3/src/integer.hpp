#ifndef _integer_HPP_
#define _integer_HPP_

#include <iostream>

#include "number.hpp"
#include "exceptions.hpp"
//#include "debug.hpp"

#define MIN_VAL -2147483647
#define MAX_VAL 2147483647

namespace dra{
	typedef long int integer_t;
	class integer;
}

class dra::integer: public dra::number{
private:
    dra::integer_t number_;
public:
    //================================== Constructores, destructores y operador=
    integer(void);
    integer(long long int);
    integer(const integer&);
    integer& operator=(const integer&);
    ~integer(void);
    //=================================================== Operadores artiméticos
    dra::integer operator+(const dra::integer& intg) const;
    dra::integer operator-(const dra::integer& intg) const;
    dra::integer operator*(const dra::integer& intg) const;
    dra::integer operator/(const dra::integer& intg) const;
    dra::integer operator%(const dra::integer& intg) const;
    //==================================== Operadores de incremento y decremento
    void operator++(int);
    void operator--(int);
    //====================================== Operadores de asignación compuestos
    dra::integer operator+=(const dra::integer& intg);
    dra::integer operator-=(const dra::integer& intg);
    dra::integer operator*=(const dra::integer& intg);
    dra::integer operator/=(const dra::integer& intg);
    dra::integer operator%=(const dra::integer& intg);
    //======================================================= Operadores lógicos
    bool operator!(void) const;
    bool operator&&(const dra::integer& intg) const;
    bool operator||(const dra::integer& intg) const;
    //================================================== Operadores relacionales
    bool operator==(const dra::integer& intg) const;
	bool operator!=(const dra::integer& intg) const;
	bool operator<(const dra::integer& intg) const;
	bool operator>(const dra::integer& intg) const;
	bool operator<=(const dra::integer& intg) const;
	bool operator>=(const dra::integer& intg) const;
	//======================================================= Conversión de tipo
	explicit operator dra::integer_t();
    //====================================================================== E/S
    std::ostream& toStream(std::ostream& os) const;
    std::istream& fromStream(std::istream& is);
};

//==============================================================================
//====================================== Constructores, destructores y operador=
//==============================================================================
dra::integer::integer(void):
number_(0)
{}

dra::integer::integer(long long int num):
number_(0)
{
    if(num < MIN_VAL)
        throw exception::underflow_error("Exceeded 'MIN_VAL'");
    if(num > MAX_VAL)
        throw exception::overflow_error("Exceeded 'MAX_VAL'");
    number_ = num;
}

dra::integer::integer(const integer& intg)
{
    number_ = intg.number_; //Se podría poner *this=nat
}

dra::integer& dra::integer::operator=(const integer& intg)
{
    number_ = intg.number_;
}

dra::integer::~integer(void)
{}

//==============================================================================
//======================================================= Operadores artiméticos
//==============================================================================
dra::integer dra::integer::operator+(const dra::integer& intg) const
{
    if((number_ + intg.number_) > MAX_VAL)
        throw exception::overflow_error("Exceeded 'MAX_VAL' in operator '+'");
    return number_ + intg.number_;
}

dra::integer dra::integer::operator-(const dra::integer& intg) const
{
    if((number_ - intg.number_) < MIN_VAL)
        throw exception::underflow_error("Exceeded 'MIN_VAL'");
    return number_ - intg.number_;
}

dra::integer dra::integer::operator*(const dra::integer& intg) const
{
    if((number_ * intg.number_) > MAX_VAL)
        throw exception::overflow_error("Exceeded 'MAX_VAL' in operator '*'");
    return number_ * intg.number_;
}

dra::integer dra::integer::operator/(const dra::integer& intg) const
{
    if(intg == 0)
        throw exception::overflow_error("Divide by zero in operator '/'");
    return number_ / intg.number_;
}

dra::integer dra::integer::operator%(const dra::integer& intg) const
{
    if(intg == 0)
        throw exception::overflow_error("Divide by zero in operator '%'");
    return number_ % intg.number_;
}

//==============================================================================
//======================================== Operadores de incremento y decremento
//==============================================================================
void dra::integer::operator++(int)
{
    if((number_ + 1) > MAX_VAL)
        throw exception::overflow_error("Exceeded 'MAX_VAL' in operator '++'");
    number_++;
}

void dra::integer::operator--(int)
{
    if((number_ -1) < MIN_VAL)
        throw exception::underflow_error("Can't handle negative integers in operator '--'");
    number_--;
}
//==============================================================================
//========================================== Operadores de asignación compuestos
//==============================================================================
dra::integer dra::integer::operator+=(const dra::integer& intg)
{
    if((number_ + intg.number_) > MAX_VAL)
        throw exception::overflow_error("Exceeded 'MAX_VAL' in operator '+='");
    return number_ += intg.number_;
}

dra::integer dra::integer::operator-=(const dra::integer& intg)
{
    if((number_ - intg.number_) < MIN_VAL)
        throw exception::underflow_error("Exceeded 'MIN_VAL'");
    return number_ -= intg.number_;
}

dra::integer dra::integer::operator*=(const dra::integer& intg)
{
    if((number_ * intg.number_) > MAX_VAL)
        throw exception::overflow_error("Exceeded 'MAX_VAL' in operator '*='");
    return number_ *= intg.number_;
}

dra::integer dra::integer::operator/=(const dra::integer& intg)
{
    if(intg == 0)
        throw exception::overflow_error("Divide by zero in operator '/='");
    return number_ /= intg.number_;
}

dra::integer dra::integer::operator%=(const dra::integer& intg)
{
    if(intg == 0)
        throw exception::overflow_error("Divide by zero in operator '%='");
    return number_ %= intg.number_;
}
//==============================================================================
//=========================================================== Operadores lógicos
//==============================================================================
bool dra::integer::operator!(void) const
{
    return !number_;
}

bool dra::integer::operator&&(const dra::integer& intg) const
{
    return number_ && intg.number_;
}

bool dra::integer::operator||(const dra::integer& intg) const
{
    return number_ || intg.number_;
}

//==============================================================================
//====================================================== Operadores relacionales
//==============================================================================
bool dra::integer::operator==(const dra::integer& intg) const
{
    return number_ == intg.number_;
}

bool dra::integer::operator!=(const dra::integer& intg) const
{
    return number_ != intg.number_;
}

bool dra::integer::operator<(const dra::integer& intg) const
{
    return number_ < intg.number_;
}

bool dra::integer::operator>(const dra::integer& intg) const
{
    return number_ > intg.number_;
}

bool dra::integer::operator<=(const dra::integer& intg) const
{
    return number_ <= intg.number_;
}

bool dra::integer::operator>=(const dra::integer& intg) const
{
    return number_ >= intg.number_;
}

//==============================================================================
//=========================================================== Conversión de tipo
//==============================================================================
dra::integer::operator dra::integer_t()
{
    return number_;
}

//==============================================================================
//========================================================================== E/S
//==============================================================================
std::ostream& dra::integer::toStream(std::ostream& os) const
{
    os << number_;
    return os;
}

std::istream& dra::integer::fromStream(std::istream& is)
{
    is >> number_;
    return is;
}

std::ostream& operator<<(std::ostream& os, dra::integer intg)
{
    intg.toStream(os);
    return os;
}

std::istream& operator>>(std::istream& is, dra::integer intg)
{
    intg.fromStream(is);
    return is;
}

#endif