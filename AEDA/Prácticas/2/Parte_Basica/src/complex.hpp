#pragma once

#include <iostream>
#include <cstdlib>
#include "real.hpp"

#define TRAZA(ARG) std::cout << #ARG " = " << ARG << std::endl; 

class complex_t
{
private:
	real_t real_;
	real_t imag_;
public:
	//============================================Constructores y destructores
	complex_t(void);
	complex_t(real_t);
	complex_t(real_t, real_t);
	complex_t(const complex_t&);
	~complex_t(void);
	//============================================Acceso a los elementos
	void set_real(real_t real);
	void set_imag(real_t imag);
	real_t get_real(void);
	real_t get_imag(void);
	
	//============================================Sobrecarga de operadores
	friend std::ostream& operator<<(std::ostream& os, const complex_t& num);
	friend std::istream& operator>>(std::istream& is, complex_t& num);

	//complex_t& operator=(const complex_t& num);

	complex_t operator+(const complex_t& num) const;
	complex_t operator-(const complex_t& num) const;
	complex_t operator*(const complex_t& num) const;
	complex_t operator/(const complex_t& num) const;

	bool operator==(const complex_t& num) const;
	bool operator!=(const complex_t& num) const;
	// http://www.cut-the-knot.org/do_you_know/complex_compare.shtml
};