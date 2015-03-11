#include "rational.hpp"
#include <unistd.h>

//============================================Constructores y destructores

rational_t::rational_t(void):
numerator_(0),
denominator_(1){}

rational_t::rational_t(integer_t numerator):
numerator_(numerator),
denominator_(1){}

rational_t::rational_t(integer_t numerator, integer_t denominator):
numerator_(numerator)
{
	set_denominator(denominator);
}

rational_t::rational_t(const rational_t& num)
{
	*this = num;
}

rational_t::~rational_t(void){}

//============================================Simplificar las fracciones

void rational_t::simplify(void)
{
	for(integer_t i = abs(numerator_ * denominator_); i > 1; i = i - 1){
		if((denominator_ % i == 0) && (numerator_ % i == 0)){
			denominator_ = denominator_ / i;
			numerator_   = numerator_   / i;
		}
	}
}

integer_t rational_t::abs(integer_t num)
{
	if(num < 0)
		return num*-1;
	return num;
}

//============================================Acceso a los elementos

void rational_t::set_numerator(integer_t numerator)
{
	numerator_ = numerator;
	simplify();
}

void rational_t::set_denominator(integer_t denominator)
{
	if(denominator == 0) exit(1);
	else denominator_ = denominator;
	simplify();
}

integer_t rational_t::get_numerator(void){return numerator_;}
integer_t rational_t::get_denominator(void){return denominator_;}

//============================================Sobrecarga de operadores

std::ostream& operator<<(std::ostream& os, const rational_t& num){ os << num.numerator_ << "/" << num.denominator_; return os;}
std::istream& operator>>(std::istream& is, rational_t& num){ is >> num.numerator_ >> num.denominator_; return is;}


rational_t& rational_t::operator=(const rational_t& num)
{
	numerator_ = num.numerator_;
	denominator_ = num.denominator_;
	return *this;
}

rational_t rational_t::operator+(const rational_t& num) const
{
	rational_t aux((numerator_ * num.denominator_) + (num.numerator_ * denominator_), denominator_*num.denominator_);
	aux.simplify();
	return aux;
}

rational_t rational_t::operator-(const rational_t& num) const
{
	rational_t aux(num.numerator_*-1, num.denominator_);
	aux = aux + *this; //no hace falta simplificar porque la suma ya está simplificando
	return aux;
}


rational_t rational_t::operator*(const rational_t& num) const
{
	rational_t aux(numerator_*num.numerator_, denominator_*num.denominator_);
	aux.simplify();
	return aux;
}
rational_t rational_t::operator/(const rational_t& num) const
{
	rational_t aux(numerator_*num.denominator_, denominator_*num.numerator_);
	aux.simplify();
	return aux;
}


bool rational_t::operator==(const rational_t& num) const {return (numerator_ == num.numerator_) && (denominator_ == num.denominator_);}
bool rational_t::operator!=(const rational_t& num) const {return (numerator_ != num.numerator_) || (denominator_ != num.denominator_);}
bool rational_t::operator< (const rational_t& num) const {return numerator_*num.denominator_ < num.numerator_*denominator_;}
bool rational_t::operator> (const rational_t& num) const {return numerator_*num.denominator_ > num.numerator_*denominator_;}
bool rational_t::operator<=(const rational_t& num) const {return numerator_*num.denominator_ <= num.numerator_*denominator_;}
bool rational_t::operator>=(const rational_t& num) const {return numerator_*num.denominator_ >= num.numerator_*denominator_;}