#include <iostream>

using namespace std;

int main(void)
{
	try{
		throw(5);
	}
	catch(int o)
	{
		cout << "Se ha producido el error " << o << endl;
	}
	return 0;
}