#include <iostream>
#include "integer.hpp"

using namespace std;

int main(void)
{
	unsigned short int test1(4);
	short int test2(4);

	unsigned int test3(4);
	int test4(4);

	unsigned long int test5(4);
	long int test6(4);

	integer_t test11(test1);
	TRAZA(test11);

	integer_t test12(test2);
	TRAZA(test12);

	integer_t test13(test3);
	TRAZA(test13);

	integer_t test14(test4);
	TRAZA(test14);

	integer_t test15(test5);
	TRAZA(test15);

	integer_t test16(test6);
	TRAZA(test16);

	test16 = test11 + test12;

	TRAZA(test16);

	test16 = test11 - test12;

	TRAZA(test16);

	test16 = test11 * test12;

	TRAZA(test16);

	test16 = test11 / test12;

	TRAZA(test16);

	return 0;
}
