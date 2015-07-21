#ifndef _STACK_HPP_
#define _STACK_HPP_

#include <iostream>
#include <cstring> //memcpy
#include <initializer_list> //C++11

#include "exceptions.hpp"
//#include "debug.hpp"

#define STK_EMPTY_STACK 4294967295 //Realmente, es un -1, si le hacemos ++ da 0;
#define STK_UNINITIALIZED_VALUE 0
#define STK_DEFAULT_BUFFER_SIZE 10
#define STK_MAX_SIZE 4294967294

namespace dra{
	typedef unsigned int size_t;
	typedef unsigned int buffer_t;
	typedef unsigned int iterator_t;
	
	template<class T> class stack;
}

template<class T>
class dra::stack
{
	private:
	T *s_;
	size_t sz_;
	size_t msz_;
	iterator_t top_;
	buffer_t buffer_;
	public:
	//================================== Constructores, destructores y operador=
	stack(void);
	stack(dra::size_t);
	stack(const stack&);
	stack(std::initializer_list<T> il);
	stack& operator=(const stack&);
	~stack(void);
	//================================================================ Capacidad
	inline bool empty(void) const;
	size_t size(void) const;
	void resize(size_t);
	//======================================================= Acceso a elementos
	T& top(void);
	T top(void) const;
	//============================================================ Modificadores
	void push(const T&);
	void pop(void);
	//====================================================================== E/S
	std::ostream& toStream(std::ostream& os) const;
};

//==============================================================================
//====================================== Constructores, destructores y operador=
//==============================================================================

template<class T>
dra::stack<T>::stack(void):
s_(nullptr),
top_(STK_EMPTY_STACK),
sz_(STK_UNINITIALIZED_VALUE),
buffer_(STK_DEFAULT_BUFFER_SIZE),
msz_(sz_+buffer_)
{
	resize(STK_UNINITIALIZED_VALUE);
}

template<class T>
dra::stack<T>::stack(dra::size_t sz):
s_(nullptr),
sz_(STK_UNINITIALIZED_VALUE),
msz_(STK_UNINITIALIZED_VALUE),
top_(STK_EMPTY_STACK),
buffer_(STK_DEFAULT_BUFFER_SIZE)
{
	resize(sz);
}

template<class T>
dra::stack<T>::stack(const stack& s)
{
	*this = s;
}

template<class T>
dra::stack<T>::stack(std::initializer_list<T> il):
s_(nullptr),
sz_(STK_UNINITIALIZED_VALUE),
msz_(STK_UNINITIALIZED_VALUE),
top_(STK_EMPTY_STACK),
buffer_(STK_DEFAULT_BUFFER_SIZE)
{
	resize(il.size());
	
	for(auto &val : il){
		top_++;
		s_[top_] = val;
	}
}

template<class T>
dra::stack<T>::~stack(void)
{
	if(s_ != nullptr)
		delete[] s_;
}

template<class T>
dra::stack<T>& dra::stack<T>::operator=(const stack& s)
{
	resize(s.sz_);
	
	for(int i = 0; i < sz_; i++)
		s_ = s.s_;
	
}

//==============================================================================
//==================================================================== Capacidad
//==============================================================================
template<class T>
bool dra::stack<T>::empty(void) const
{
	return (top_ == STK_EMPTY_STACK);
}

template<class T>
dra::size_t dra::stack<T>::size(void) const
{
	return sz_;
}

template<class T>
void dra::stack<T>::resize(size_t new_sz)
{
	if((new_sz > msz_)  || (s_ == nullptr)){
		if(new_sz > STK_MAX_SIZE)
			throw exception::length_error("Exceeded max vector size 'STK_MAX_SIZE'");
		sz_ = new_sz;
		
		if((sz_+buffer_) > STK_MAX_SIZE)
			buffer_ = sz_ - STK_MAX_SIZE;
		
		msz_ = sz_ + buffer_;
		
		T *tmp_ptr = nullptr;
		
		try{
			tmp_ptr = new T[msz_];
		}catch(...){
			throw exception::mem_error("Memory error (full memory?)");
		}
		
		if(s_ != nullptr){
			memcpy(tmp_ptr, s_, sz_*sizeof(T));
			delete[] s_;
		}
		s_ = tmp_ptr;
	}
	else
		sz_ = new_sz;
}

//==============================================================================
//======================================================= Acceso a los elementos
//==============================================================================
template<class T>
T& dra::stack<T>::top(void)
{
	return s_[top_];
}

template<class T>
T dra::stack<T>::top(void) const
{
	return s_[top_];
}

//==============================================================================
//================================================================ Modificadores
//==============================================================================
template<class T>
void dra::stack<T>::push(const T& val)
{
	top_++;
	if(top_ > STK_MAX_SIZE)
		throw exception::length_error("Stack overflow!");
	
	if(top_ >= sz_)
		resize(sz_+1);
	
	s_[top_] = val;
}

template<class T>
void dra::stack<T>::pop(void)
{
	if(empty())
		throw exception::length_error("Stack underflow!");
	
	top_--;
}

//==============================================================================
//========================================================================== E/S
//==============================================================================
template<class T>
std::ostream& dra::stack<T>::toStream(std::ostream& os) const
{
	if(!empty()){
		for(dra::iterator_t i = 0; i <= top_; i++)
			os << s_[i] << " ";
	}
	return os;
}

//==============================================================================
//=============================================Fin de implementación de la clase
//==============================================================================
template<class T>
std::ostream& operator<<(std::ostream& os, const dra::stack<T>& s)
{
	s.toStream(os);
	return os;
}

#endif