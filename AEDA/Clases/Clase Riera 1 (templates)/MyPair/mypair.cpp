#include "mypair.hpp"


mypair<T>::mypair(T a, T b):
a_(a),
b_(b){}


T mypair<T>::get_max(void)
{
	T aux;
	aux = a_ > b_? a_:b_;
	return T;
}