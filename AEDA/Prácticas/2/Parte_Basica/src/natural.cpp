#include "natural.hpp"

//============================================Constructores y destructores

natural_t::natural_t(void):
number_(0){}

natural_t::natural_t(long long int num)
{
	if(!isnatural(num)) exit(-1);
	else number_ = num;
}

natural_t::natural_t(const natural_t& num)
{
	*this = num;
}

natural_t::~natural_t(void){}

//============================================Condicion de natural

bool natural_t::isnatural(long long int num)
{
	return (num >= 0);
}

//============================================Acceso a los elementos

void natural_t::set_num(long long int num)
{
	if(!isnatural(num)) exit(-1);
	else number_ = num;
}

unsigned int natural_t::get_num(void) const
{
	return number_;
}

//============================================Sobrecarga de operadores

std::ostream& operator<<(std::ostream& os, const natural_t& num){ os << num.number_; return os;}
std::istream& operator>>(std::istream& is, natural_t& num){	is >> num.number_; return is;}


natural_t& natural_t::operator=(const natural_t& num){ number_ = num.number_; return *this;}

natural_t natural_t::operator+(const natural_t& num) const{	return natural_t(number_ + num.number_);}
natural_t natural_t::operator-(const natural_t& num) const{	if(*this < num) exit(1); else return natural_t(number_ - num.number_);}
natural_t natural_t::operator*(const natural_t& num) const{	return natural_t(number_ * num.number_);}
natural_t natural_t::operator/(const natural_t& num) const{	return natural_t(number_ / num.number_);}
natural_t natural_t::operator%(const natural_t& num) const{	return natural_t(number_ % num.number_);}


bool natural_t::operator==(const natural_t& num) const {return number_ == num.number_;}
bool natural_t::operator!=(const natural_t& num) const {return number_ != num.number_;}
bool natural_t::operator< (const natural_t& num) const {return number_ <  num.number_;}
bool natural_t::operator> (const natural_t& num) const {return number_ >  num.number_;}
bool natural_t::operator<=(const natural_t& num) const {return number_ <= num.number_;}
bool natural_t::operator>=(const natural_t& num) const {return number_ >= num.number_;}