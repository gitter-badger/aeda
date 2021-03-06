#ifndef _rational_HPP_
#define _rational_HPP_

#include <iostream>

#include "number.hpp"
#include "integer.hpp"
#include "exceptions.hpp"
#include "debug.hpp"

namespace dra{
	typedef dra::integer rational_t;
	class rational;
}

class dra::rational: public dra::number{
private:
    dra::rational_t numerator_;
    dra::rational_t denominator_;
public:
    //================================== Constructores, destructores y operador=
    rational(void);
    rational(long long int);
    rational(long long int, long long int);
    rational(const rational&);
    rational& operator=(const rational&);
    ~rational(void);
    //=============================================================== Utilidades
	void simplify(void);
	dra::rational_t min(dra::rational_t, dra::rational_t);
	//=================================================================== Acceso
	dra::integer get_numerator(void) const;
	dra::integer get_denominator(void) const;
	void set_numerator(const dra::integer&);
	void set_denominator(const dra::integer&);
    //=================================================== Operadores artiméticos
    dra::rational operator+(const dra::rational& rat) const;
    dra::rational operator-(const dra::rational& rat) const;
    dra::rational operator*(const dra::rational& rat) const;
    dra::rational operator/(const dra::rational& rat) const;
    //==================================== Operadores de incremento y decremento
    void operator++(int);
    void operator--(int);
    //====================================== Operadores de asignación compuestos
    dra::rational operator+=(const dra::rational& rat);
    dra::rational operator-=(const dra::rational& rat);
    dra::rational operator*=(const dra::rational& rat);
    dra::rational operator/=(const dra::rational& rat);
    //================================================== Operadores relacionales
    bool operator==(const dra::rational& rat) const;
	bool operator!=(const dra::rational& rat) const;
	bool operator<(const dra::rational& rat) const;
	bool operator>(const dra::rational& rat) const;
	bool operator<=(const dra::rational& rat) const;
	bool operator>=(const dra::rational& rat) const;
    //====================================================================== E/S
    std::ostream& toStream(std::ostream& os) const;
    std::istream& fromStream(std::istream& is);
};

//==============================================================================
//====================================== Constructores, destructores y operador=
//==============================================================================
dra::rational::rational(void):
numerator_(0),
denominator_(1)
{}

dra::rational::rational(long long int numerator):
numerator_(numerator),
denominator_(1)
{}

dra::rational::rational(long long int numerator, long long int denominator):
numerator_(numerator),
denominator_(denominator)
{
    simplify();
}

dra::rational::rational(const rational& rat)
{
    numerator_ = rat.numerator_;
    denominator_ = rat.denominator_;
}

dra::rational& dra::rational::operator=(const rational& rat)
{
    numerator_ = rat.numerator_;
    denominator_ = rat.denominator_;
}

dra::rational::~rational(void)
{}

//==============================================================================
//=================================================================== Utilidades
//==============================================================================
void dra::rational::simplify(void)
{
    dra::integer zero;
    for(dra::integer i = min(numerator_, denominator_); i > 1; i--){
		if(((denominator_ % i) == zero) && ((numerator_ % i) == zero)){
			denominator_ /= i;
			numerator_   /= i;
		}
	}
	if(denominator_ < 0){
	    denominator_*=-1;
	    numerator_*=-1;
	}
}

dra::rational_t dra::rational::min(dra::rational_t one, dra::rational_t two)
{
    if(one < 0) one*=-1;
    if(two < 0) two*=-1;
    return (one>two)? two: one;
}

//==============================================================================
//======================================================================= Acceso
//==============================================================================
dra::integer dra::rational::get_numerator(void) const
{
    return numerator_;
}

dra::integer dra::rational::get_denominator(void) const
{
    return denominator_;
}

void dra::rational::set_numerator(const dra::integer& num)
{
    numerator_ = num;
    simplify();
}

void dra::rational::set_denominator(const dra::integer& den)
{
    denominator_ = den;
    simplify();
}
	
//==============================================================================
//======================================================= Operadores artiméticos
//==============================================================================
dra::rational dra::rational::operator+(const dra::rational& rat) const
{
    return dra::rational(dra::integer_t((numerator_ * rat.denominator_) + (rat.numerator_ * denominator_)), dra::integer_t(denominator_*rat.denominator_));
}

dra::rational dra::rational::operator-(const dra::rational& rat) const
{
    return dra::rational(dra::integer_t((numerator_ * rat.denominator_) - (rat.numerator_ * denominator_)), dra::integer_t(denominator_*rat.denominator_));
}

dra::rational dra::rational::operator*(const dra::rational& rat) const
{
    return dra::rational(dra::integer_t(numerator_*rat.numerator_), dra::integer_t(denominator_*rat.denominator_));
}

dra::rational dra::rational::operator/(const dra::rational& rat) const
{
    return dra::rational(dra::integer_t(numerator_*rat.denominator_), dra::integer_t(denominator_*rat.numerator_));
}

//==============================================================================
//======================================== Operadores de incremento y decremento
//==============================================================================
void dra::rational::operator++(int)
{
    *this = *this + dra::rational(1);
}

void dra::rational::operator--(int)
{
    *this = *this - dra::rational(1);
}
//==============================================================================
//========================================== Operadores de asignación compuestos
//==============================================================================
dra::rational dra::rational::operator+=(const dra::rational& rat)
{
    return *this = *this + rat;
}

dra::rational dra::rational::operator-=(const dra::rational& rat)
{
    return *this = *this - rat;
}

dra::rational dra::rational::operator*=(const dra::rational& rat)
{
    return *this = *this * rat;
}

dra::rational dra::rational::operator/=(const dra::rational& rat)
{
    return *this = *this / rat;
}

//==============================================================================
//====================================================== Operadores relacionales
//==============================================================================
bool dra::rational::operator==(const dra::rational& rat) const
{
    return (numerator_ == rat.numerator_) && (denominator_ == rat.denominator_);
}

bool dra::rational::operator!=(const dra::rational& rat) const
{
    return (numerator_ != rat.numerator_) || (denominator_ != rat.denominator_);
}

bool dra::rational::operator<(const dra::rational& rat) const
{
    return numerator_*rat.denominator_ < rat.numerator_*denominator_;
}

bool dra::rational::operator>(const dra::rational& rat) const
{
    return numerator_*rat.denominator_ > rat.numerator_*denominator_;
}

bool dra::rational::operator<=(const dra::rational& rat) const
{
    return numerator_*rat.denominator_ <= rat.numerator_*denominator_;
}

bool dra::rational::operator>=(const dra::rational& rat) const
{
    return numerator_*rat.denominator_ >= rat.numerator_*denominator_;
}

//==============================================================================
//========================================================================== E/S
//==============================================================================
std::ostream& dra::rational::toStream(std::ostream& os) const
{
    os << numerator_ << "/" << denominator_;
    return os;
}

std::istream& dra::rational::fromStream(std::istream& is)
{
    is >> numerator_ >> denominator_;
    return is;
}

std::ostream& operator<<(std::ostream& os, dra::rational rat)
{
    rat.toStream(os);
    return os;
}

std::istream& operator>>(std::istream& is, dra::rational rat)
{
    rat.fromStream(is);
    return is;
}

#endif