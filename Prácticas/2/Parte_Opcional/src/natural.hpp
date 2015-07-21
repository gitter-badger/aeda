#ifndef __NATURAL_HPP__
#define __NATURAL_HPP__

#include <iostream>
#include <deque>
#include <string>
#include <stdlib.h>

#include "digit.hpp"

#define NOT_A_DIGIT 1
#define NEGATIVE_SUBSTRACT 2
#define DIVISION_BY_ZERO 3
#define CHAR_MASK 0x30
#define TRAZA(ARG) std::cout << #ARG " = " << ARG << std::endl;

class natural_t
{
public:
	std::deque<digit_t> natural_;
public:
	natural_t(void);
	explicit natural_t(std::string);
	explicit natural_t(const char*);
	natural_t(unsigned long long int);
	~natural_t(void);

	void shrink_to_fit(void);
	void align(natural_t&);

	natural_t operator=(std::string);
	natural_t operator=(const char*);
	natural_t operator=(unsigned long long int);

	friend std::ostream& operator<<(std::ostream& os, natural_t natural);
	friend std::istream& operator>>(std::istream& os, natural_t& natural);

	natural_t operator+(natural_t);
	natural_t operator-(natural_t);
	natural_t operator*(natural_t);
	natural_t operator/(natural_t);
	natural_t operator%(natural_t);

	natural_t operator+=(natural_t);
	natural_t operator-=(natural_t);
	natural_t operator*=(natural_t);
	natural_t operator/=(natural_t);

	natural_t operator++(int);
	natural_t operator--(int);

	bool operator==(natural_t);
	bool operator!=(natural_t);
	bool operator<(natural_t);
	bool operator>(natural_t);
	bool operator<=(natural_t);
	bool operator>=(natural_t);
};

#endif