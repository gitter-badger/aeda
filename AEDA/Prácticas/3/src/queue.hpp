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
	size_t sz_;
	size_t msz_;
	iterator_t rear_;
	buffer_t buffer_;
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
	std::ostream& toStream(std::ostream&);
};

//==============================================================================
//====================================== Constructores, destructores y operador=
//==============================================================================
template<class T>
dra::queue<T>::queue(void):
q_(nullptr),
rear_(EMPTY_QUEUE),
sz_(UNINITIALIZED_VALUE),
buffer_(DEFAULT_BUFFER_SIZE),
msz_(sz_+buffer_)
{
	
}

template<class T>
dra::queue<T>::queue(dra::size_t sz):
q_(nullptr),
rear_(EMPTY_QUEUE),
sz_(UNINITIALIZED_VALUE),
buffer_(DEFAULT_BUFFER_SIZE),
msz_(sz_+buffer_)
{
	
}

template<class T>
dra::queue<T>::queue(const queue& q)
{
	
}

template<class T>
dra::queue<T>::queue(std::initializer_list<T> il):
q_(nullptr),
rear_(EMPTY_QUEUE),
sz_(UNINITIALIZED_VALUE),
buffer_(DEFAULT_BUFFER_SIZE),
msz_(sz_+buffer_)
{
	
}

template<class T>
dra::queue<T>& dra::queue<T>::operator=(const queue& q)
{
	
}

template<class T>
dra::queue<T>::~queue(void)
{
	
}

//==============================================================================
//==================================================================== Capacidad
//==============================================================================
template<class T>
bool dra::queue<T>::empty(void) const
{
	
}

template<class T>
void dra::queue<T>::resize(dra::size_t size)
{
	
}

template<class T>
dra::size_t dra::queue<T>::size(void) const
{
	
}

//==============================================================================
//=========================================================== Acceso a elementos
//==============================================================================
template<class T>
T& dra::queue<T>::front(void)
{
	
}

template<class T>
T dra::queue<T>::front(void) const
{
	
}

template<class T>
T& dra::queue<T>::rear(void)
{
	
}

template<class T>
T dra::queue<T>::rear(void) const
{
	
}

//==============================================================================
//================================================================ Modificadores
//==============================================================================
template<class T>
void dra::queue<T>::push(const T& val)
{
	
}

template<class T>
void dra::queue<T>::pop(void)
{
	
}

template<class T>
void dra::queue<T>::swap(queue& it)
{
	
}

//==============================================================================
//========================================================================== E/S
//==============================================================================

template<class T>
std::ostream& dra::queue<T>::toStream(std::ostream& os)
{
	
}

//==============================================================================
//=============================================Fin de implementación de la clase
//==============================================================================
template<class T>
std::ostream& operator<<(std::ostream& os, const dra::queue<T>& q)
{
	
}

#endif