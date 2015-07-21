#include "real.hpp"

//============================================Constructores y destructores

real_t::real_t(void):
number_(0){}

real_t::real_t(long double num):
number_(num){}

real_t::real_t(const real_t& num)
{
	*this = num;
}

real_t::~real_t(void){}

//============================================Acceso a los elementos

void real_t::set_num(long double num)
{
	number_ = num;
}

long double real_t::get_num(void)
{
	return number_;
}

//============================================Sobrecarga de operadores

std::ostream& operator<<(std::ostream& os, const real_t& num){ os << num.number_; return os;}
std::istream& operator>>(std::istream& is, real_t& num){	is >> num.number_; return is;}


real_t& real_t::operator=(const real_t& num){ number_ = num.number_; return *this;}

real_t real_t::operator+(const real_t& num) const{	return real_t(number_ + num.number_);}
real_t real_t::operator-(const real_t& num) const{	return real_t(number_ - num.number_);}
real_t real_t::operator*(const real_t& num) const{	return real_t(number_ * num.number_);}
real_t real_t::operator/(const real_t& num) const{	return real_t(number_ / num.number_);}


bool real_t::operator==(const real_t& num) const
{
	return fabs(number_ - num.number_) < EPSILON;
}

bool real_t::operator!=(const real_t& num) const
{
	return fabs(number_ - num.number_) >= EPSILON;
}

bool real_t::operator< (const real_t& num) const
{
	return (number_ - num.number_ < EPSILON) && (fabs(number_-num.number_) > EPSILON);
}

bool real_t::operator> (const real_t& num) const
{
	return (number_ - num.number_ > EPSILON) && (fabs(number_-num.number_) > EPSILON);
}

bool real_t::operator<=(const real_t& num) const
{
	return (*this < num) || (*this == num);
}
bool real_t::operator>=(const real_t& num) const
{
	return (*this > num) || (*this == num);
}