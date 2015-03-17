#ifndef _complex_HPP_
#define _complex_HPP_

#include <iostream>

#include "number.hpp"
#include "exceptions.hpp"
#include "real.hpp"

namespace dra{
	typedef dra::real complex_t;
	class complex;
}

class dra::complex: public dra::number{
private:
    dra::complex_t real_;
    dra::complex_t imag_;
public:
    //================================== Constructores, destructores y operador=
    complex(void);
    complex(long double);
    complex(long double,long double);
    complex(const complex&);
    complex& operator=(const complex&);
    ~complex(void);
    //=================================================== Operadores artiméticos
    dra::complex operator+(const dra::complex& cmpl) const;
    dra::complex operator-(const dra::complex& cmpl) const;
    dra::complex operator*(const dra::complex& cmpl) const;
    dra::complex operator/(const dra::complex& cmpl) const;
    //==================================== Operadores de incremento y decremento
    void operator++(int);
    void operator--(int);
    //====================================== Operadores de asignación compuestos
    dra::complex operator+=(const dra::complex& cmpl);
    dra::complex operator-=(const dra::complex& cmpl);
    dra::complex operator*=(const dra::complex& cmpl);
    dra::complex operator/=(const dra::complex& cmpl);
    //================================================== Operadores relacionales
    bool operator==(const dra::complex& cmpl) const;
	bool operator!=(const dra::complex& cmpl) const;
    //====================================================================== E/S
    std::ostream& toStream(std::ostream& os) const;
    std::istream& fromStream(std::istream& is);
};

//==============================================================================
//====================================== Constructores, destructores y operador=
//==============================================================================
dra::complex::complex(void):
real_(0),
imag_(0)
{}

dra::complex::complex(long double real):
real_(real),
imag_(0)
{}

dra::complex::complex(long double real, long double imag):
real_(real),
imag_(imag)
{}

dra::complex::complex(const complex& cmpl):
real_(cmpl.real_),
imag_(cmpl.imag_)
{}

dra::complex& dra::complex::operator=(const complex& cmpl)
{
    real_ = cmpl.real_;
    imag_ = cmpl.imag_;
}

dra::complex::~complex(void)
{}

//==============================================================================
//======================================================= Operadores artiméticos
//==============================================================================
dra::complex dra::complex::operator+(const dra::complex& cmpl) const
{
    return complex(dra::real_t(real_ + cmpl.real_), dra::real_t(imag_ + cmpl.imag_));
}

dra::complex dra::complex::operator-(const dra::complex& cmpl) const
{
    return complex(dra::real_t(real_ - cmpl.real_), dra::real_t(imag_ - cmpl.imag_));
}

dra::complex dra::complex::operator*(const dra::complex& cmpl) const
{
    return complex(dra::real_t((real_ * cmpl.real_) - (imag_ * cmpl.imag_)), dra::real_t((imag_ * cmpl.real_) + (real_ * cmpl.imag_)));
}

dra::complex dra::complex::operator/(const dra::complex& cmpl) const
{
    return complex( dra::real_t(( (real_ * cmpl.real_) - (imag_ * cmpl.imag_) )/( cmpl.real_*cmpl.real_ + cmpl.imag_*cmpl.imag_ )), dra::real_t(( (imag_ * cmpl.real_) + (real_ * cmpl.imag_) )/( cmpl.real_*cmpl.real_ + cmpl.imag_*cmpl.imag_ ) ));
}

//==============================================================================
//======================================== Operadores de incremento y decremento
//==============================================================================
void dra::complex::operator++(int)
{
    *this = *this + 1;
}

void dra::complex::operator--(int)
{
    *this = *this - 1;
}
//==============================================================================
//========================================== Operadores de asignación compuestos
//==============================================================================
dra::complex dra::complex::operator+=(const dra::complex& cmpl)
{
    return *this = *this + cmpl;
}

dra::complex dra::complex::operator-=(const dra::complex& cmpl)
{
    return *this = *this - cmpl;
}

dra::complex dra::complex::operator*=(const dra::complex& cmpl)
{
    return *this = *this * cmpl;
}

dra::complex dra::complex::operator/=(const dra::complex& cmpl)
{
    return *this = *this / cmpl;
}

//==============================================================================
//====================================================== Operadores relacionales
//==============================================================================
bool dra::complex::operator==(const dra::complex& cmpl) const
{
    return (real_ == cmpl.real_) && (imag_ == cmpl.imag_);
}

bool dra::complex::operator!=(const dra::complex& cmpl) const
{
    return (real_ != cmpl.real_) || (imag_ != cmpl.imag_);
}

//==============================================================================
//========================================================================== E/S
//==============================================================================
std::ostream& dra::complex::toStream(std::ostream& os) const
{
    if(imag_>=0)
        os << real_ << " + " << imag_ << "i";
    else
	    os << real_ << " - " << imag_ << "i";
	return os;
}

std::istream& dra::complex::fromStream(std::istream& is)
{
    is >> real_ >> imag_;
    return is;
}

std::ostream& operator<<(std::ostream& os, dra::complex cmpl)
{
    cmpl.toStream(os);
    return os;
}

std::istream& operator>>(std::istream& is, dra::complex cmpl)
{
    cmpl.fromStream(is);
    return is;
}

#endif