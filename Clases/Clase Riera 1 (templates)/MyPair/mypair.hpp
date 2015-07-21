#include <iostream>

template<class T>

class mypair{
private:
	T a_, b_;
public:
	mypair(T a, T b);
	T get_max(void);
};