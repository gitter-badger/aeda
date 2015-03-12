#ifndef _QUEUE_HPP_
#define _QUEUE_HPP_

#include <iostream>
#include <cstring> //memcpy
#include <initializer_list> //C++11

#include "exceptions.hpp"
#include "debug.hpp"

#define EMPTY_QUEUE 4294967295 //Realmente, es un -1, si le hacemos ++ da 0;
#define UNINITIALIZED_VALUE 0
#define DEFAULT_BUFFER_SIZE 10
#define MAX_SIZE 4294967294

namespace dra{
	typedef unsigned int size_t;
	typedef unsigned int buffer_t;
	typedef unsigned int iterator_t;
	
	template<class T> class queue;
}

template<class T>
class dra::queue{
private:
	T* q_;
	dra::iterator_t rear_;
	dra::size_t size_;
public:
    //================================== Constructores, destructores y operador=
	queue(void);
	queue(dra::size_t);
	queue(const queue&);
	queue(std::initializer_list<T> il);
	queue& operator=(const queue&);
	~queue(void);
    //================================================================ Capacidad
    inline bool empty(void) const;
	void resize(dra::size_t size);
	size_t size(void) const;
    //======================================================= Acceso a elementos
    T& front(void);
	T front(void) const;
	T& rear(void);
	T rear(void) const;
	//============================================================ Modificadores
	void push(const T& val);
	void pop(void);
	void swap(queue& it);
	//====================================================================== E/S
	std::ostream& toStream(std::ostream& os, queue& it);
};

#endif