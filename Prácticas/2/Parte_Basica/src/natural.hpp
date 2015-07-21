#pragma once

#include <iostream>
#include <cstdlib>

#define TRAZA(ARG) std::cout << #ARG " = " << ARG << std::endl; 

class natural_t
{
private:
	unsigned long int number_;
public:
	//============================================Constructores y destructores
	natural_t(void);
	natural_t(long long int);
	natural_t(const natural_t&);
	~natural_t(void);
	//============================================Condicion de natural
	bool isnatural(long long int);
	//============================================Acceso a los elementos
	void set_num(long long int);
	unsigned int get_num(void) const;
	//============================================Sobrecarga de operadores
	friend std::ostream& operator<<(std::ostream& os, const natural_t& num);
	friend std::istream& operator>>(std::istream& is, natural_t& num);

	natural_t& operator=(const natural_t& num);

	natural_t operator+(const natural_t& num) const;
	natural_t operator-(const natural_t& num) const;
	natural_t operator*(const natural_t& num) const;
	natural_t operator/(const natural_t& num) const;
	natural_t operator%(const natural_t& num) const;

	bool operator==(const natural_t& num) const;
	bool operator!=(const natural_t& num) const;
	bool operator<(const natural_t& num) const;
	bool operator>(const natural_t& num) const;
	bool operator<=(const natural_t& num) const;
	bool operator>=(const natural_t& num) const;
};