#ifndef _HUMAN_HPP_
#define _HUMAN_HPP_

#include <iostream>
#include <string>

#include "random.hpp"

namespace dra{
class human;

typedef std::string name_t;
typedef std::string surname_t;
typedef unsigned long dni_t;
typedef unsigned long number_t;
}

class dra::human{
public:
	name_t name_;
	surname_t surname_;
	dni_t dni_;
	number_t number_;
public:
	human(void);
	dra::name_t& name(void);
	dra::name_t name(void) const;
	dra::surname_t& surname(void);
	dra::surname_t surname(void) const;
	dra::dni_t& dni(void);
	dra::dni_t dni(void) const;
	dra::number_t& number(void);
	dra::number_t number(void) const;

	std::ostream& toStream(std::ostream&);
};

dra::human::human(void)
{
	srand(dra::rand());
	int name = rand() % 50;

	srand(rand());
	int surname = rand() % 50;

	srand(rand());
	dni_ = rand() % 50000000 +30000000;

	srand(rand());
	number_ = rand() % 1000000 +922000000;

	switch(name){
	case 0: name_ = "Georgina"; break;
	case 1: name_ = "Mike"; break;
	case 2: name_ = "Lupe"; break;
	case 3: name_ = "Bertram"; break;
	case 4: name_ = "Georgetta"; break;
	case 5: name_ = "Telma"; break;
	case 6: name_ = "Floria"; break;
	case 7: name_ = "Darren"; break;
	case 8: name_ = "Carson"; break;
	case 9: name_ = "Lorene"; break;
	case 10: name_ = "Dorian"; break;
	case 11: name_ = "Carlota"; break;
	case 12: name_ = "Jackeline"; break;
	case 13: name_ = "Marcelo"; break;
	case 14: name_ = "Cathryn"; break;
	case 15: name_ = "Alvera"; break;
	case 16: name_ = "Elvera"; break;
	case 18: name_ = "Pamelia"; break;
	case 19: name_ = "Mckinley"; break;
	case 20: name_ = "Rufus"; break;
	case 21: name_ = "Monte"; break;
	case 22: name_ = "Emmett"; break;
	case 23: name_ = "Zulema"; break;
	case 24: name_ = "Wilbert"; break;
	case 25: name_ = "Janise"; break;
	case 26: name_ = "Ariane"; break;
	case 27: name_ = "Felice"; break;
	case 28: name_ = "Julienne"; break;
	case 29: name_ = "Kaci"; break;
	case 30: name_ = "Guillermina"; break;
	case 31: name_ = "Vennie"; break;
	case 32: name_ = "Lachelle"; break;
	case 33: name_ = "Maryrose"; break;
	case 34: name_ = "Shandra"; break;
	case 35: name_ = "Akiko"; break;
	case 36: name_ = "Pamala"; break;
	case 37: name_ = "Eric"; break;
	case 38: name_ = "Skye"; break;
	case 39: name_ = "Marissa"; break;
	case 40: name_ = "Denna"; break;
	case 41: name_ = "Wes"; break;
	case 42: name_ = "Many"; break;
	case 43: name_ = "Kris"; break;
	case 44: name_ = "Toshia"; break;
	case 45: name_ = "Athena"; break;
	case 46: name_ = "Janis"; break;
	case 47: name_ = "Myrtie"; break;
	case 48: name_ = "Maximo"; break;
	case 49: name_ = "Jamel"; break;
	}

	switch(surname){
	case 0: surname_ = "Sandoval"; break;
	case 1: surname_ = "Villanueva"; break;
	case 2: surname_ = "Fitzpatrick"; break;
	case 3: surname_ = "Patton"; break;
	case 4: surname_ = "Heath"; break;
	case 5: surname_ = "Cordova"; break;
	case 6: surname_ = "Gaines"; break;
	case 7: surname_ = "Sweeney"; break;
	case 8: surname_ = "Hunt"; break;
	case 9: surname_ = "Small"; break;
	case 10: surname_ = "Greer"; break;
	case 11: surname_ = "Chavez"; break;
	case 12: surname_ = "Monroe"; break;
	case 13: surname_ = "Benton"; break;
	case 14: surname_ = "Tapia"; break;
	case 15: surname_ = "Chambers"; break;
	case 16: surname_ = "Simmons"; break;
	case 17: surname_ = "Ingram"; break;
	case 18: surname_ = "Calderon"; break;
	case 19: surname_ = "Hahn"; break;
	case 20: surname_ = "Pratt"; break;
	case 21: surname_ = "Hoffman"; break;
	case 22: surname_ = "Murray"; break;
	case 23: surname_ = "Warner"; break;
	case 24: surname_ = "Benson"; break;
	case 25: surname_ = "Fischer"; break;
	case 26: surname_ = "Reilly"; break;
	case 27: surname_ = "Horne"; break;
	case 28: surname_ = "Donaldson"; break;
	case 29: surname_ = "Aguirre"; break;
	case 30: surname_ = "Soto"; break;
	case 31: surname_ = "Casey"; break;
	case 32: surname_ = "Bird"; break;
	case 33: surname_ = "Ferrell"; break;
	case 34: surname_ = "Lucero"; break;
	case 35: surname_ = "Henson"; break;
	case 36: surname_ = "French"; break;
	case 37: surname_ = "Stevenson"; break;
	case 38: surname_ = "Garner"; break;
	case 39: surname_ = "Rice"; break;
	case 40: surname_ = "Rollins"; break;
	case 41: surname_ = "Koch"; break;
	case 42: surname_ = "Russell"; break;
	case 43: surname_ = "Underwood"; break;
	case 44: surname_ = "Marks"; break;
	case 45: surname_ = "Vasquez"; break;
	case 46: surname_ = "Bennett"; break;
	case 47: surname_ = "Edwards"; break;
	case 48: surname_ = "Newman"; break;
	case 49: surname_ = "Ford"; break;
	}
}

dra::name_t& dra::human::name(void)
{
	return name_;
}

dra::name_t dra::human::name(void) const
{
	return name_;
}

dra::surname_t& dra::human::surname(void)
{
	return surname_;
}

dra::surname_t dra::human::surname(void) const
{
	return surname_;
}

dra::dni_t& dra::human::dni(void)
{
	return dni_;
}

dra::dni_t dra::human::dni(void) const
{
	return dni_;
}

dra::number_t& dra::human::number(void)
{
	return number_;
}

dra::number_t dra::human::number(void) const
{
	return number_;
}

std::ostream& dra::human::toStream(std::ostream& os)
{
	os << name_ << " " << surname_ << " (" << dni_ << "), TEL:" << number_;
	return os;
}

std::ostream& operator<<(std::ostream& os, dra::human person)
{
	person.toStream(os);
}

#endif
