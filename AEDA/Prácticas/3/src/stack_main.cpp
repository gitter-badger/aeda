#include "stack.hpp"

#include <iostream>

using namespace std;

int main(void)
{
	dra::stack<int> hola;
	
	for(int i = 0; i < 33; i++){
		hola.push(i+1);
	}
	cout << hola << endl;
	for(int i = 0; i < 32; i++){
		hola.pop();
	}
	cout << hola << endl;
	
	
	return 0;
}