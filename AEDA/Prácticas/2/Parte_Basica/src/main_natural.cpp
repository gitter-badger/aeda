#include <iostream>
#include "natural.hpp"

using namespace std;

int main(void)
{
	natural_t test1(5);
	natural_t test2;

	TRAZA(test2);
	test2 = test1;
	TRAZA(test2);
	
	return 0;
}
