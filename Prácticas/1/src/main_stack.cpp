#include "common.hpp"
#include "stack.hpp"

#include <iostream>

using namespace std;

int main(void)
{
	stack_t test;
	test.emplace(3);
	test.emplace(6);
	test.emplace(7);

	cout << test << endl;
	/*
	stack_t test1(5);
	stack_t test2(5);

	test1.push(1);
	test1.push(2);
	test1.push(9);

	cout << "Primera pila:\n" << test1 << endl;

	test2.push(3);
	test2.push(7);

	cout << "Segunda pila:\n" << test2 << endl;

	test1.swap(test2);

	cout << "Primera pila:\n" << test1 << endl;
	cout << "Segunda pila:\n" << test2 << endl;
	*/

	return 0;
}