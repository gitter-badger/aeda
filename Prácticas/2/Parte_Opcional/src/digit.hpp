#ifndef __DIGIT_HPP__
#define __DIGIT_HPP__
#include <iostream>

/********************************************************************************************
 * En esta cabecera:
 * digit_struct: Estructura que almacena 4 bits.
 * digit_t: Clase que proporciona una interfaz a la estructura digit_struct
 *******************************************************************************************
 *
 * La clase digit_t almacena exactamente un digito decimal. Tambien almacena un overflow para
 * controlar la suma y la multiplicacion.
 * 
 * El digito (y el overflow) se almacena en forma de 4 bits, que estan en la
 * estructura "digit_struct", para poder encapsular el codigo. Esta estructura tambien tiene 2
 * funciones. La sobrecarga de operador "=" que recibe un unsigned short. Y una funcion que convierte
 * los bits a un unsiged short (para poder relacionarnos de forma correcta con los tipos del sitema).
 * 
 * 
 * Tiene los operadores aritmeticos (+,-,*,/), logicos(==,!=,<,>,<=,>=) acceso([]), y
 * E/S estandar (<<, >>) sobrecargados.
 */

#define NOT_A_DIGIT 1
#define BAD_ELEMENT_ACCESS 2


struct digit_struct{
	bool bit_[4] = {0,0,0,0};

	digit_struct operator=(const unsigned short integer);
	unsigned short integer(void) const;
};

class digit_t
{
private:
	digit_struct digit_;
public:
	digit_t(void);
	digit_t(unsigned short);
	digit_t(const digit_t&);
	~digit_t(void);

	unsigned short integer(void);
	
	friend std::ostream& operator<<(std::ostream&, const digit_t&);
	
	explicit operator int() const;

	bool operator==(const digit_t&) const;
	bool operator!=(const digit_t&) const;
	bool operator<(const digit_t&) const;
	bool operator>(const digit_t&) const;
	bool operator<=(const digit_t&) const;
	bool operator>=(const digit_t&) const;


};

#endif