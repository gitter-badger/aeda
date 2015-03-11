#pragma once

#include <iostream>
#include <cstdlib>
#include "integer.hpp"

#define TRAZA(ARG) std::cout << #ARG " = " << ARG << std::endl; 

class rational_t
{
public:
	integer_t numerator_;
	integer_t denominator_;
public:
	//============================================Constructores y destructores
	rational_t(void);
	rational_t(integer_t);
	rational_t(integer_t, integer_t);
	rational_t(const rational_t&);
	~rational_t(void);
	//============================================Utilidades
	void simplify(void);
	integer_t abs(integer_t);
	//============================================Acceso a los elementos
	void set_numerator(integer_t);
	void set_denominator(integer_t);
	integer_t get_numerator(void);
	integer_t get_denominator(void);
	//============================================Sobrecarga de operadoress
	friend std::ostream& operator<<(std::ostream& os, const rational_t& num);
	friend std::istream& operator>>(std::istream& is, rational_t& num);

	rational_t& operator=(const rational_t& num);

	rational_t operator+(const rational_t& num) const;
	rational_t operator-(const rational_t& num) const;
	rational_t operator*(const rational_t& num) const;
	rational_t operator/(const rational_t& num) const;

	bool operator==(const rational_t& num) const;
	bool operator!=(const rational_t& num) const;
	bool operator<(const rational_t& num) const;
	bool operator>(const rational_t& num) const;
	bool operator<=(const rational_t& num) const;
	bool operator>=(const rational_t& num) const;
};