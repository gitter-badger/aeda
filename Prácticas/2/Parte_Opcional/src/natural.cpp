#include "natural.hpp"

natural_t::natural_t(void)
{}

natural_t::natural_t(std::string natural)
{
	*this = natural;
}

natural_t::natural_t(const char* natural)
{
	*this = natural;
}

natural_t::natural_t(unsigned long long int natural)
{
	*this = natural;
}

natural_t::~natural_t(void)
{}

void natural_t::shrink_to_fit(void)
{
	digit_t zero;
	while((natural_.front() == zero) && natural_.size() > 0 )
		natural_.pop_front();
}

void natural_t::align(natural_t& natural)
{
	while(natural_.size() != natural.natural_.size())
	{
		if(natural_.size() < natural.natural_.size())
			natural_.push_front(0);
		else
			natural.natural_.push_front(0);
	}
}

natural_t natural_t::operator=(std::string natural)
{
	while(natural.size() > 0){ //Mientras no hayamos eliminado todos los elementos del string temporal
		if((natural.back() < '0') || (natural.back() > '9')){
			std::cerr << "Invalid digit '" << natural.back() << "'" << std::endl;
			exit(NOT_A_DIGIT);
		}
		digit_t dummy(natural.back() - CHAR_MASK);
		natural_.push_front(dummy);
		natural.pop_back();
	}
	shrink_to_fit();

	return *this;
}

natural_t natural_t::operator=(const char* natural)
{
	*this = std::string(natural);
	return *this;
}

natural_t natural_t::operator=(unsigned long long int natural)
{
	*this = std::to_string(natural);
	return *this;
}

std::ostream& operator<<(std::ostream& os, natural_t natural)
{
	if(natural.natural_.size() == 0)
		os << 0;
	while(natural.natural_.size() > 0)
	{
		os << natural.natural_.front();
		natural.natural_.pop_front();
	}
	return os;
}

std::istream& operator>>(std::istream& is, natural_t& natural)
{
	std::string aux;
	std::getline(is, aux);
	natural = aux;
}

natural_t natural_t::operator+(natural_t scd)
{
	natural_t result;
	natural_t fst = *this;
	fst.align(scd);

	unsigned short tmp; //almacena el resultado de la suma de los 2 miembros y el overflow, que despues se desglosa en...
	unsigned short overflow; // el overflow (para la siguiente suma) y
	digit_t rst; //en el resultado de ese digito

	while(fst.natural_.size() > 0)
	{
		tmp = fst.natural_.back().integer() + scd.natural_.back().integer() + overflow;
		overflow = 0;
		while(tmp > 9){
			tmp-=10;
			overflow++;
		}
		rst = tmp;
		//=============================================
		result.natural_.push_front(rst);
		fst.natural_.pop_back();
		scd.natural_.pop_back();
	}

	if(overflow != 0)
		result.natural_.push_front(1);

	return result;
}

natural_t natural_t::operator-(natural_t scd)
{
	if(*this < scd){
		std::cerr << "Negative substract!" << std::endl;
		exit(NEGATIVE_SUBSTRACT);
	}

	natural_t result;

	if(*this == scd){
		return result;
	}

	natural_t fst = *this;
	fst.align(scd);
	unsigned short overflow;
	unsigned short tmp;
	digit_t rst;

	while(fst.natural_.size() > 0)
	{
		tmp = fst.natural_.back().integer();
		overflow+=scd.natural_.back().integer();

		if(overflow == 10){
			overflow = 0;
			rst = tmp - overflow;
			overflow = 1;
		}
		else if(tmp < overflow){
			tmp+=10;
			rst = tmp - overflow;
			overflow = 1;
		}
		else{
			rst = tmp - overflow;
			overflow = 0;
		}
		result.natural_.push_front(rst);
		fst.natural_.pop_back();
		scd.natural_.pop_back();
	}

	result.shrink_to_fit();
	return result;
}

natural_t natural_t::operator*(natural_t scd)
{
	natural_t result;
	if((natural_.size() == 0) || (scd.natural_.size() == 0))
		return result;

	if(natural_.size() == 1)
		return scd;

	if(scd.natural_.size() == 1)
		return *this;


	natural_t displace_counter;
	natural_t rst;
	unsigned short overflow;
	unsigned short tmp;

	while(scd.natural_.size() != 0){
		natural_t fst = *this;
		natural_t sums;
		overflow = 0;
		while(fst.natural_.size() != 0){
			tmp = (scd.natural_.back().integer() * fst.natural_.back().integer()) + overflow;
			overflow = 0;
			while(tmp > 9){
				tmp-=10;
				overflow++;
			}
			sums.natural_.push_front(tmp);
			fst.natural_.pop_back();
		}

		if(overflow != 0)
			sums.natural_.push_front(overflow);

		natural_t bk;
		while(bk != displace_counter){
			sums.natural_.push_back(0);
			bk++;
		}
		displace_counter++;
		result = result + sums;
		scd.natural_.pop_back();
	}


	return result;
}

