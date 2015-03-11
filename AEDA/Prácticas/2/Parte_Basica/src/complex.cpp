#include "complex.hpp"

//============================================Constructores y destructores

complex_t::complex_t(void):
real_(0),
imag_(0){}

complex_t::complex_t(real_t num):
real_(num),
imag_(0){}

complex_t::complex_t(real_t real, real_t imag):
real_(real),
imag_(imag){}

complex_t::complex_t(const complex_t& num)
{
	*this = num;
}

complex_t::~complex_t(void){}

//============================================Acceso a los elementos

void complex_t::set_real(real_t real){real_ = real;}
void complex_t::set_imag(real_t imag){imag_ = imag;}
real_t complex_t::get_real(void){return real_;}
real_t complex_t::get_imag(void){return imag_;}

//============================================Sobrecarga de operadores

std::ostream& operator<<(std::ostream& os, const complex_t& num)
{
	if(num.imag_>=0){os << num.real_ << " + " << num.imag_ << "i"; return os;}
	os << num.real_ << " - " << num.imag_ << "i"; return os;
}
std::istream& operator>>(std::istream& is, complex_t& num){	is >> num.real_ >> num.imag_; return is;}


//complex_t& complex_t::operator=(const complex_t& num){ real = num.number_; return *this;}

complex_t complex_t::operator+(const complex_t& num) const
{
	return complex_t(real_ + num.real_, imag_ + num.imag_);
}

complex_t complex_t::operator-(const complex_t& num) const
{
	return complex_t(real_ - num.real_, imag_ - num.imag_);
}

complex_t complex_t::operator*(const complex_t& num) const
{
	return complex_t(((real_ * num.real_) - (imag_ * num.imag_)), ((imag_ * num.real_) + (real_ * num.imag_)));
}

complex_t complex_t::operator/(const complex_t& num) const
{
	complex_t aux( ( (real_ * num.real_) - (imag_ * num.imag_) )/( num.real_*num.real_ + num.imag_*num.imag_ ), ( (imag_ * num.real_) + (real_ * num.imag_) )/( num.real_*num.real_ + num.imag_*num.imag_ ) );
}

bool complex_t::operator==(const complex_t& num) const {return (real_ == num.real_) && (imag_ == num.imag_);}


bool complex_t::operator!=(const complex_t& num) const {return (real_ != num.real_) || (imag_ != num.imag_);}