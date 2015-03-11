#include <iostream>
#include <exception>

using namespace std;

class myexception:public exception
{
	virtual const char* what() const throw()
	{
		return "My exception happened";
	}
} myex;



int main(){
	try{
		throw myex;
	}
	catch(exception& ex)
	{
		cout << ex.what() << endl;
	}
	return 0;
}