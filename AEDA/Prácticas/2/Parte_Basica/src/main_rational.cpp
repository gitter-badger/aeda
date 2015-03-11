#include <iostream>
#include "rational.hpp"

using namespace std;

int main(void)
{
	rational_t test1(1,9);

	rational_t test2(10,20);

	rational_t test3;

	test3 = test1 * test2;

	TRAZA(test3);

	return 0;
}
