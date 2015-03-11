#include "stack.hpp"

#include <iostream>

using namespace std;

int main(void)
{
	dra::stack<int> hola;
	
	
	hola.push(1);
	hola.push(2);
	hola.push(3);
	hola.push(4);
	
	
	cout << hola << endl;
	
	return 0;
}