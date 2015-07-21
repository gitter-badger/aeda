#include <iostream>
#include "complex.hpp"

using namespace std;

int main(void)
{
	complex_t test(5, 3);

	complex_t test2;

	TRAZA(test);
	TRAZA(test2);

	test2 = test;

	TRAZA(test2);

	return 0;
}
