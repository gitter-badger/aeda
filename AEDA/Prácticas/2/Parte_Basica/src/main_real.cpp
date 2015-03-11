#include <iostream>
#include "real.hpp"

using namespace std;

int main(void)
{
	real_t test1(9.13456);
	real_t test2(9.13456);

	bool logic = test1 > test2;

	cout << logic << endl;
	

	return 0;
}
