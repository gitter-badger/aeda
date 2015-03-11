#include <iostream>

using namespace std;

template<class T>

class mycontainer{
	T element_;
public:
	mycontainer(T element):
	element_(element){}
	T increase(void){return ++element_;}
};

template<>

class mycontainer<char>{
	char element_;
public:
	mycontainer(char element):
	element_(element){}
	char uppercase(void){
		if((element_ >= 'a') && (element_ <= 'z')){
			element_ += 'A'-'a';
		}
		return element_;
	}
};

int main(void)
{
	mycontainer<int> a(7);
	mycontainer<char> b('j');
	cout << a.increase() << endl; // ???????????
	cout << b.uppercase() << endl;

	return 0;
}
