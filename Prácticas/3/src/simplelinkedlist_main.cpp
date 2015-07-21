#include <iostream>
#include "simplelinkedlist.hpp"

using namespace std;

int main(void)
{
	dra::simplelinkedlist<int> test;


	test.push_back(new dra::node<int>(5)); //meter 3 nodos (por el final)
	
	cout << test << endl;
	
	test.extract_front();
	
	cout << test << endl;
	
	return 0;
}