natural_t natural_t::operator/(natural_t scd)
{
	if(scd == 0){
		std::cerr << "Division by zero!" << std::endl;
		exit(DIVISION_BY_ZERO);
	}

	natural_t result;
	natural_t fst = *this;
	natural_t dividendo;

	unsigned short rst;


	while(dividendo < scd)
	{
		dividendo.natural_.push_back(fst.natural_.front());
		fst.natural_.pop_front();
		result.natural_.push_back(0);
	}

	while(dividendo >= scd)
	{
		rst = 0;
		while(dividendo >= scd)
		{
			dividendo = dividendo - scd;
			rst++;
		}

		result.natural_.push_back(rst);
		if(fst.natural_.size() > 0){
			dividendo.natural_.push_back(fst.natural_.front());
			fst.natural_.pop_front();

			while((dividendo < scd))
			{
				dividendo.natural_.push_back(fst.natural_.front());
				fst.natural_.pop_front();
				result.natural_.push_back(0);
			}
		}
	}

	result.shrink_to_fit();
	return result;
}

natural_t natural_t::operator%(natural_t scd)
{
	if(scd == 0){
		std::cerr << "Division by zero!" << std::endl;
		exit(DIVISION_BY_ZERO);
	}

	natural_t result;
	natural_t fst = *this;
	natural_t dividendo;

	unsigned short rst;


	while(dividendo < scd)
	{
		dividendo.natural_.push_back(fst.natural_.front());
		fst.natural_.pop_front();
		result.natural_.push_back(0);
	}

	while(dividendo >= scd)
	{
		rst = 0;

		while(dividendo >= scd)
		{
			dividendo = dividendo - scd;
			rst++;
		}
		result.natural_.push_back(rst);
		if(fst.natural_.size() > 0){
			dividendo.natural_.push_back(fst.natural_.front());
			fst.natural_.pop_front();

			while((dividendo < scd))
			{
				dividendo.natural_.push_back(fst.natural_.front());
				fst.natural_.pop_front();
				result.natural_.push_back(0);
			}
		}
	}

	dividendo.shrink_to_fit();
	return dividendo;
}

natural_t natural_t::operator+=(natural_t scd)
{
	*this = *this + scd;
	return *this;
}
natural_t natural_t::operator-=(natural_t scd)
{
	*this = *this - scd;
	return *this;
}
natural_t natural_t::operator*=(natural_t scd)
{
	*this = *this * scd;
	return *this;
}
natural_t natural_t::operator/=(natural_t scd)
{
	*this = *this / scd;
	return *this;
}

natural_t natural_t::operator++(int)
{
	*this = *this + 1;
	return *this;
}

natural_t natural_t::operator--(int)
{
	*this = *this - 1;
	return *this;
}

bool natural_t::operator==(natural_t scd)
{
	
	if(natural_.size() != scd.natural_.size())
		return false;

	natural_t fst(*this);
	
	while(fst.natural_.size() != 0){
		if(fst.natural_.back() != scd.natural_.back())
			return false;
		fst.natural_.pop_back();
		scd.natural_.pop_back();
	}
	return true;
}

bool natural_t::operator!=(natural_t scd)
{
	return !(*this == scd);
}

bool natural_t::operator<(natural_t scd)
{
	if(natural_.size() < scd.natural_.size())
		return true;
	if(natural_.size() > scd.natural_.size())
		return false;

	natural_t fst(*this);

	while(fst.natural_.size() != 0){
		if(fst.natural_.front() < scd.natural_.front())
			return true;
		if(fst.natural_.front() > scd.natural_.front())
			return false;
		
		fst.natural_.pop_front();
		scd.natural_.pop_front();
	}
	return false;
}

bool natural_t::operator>(natural_t scd)
{
	return !(*this < scd) && (*this != scd);
}

bool natural_t::operator<=(natural_t scd)
{
	return (*this < scd) || (*this == scd);
}

bool natural_t::operator>=(natural_t scd)
{
	return (*this > scd) || (*this == scd);
}