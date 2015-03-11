#pragma once

#include <iostream>
#include <cstdlib>

#define TRAZA(ARG) std::cout << #ARG " = " << ARG << std::endl; 

class integer_t
{
private:
	long long int number_;
public:
	//============================================Constructores y destructores
	integer_t(void);
	integer_t(long long int);
	integer_t(const integer_t&);
	~integer_t(void);
	//============================================Acceso a los elementos
	void set_num(long long int);
	long long int get_num(void);
	//============================================Sobrecarga de operadores
	friend std::ostream& operator<<(std::ostream& os, const integer_t& num);
	friend std::istream& operator>>(std::istream& is, integer_t& num);

	integer_t& operator=(const integer_t& num);

	integer_t operator+(const integer_t& num) const;
	integer_t operator-(const integer_t& num) const;
	integer_t operator*(const integer_t& num) const;
	integer_t operator/(const integer_t& num) const;
	integer_t operator%(const integer_t& num) const;

	bool operator==(const integer_t& num) const;
	bool operator!=(const integer_t& num) const;
	bool operator<(const integer_t& num) const;
	bool operator>(const integer_t& num) const;
	bool operator<=(const integer_t& num) const;
	bool operator>=(const integer_t& num) const;
};