#include "common.hpp"
#include "queue.hpp"
#include <iostream>

using namespace std;

int main(void)
{
	queue_t test(4);

	for(int i = 1; i <= 3; i++)
		test.push(i);

	cout << test << endl;

	cout << "Saco el numero: " << test.pop() << endl;

	cout << test << endl;

	for(int i = 90; i <= 93; i++) //OVERFLOW!!
		test.push(i);

	cout << test << endl;

	for(int i = 40; i <= 44; i++)
		test.emplace(i);

	cout << test << endl;

	cout << "======================================================" << endl;

	queue_t test2;

	cout << test2 << endl;
	
	for(int i = 30; i <= 35; i++)
		test2.emplace(i);

	
	cout << test << endl;
	cout << test2 << endl;

	test.swap(test2);

	cout << test << endl;
	cout << test2 << endl;


	return 0;
}