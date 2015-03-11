#include "integer.hpp"

//============================================Constructores y destructores

integer_t::integer_t(void):
number_(0){}

integer_t::integer_t(long long int num):
number_(num){}

integer_t::integer_t(const integer_t& num)
{
	*this = num;
}

integer_t::~integer_t(void){}

//============================================Acceso a los elementos

void integer_t::set_num(long long int num)
{
	number_ = num;
}

long long int integer_t::get_num(void)
{
	return number_;
}

//============================================Sobrecarga de operadores

std::ostream& operator<<(std::ostream& os, const integer_t& num){ os << num.number_; return os;}
std::istream& operator>>(std::istream& is, integer_t& num){	is >> num.number_; return is;}


integer_t& integer_t::operator=(const integer_t& num){ number_ = num.number_; return *this;}

integer_t integer_t::operator+(const integer_t& num) const{	return integer_t(number_ + num.number_);}
integer_t integer_t::operator-(const integer_t& num) const{	return integer_t(number_ - num.number_);}
integer_t integer_t::operator*(const integer_t& num) const{	return integer_t(number_ * num.number_);}
integer_t integer_t::operator/(const integer_t& num) const{	return integer_t(number_ / num.number_);}
integer_t integer_t::operator%(const integer_t& num) const{	return integer_t(number_ % num.number_);}


bool integer_t::operator==(const integer_t& num) const {return number_ == num.number_;}
bool integer_t::operator!=(const integer_t& num) const {return number_ != num.number_;}
bool integer_t::operator< (const integer_t& num) const {return number_ <  num.number_;}
bool integer_t::operator> (const integer_t& num) const {return number_ >  num.number_;}
bool integer_t::operator<=(const integer_t& num) const {return number_ <= num.number_;}
bool integer_t::operator>=(const integer_t& num) const {return number_ >= num.number_;}