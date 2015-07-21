#include "common.hpp"
#include "vector.hpp"

#include <iostream>

using namespace std;

int main(void)
{
	vector_t test1(1, 10);
	for(int i = 1; i <= 10; i++)
		test1[i] = i;

	test1.push_back(99);

	cout << "Push 99....: " << test1 << endl;

	cout << "Popeo: " << test1.pop_back();

	cout << "..: " << test1 << endl;

	test1.earse(2);

	cout << "Easrse #2..: " << test1 << endl;

	test1.insert(5, 88);

	cout << "Insert #5=88 " << test1 << endl;

	vector_t test2(test1);

	cout << "Test 2.....: " << test2 << endl;

	return 0;
}