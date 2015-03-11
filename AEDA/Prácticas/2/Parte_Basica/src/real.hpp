#pragma once

#include <iostream>
#include <cstdlib>
#include <cmath>

#define TRAZA(ARG) std::cout << #ARG " = " << ARG << std::endl;
#define EPSILON 0.00001

class real_t
{
private:
	long double number_;
public:
	//============================================Constructores y destructores
	real_t(void);
	real_t(long double);
	real_t(const real_t&);
	~real_t(void);
	//============================================Acceso a los elementos
	void set_num(long double);
	long double get_num(void);
	//============================================Sobrecarga de operadores
	friend std::ostream& operator<<(std::ostream& os, const real_t& num);
	friend std::istream& operator>>(std::istream& is, real_t& num);

	real_t& operator=(const real_t& num);

	real_t operator+(const real_t& num) const;
	real_t operator-(const real_t& num) const;
	real_t operator*(const real_t& num) const;
	real_t operator/(const real_t& num) const;

	bool operator==(const real_t& num) const;
	bool operator!=(const real_t& num) const;
	bool operator<(const real_t& num) const;
	bool operator>(const real_t& num) const;
	bool operator<=(const real_t& num) const;
	bool operator>=(const real_t& num) const;
};