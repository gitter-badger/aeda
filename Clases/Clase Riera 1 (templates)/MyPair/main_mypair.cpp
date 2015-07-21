#include <iostream>

using namespace std;

int main(void)
{
	mypair<int> p_a(2, 3);
	mypair<char> p_b('a', 'b');
	mypair<double> p_c(2.3, 5.4);

	//mypair<miclase>

	cout << p_a.get_max() << endl;
	cout << p_b.get_max() << endl;
	cout << p_c.get_max() << endl;
}