#ifndef _QUEUE_HPP_
#define _QUEUE_HPP_

#include <iostream>
#include <cstring> //memcpy
#include <initializer_list> //C++11

#include "exceptions.hpp"
#include "debug.hpp"

#define QUE_EMPTY_QUEUE 4294967295 //Realmente, es un -1, si le hacemos ++ da 0;
#define QUE_UNINITIALIZED_VALUE 0
#define QUE_DEFAULT_BUFFER_SIZE 10
#define QUE_MAX_SIZE 4294967294

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
	std::ostream& toStream(std::ostream&) const;
};

//==============================================================================
//====================================== Constructores, destructores y operador=
//==============================================================================
template<class T>
dra::queue<T>::queue(void):
q_(nullptr),
rear_(QUE_EMPTY_QUEUE),
sz_(QUE_UNINITIALIZED_VALUE),
buffer_(QUE_DEFAULT_BUFFER_SIZE),
msz_(sz_+buffer_)
{
	resize(QUE_UNINITIALIZED_VALUE);
}

template<class T>
dra::queue<T>::queue(dra::size_t sz):
q_(nullptr),
rear_(QUE_EMPTY_QUEUE),
sz_(QUE_UNINITIALIZED_VALUE),
buffer_(QUE_DEFAULT_BUFFER_SIZE),
msz_(sz_+buffer_)
{
	resize(sz);
}

template<class T>
dra::queue<T>::queue(const queue& q):
q_(nullptr),
rear_(QUE_EMPTY_QUEUE),
sz_(QUE_UNINITIALIZED_VALUE),
buffer_(QUE_DEFAULT_BUFFER_SIZE),
msz_(sz_+buffer_)
{
	*this = q;
}

template<class T>
dra::queue<T>::queue(std::initializer_list<T> il):
q_(nullptr),
rear_(QUE_EMPTY_QUEUE),
sz_(QUE_UNINITIALIZED_VALUE),
buffer_(QUE_DEFAULT_BUFFER_SIZE),
msz_(sz_+buffer_)
{
	resize(il.size());
	
	for(auto &val : il){
		rear_++;
		q_[rear_] = val;
	}
}

template<class T>
dra::queue<T>& dra::queue<T>::operator=(const queue& q)
{
	resize(q.sz_);
	
	if(!q.empty())
		memcpy(q_, q.q_, sz_*sizeof(T));
	
	rear_ = q.rear_;
}

template<class T>
dra::queue<T>::~queue(void)
{
	if(q_ != nullptr)
		delete[] q_;
}

//==============================================================================
//==================================================================== Capacidad
//==============================================================================
template<class T>
bool dra::queue<T>::empty(void) const
{
	return (rear_ == QUE_EMPTY_QUEUE);
}

template<class T>
void dra::queue<T>::resize(dra::size_t new_sz)
{
	if((new_sz > msz_)  || (q_ == nullptr)){
		if(new_sz > QUE_MAX_SIZE)
			throw exception::length_error("Exceeded max vector size 'QUE_MAX_SIZE'");
		
		sz_ = new_sz;
		
		if((sz_+buffer_) > QUE_MAX_SIZE)
			buffer_ = QUE_MAX_SIZE - sz_;
		
		msz_ = sz_ + buffer_;
		
		T *tmp_ptr = nullptr;
		
		try{
			tmp_ptr = new T[msz_];
		}
		catch(...){
			throw exception::mem_error("Memory error (full memory?)");
		}
		
		if(q_ != nullptr){
			memcpy(tmp_ptr, q_, sz_*sizeof(T));
			delete[] q_;
		}
		q_ = tmp_ptr;
	}
	else
		sz_ = new_sz;
}

template<class T>
dra::size_t dra::queue<T>::size(void) const
{
	return msz_;
}

//==============================================================================
//=========================================================== Acceso a elementos
//==============================================================================
template<class T>
T& dra::queue<T>::front(void)
{
	if(empty())
		throw exception::length_error("Empty Queue!");
	return q_[0];
}

template<class T>
T dra::queue<T>::front(void) const
{
	if(empty())
		throw exception::length_error("Empty Queue!");
	return q_[0];
}

template<class T>
T& dra::queue<T>::rear(void)
{
	if(empty())
		throw exception::length_error("Empty Queue!");
	return q_[rear_];
}

template<class T>
T dra::queue<T>::rear(void) const
{
	if(empty())
		throw exception::length_error("Empty Queue!");
	return q_[rear_];
}

//==============================================================================
//================================================================ Modificadores
//==============================================================================
template<class T>
void dra::queue<T>::push(const T& val)
{
	rear_++;
	if(rear_ >= sz_)
		resize(sz_+1);
	q_[rear_] = val;
	
}

template<class T>
void dra::queue<T>::pop(void)
{
	if(empty())
		throw exception::length_error("Empty Queue!");
	rear_--;
}

template<class T>
void dra::queue<T>::swap(queue& it)
{
	dra::queue<T> aux(it);
	it = *this;
	*this = aux;
}

//==============================================================================
//========================================================================== E/S
//==============================================================================

template<class T>
std::ostream& dra::queue<T>::toStream(std::ostream& os) const
{
	if(!empty()){
		for(dra::iterator_t i = 0; i <= rear_; i++)
			os << q_[i] << " ";
	}
	return os;
}

//==============================================================================
//=============================================Fin de implementación de la clase
//==============================================================================
template<class T>
std::ostream& operator<<(std::ostream& os, const dra::queue<T>& q)
{
	q.toStream(os);
	return os;
}

#endif