#include "digit.hpp"

digit_struct digit_struct::operator=(const unsigned short integer)
{
	if(integer > 9){
		std::cerr << "Invalid digit '" << integer << "'" << std::endl;
		exit(NOT_A_DIGIT);
	}
	switch(integer){
		case 0: bit_[3] = 0; bit_[2] = 0; bit_[1] = 0; bit_[0] = 0; break;
		case 1: bit_[3] = 0; bit_[2] = 0; bit_[1] = 0; bit_[0] = 1; break;
		case 2: bit_[3] = 0; bit_[2] = 0; bit_[1] = 1; bit_[0] = 0; break;
		case 3: bit_[3] = 0; bit_[2] = 0; bit_[1] = 1; bit_[0] = 1; break;
		case 4: bit_[3] = 0; bit_[2] = 1; bit_[1] = 0; bit_[0] = 0; break;
		case 5: bit_[3] = 0; bit_[2] = 1; bit_[1] = 0; bit_[0] = 1; break;
		case 6: bit_[3] = 0; bit_[2] = 1; bit_[1] = 1; bit_[0] = 0; break;
		case 7: bit_[3] = 0; bit_[2] = 1; bit_[1] = 1; bit_[0] = 1; break;
		case 8: bit_[3] = 1; bit_[2] = 0; bit_[1] = 0; bit_[0] = 0; break;
		case 9: bit_[3] = 1; bit_[2] = 0; bit_[1] = 0; bit_[0] = 1; break;
	}
	return *this;
}

unsigned short digit_struct::integer(void) const
{
	unsigned short multiply = 1;
	unsigned short result = 0;
	for(unsigned short i = 0; i < 4; i++){
		result+= (bit_[i]*multiply);
		multiply*=2;
	}
	return result;
}
/*
digit_t digit_t::get_overflow(void)
{
	return digit_t(overflow_.integer());
}

void digit_t::set_overflow(digit_t overflow)
{
	overflow_ = overflow.digit_;
}

bool digit_t::overflowed(void)
{
	return (overflow_.bit_[3] || overflow_.bit_[2] || overflow_.bit_[1] || overflow_.bit_[0]);
}*/

unsigned short digit_t::integer(void)
{
	return digit_.integer();
}

digit_t::digit_t(void)
{}

digit_t::digit_t(unsigned short digit)
{
	digit_ = digit;
}

digit_t::digit_t(const digit_t& digit)
{
	*this = digit;
}

digit_t::~digit_t(void)
{}

std::ostream& operator<<(std::ostream& os, const digit_t& it)
{
	//os << it.digit_.bit_[3] << it.digit_.bit_[2] << it.digit_.bit_[1] << it.digit_.bit_[0];
	os << it.digit_.integer();
}
/*
std::istream& operator>>(std::istream& is, digit_t& it)
{
	unsigned short aux;
	is >> aux;
	it.digit_ = aux;
}*/

digit_t::operator int() const
{
	return digit_.integer();
}
/*
digit_t digit_t::operator=(const unsigned short digit)
{
	digit_ = digit;
}



digit_t digit_t::operator+(const digit_t& digit) const
{
	digit_t result;
	unsigned short fst = this->digit_.integer();
	unsigned short scd = digit.digit_.integer();
	unsigned short rst = fst + scd;

	if(overflow_.bit_[0]) rst++;
	if(rst > 9){
		rst-=10;
		result.overflow_.bit_[0] = true;
	}
	else
		result.overflow_.bit_[0] = false;

	result.digit_ = rst;

	return result;
}

digit_t digit_t::operator-(const digit_t& digit) const
{
	digit_t result;
	unsigned short fst = this->digit_.integer();
	unsigned short scd = digit.digit_.integer();
	unsigned short rst;
	
	if(overflow_.bit_[0]) scd++;

	if(fst > scd){
		rst = fst - scd;
		result.overflow_.bit_[0] = false;
	}
	else{
		rst = (fst+10) - scd;
		result.overflow_.bit_[0] = true;
	}

	result.digit_ = rst;

	return result;
}

digit_t digit_t::operator*(const digit_t& digit) const
{
	digit_t result;
	unsigned short fst = this->digit_.integer();
	unsigned short scd = digit.digit_.integer();
	unsigned short rst;
	unsigned short ove = 0;

	rst = fst * scd;

	rst += overflow_.integer();

	while(rst > 9){
		ove++;
		rst-=10;
	}

	result.overflow_ = ove;
	result.digit_ = rst;

	return result;
}

digit_t digit_t::operator/(const digit_t& digit) const
{
	digit_t result;
	unsigned short fst = this->digit_.integer();
	unsigned short scd = digit.digit_.integer();
	unsigned short rst;
	unsigned short ove = 0;

	rst = fst / scd;

	ove = fst % scd;

	result.digit_ = rst;
	result.overflow_ = ove;

	return result;
}

bool digit_t::operator[](unsigned short it) const
{
	if(it > 4 || it < 0){
		std::cerr << "Bad access" << std::endl;
		exit(BAD_ELEMENT_ACCESS);
	}
	return digit_.bit_[it];
}*/

bool digit_t::operator==(const digit_t& digit) const
{
	return digit_.integer() == digit.digit_.integer();
}

bool digit_t::operator!=(const digit_t& digit) const
{
	return digit_.integer() != digit.digit_.integer();
}

bool digit_t::operator<(const digit_t& digit) const
{
	return digit_.integer() < digit.digit_.integer();
}

bool digit_t::operator>(const digit_t& digit) const
{
	return digit_.integer() > digit.digit_.integer();
}

bool digit_t::operator<=(const digit_t& digit) const
{
	return digit_.integer() <= digit.digit_.integer();
}

bool digit_t::operator>=(const digit_t& digit) const
{
	return digit_.integer() >= digit.digit_.integer();
}