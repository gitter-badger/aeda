#ifndef _NUMERO_H_
#define _NUMERO_H_

#include <iostream>


class numbero_t
{
public:
	//Operadsores de entrada/salida estandar
	virtual std::ostream& toStream(std::ostream sout) const = 0;
	virtual std::istream& fromStream(std::istream sin) = 0;
};