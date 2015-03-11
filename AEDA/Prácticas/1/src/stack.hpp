#ifndef __stack__
#define __stack__
#include "common.hpp"

#define EMPTY_STACK -1

class stack_t{
private:
	TDATO* S_;
	int top_;
	unsigned int size_;
private:
	void build(void);
	void destroy(void);

	void resize(int n); //redimensionar la pila. 1-Es para el emplace, 2-Nunca puede decrecer
public:
	stack_t(void); //crea una pila de tamaño 1
	stack_t(unsigned int size); //crea una pila de tamaño size
	~stack_t(void);
	
	void push(TDATO it); //pone un dato en la parte superior de la pila
	TDATO top(void) const; //mirar el elemento superior de la pila
	TDATO pop(void); //sacar el elemento superior de la pila

	void swap(stack_t& it); //intercambiar una pila por otra
	void emplace(TDATO it); //si la pila está llena, se aumenta el tamaño y se pone el dato encima

	bool full(void) const; //para comprobar si la pila está llena
	bool empty(void) const; //para comprobar si la pila está vacía

	friend std::ostream& operator<<(std::ostream& os, stack_t& it);
};

#endif