#include <iostream>
#include "node.hpp"

using namespace std;

int main(void)
{
	dra::node<int> test(5);
	
	std::cout << test << std::endl;

	return 0;
}