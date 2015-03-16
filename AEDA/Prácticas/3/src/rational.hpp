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
    //================================================================Utilidades
	void simplify(void);
	dra::rational_t abs(dra::rational_t);
    //=================================================== Operadores artiméticos
    dra::rational operator+(const dra::rational& rat) const;
    dra::rational operator-(const dra::rational& rat) const;
    dra::rational operator*(const dra::rational& rat) const;
    dra::rational operator/(const dra::rational& rat) const;
    dra::rational operator%(const dra::rational& rat) const;
    //==================================== Operadores de incremento y decremento
    void operator++(int);
    void operator--(int);
    //====================================== Operadores de asignación compuestos
    dra::rational operator+=(const dra::rational& rat);
    dra::rational operator-=(const dra::rational& rat);
    dra::rational operator*=(const dra::rational& rat);
    dra::rational operator/=(const dra::rational& rat);
    dra::rational operator%=(const dra::rational& rat);
    //======================================================= Operadores lógicos
    bool operator!(void) const;
    bool operator&&(const dra::rational& rat) const;
    bool operator||(const dra::rational& rat) const;
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
    for(rational_t i = abs(numerator_ * denominator_); i > 1; i--){
		if((denominator_ % i == 0) && (numerator_ % i == 0)){
			denominator_ /= i;
			numerator_   /= i;
		}
	}
}

dra::rational_t dra::rational::abs(dra::rational_t num)
{
    if(num < 0)
		return num*-1;
	return num;
}

//==============================================================================
//======================================================= Operadores artiméticos
//==============================================================================
dra::rational dra::rational::operator+(const dra::rational& rat) const
{
    dra::rational aux(dra::integer_t((numerator_ * rat.denominator_) + (rat.numerator_ * denominator_)), dra::integer_t(denominator_*rat.denominator_));
    return aux;
}

dra::rational dra::rational::operator-(const dra::rational& rat) const
{
    int numerator = dra::integer_t((numerator_ * rat.denominator_) - (rat.numerator_ * denominator_));
    int denominator = dra::integer_t(denominator_*rat.denominator_);
    
    std::cout << "Resta es: " << numerator << "/" << denominator << std::endl;
}

dra::rational dra::rational::operator*(const dra::rational& rat) const
{
    
}

dra::rational dra::rational::operator/(const dra::rational& rat) const
{
    
}

dra::rational dra::rational::operator%(const dra::rational& rat) const
{
    
}

//==============================================================================
//======================================== Operadores de incremento y decremento
//==============================================================================
void dra::rational::operator++(int)
{
    
}

void dra::rational::operator--(int)
{
    
}
//==============================================================================
//========================================== Operadores de asignación compuestos
//==============================================================================
dra::rational dra::rational::operator+=(const dra::rational& rat)
{
    
}

dra::rational dra::rational::operator-=(const dra::rational& rat)
{
    
}

dra::rational dra::rational::operator*=(const dra::rational& rat)
{
    
}

dra::rational dra::rational::operator/=(const dra::rational& rat)
{
    
}

dra::rational dra::rational::operator%=(const dra::rational& rat)
{
    
}
//==============================================================================
//=========================================================== Operadores lógicos
//==============================================================================
bool dra::rational::operator!(void) const
{
    
}

bool dra::rational::operator&&(const dra::rational& rat) const
{
    
}

bool dra::rational::operator||(const dra::rational& rat) const
{
    
}

//==============================================================================
//====================================================== Operadores relacionales
//==============================================================================
bool dra::rational::operator==(const dra::rational& rat) const
{
    
}

bool dra::rational::operator!=(const dra::rational& rat) const
{
    
}

bool dra::rational::operator<(const dra::rational& rat) const
{
    
}

bool dra::rational::operator>(const dra::rational& rat) const
{
    
}

bool dra::rational::operator<=(const dra::rational& rat) const
{
    
}

bool dra::rational::operator>=(const dra::rational& rat) const
{
    
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