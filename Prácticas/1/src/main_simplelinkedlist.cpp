#include "common.hpp"
#include "simplelinkedlist.hpp"
#include <iostream>

using namespace std;

int main(void)
{
	simplelinkedlist_t test;

	for(int i = 1; i <= 3; i++)
		test.push_back(new node_t(i)); //meter 3 nodos (por el final)
	cout << test << endl;

	for(int i = 1; i <= 3; i++)
		test.push_front(new node_t(100-i)); //meter 3 nodos (por el el principio)
	cout << test << endl;

	delete test.extract_front();
	cout << test << endl;

	delete test.extract_back();
	cout << test << endl;
}