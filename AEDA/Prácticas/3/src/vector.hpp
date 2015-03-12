#ifndef _VECTOR_HPP_
#define _VECTOR_HPP_

#include <iostream>
#include <cstring> //memcpy
#include <initializer_list> //C++11

#include "debug.hpp"
#include "exceptions.hpp"

#define DEFAULT_BUFFER_SIZE 10
#define UNINITIALIZED_VALUE 0
#define MAX_SIZE 32767

namespace dra{

typedef unsigned int size_t;
typedef unsigned int buffer_t;
typedef unsigned int iterator_t;

template<class T> class vector;
}



template<class T>
class dra::vector
{
private:
    T *v_;
    size_t sz_;
    size_t msz_;
    buffer_t buffer_;
    iterator_t first_;
    iterator_t last_;
public:
    //================================== Constructores, destructores y operador=
    vector(void);
    vector(size_t);
    vector(dra::iterator_t, dra::iterator_t); //Rango: [first, last)
    vector(const vector<T>&);
    vector(const vector<T>&, dra::iterator_t, dra::iterator_t);
    vector(std::initializer_list<T> il);
    ~vector(void);
    vector& operator=(const vector& it);
    //================================================================ Capacidad
    inline dra::size_t size(void) const;
    inline dra::size_t max_size(void) const;
    void resize(dra::size_t);
    inline dra::size_t capacity(void) const;
    bool empty(void) const;
    //======================================================= Acceso a elementos
    T& operator[](dra::iterator_t);
    T operator[](dra::iterator_t) const;
    T& at(dra::iterator_t);
    T at(dra::iterator_t) const;
    T& front(void);
    T front(void) const;
    T& back(void);
    T back(void) const;
    T* data(void);
    //============================================================ Modificadores
    void push_back(const T&);
    void pop_back(void);
    void insert(dra::iterator_t, const T&);
    void erase(dra::iterator_t);
    //====================================================================== E/S
    std::ostream& toStream(std::ostream&) const;
};

//==============================================================================
//====================================== Constructores, destructores y operador=
//==============================================================================
template<class T>
dra::vector<T>::vector(void):
    v_(nullptr),
    sz_(UNINITIALIZED_VALUE),
    msz_(DEFAULT_BUFFER_SIZE),
    buffer_(DEFAULT_BUFFER_SIZE),
    first_(UNINITIALIZED_VALUE),
    last_(UNINITIALIZED_VALUE)
{}

template<class T>
dra::vector<T>::vector(size_t sz):
    v_(nullptr),
    sz_(sz),
    msz_(sz + DEFAULT_BUFFER_SIZE),
    buffer_(DEFAULT_BUFFER_SIZE),
    first_(UNINITIALIZED_VALUE),
    last_(sz_)
{
    if(msz_ > MAX_SIZE)
        throw exception::length_error("Exceeded max vector size 'MAX_SIZE'");
    try{
        v_ = new T[msz_];
    }catch(...){
        throw exception::mem_error("Memory error (full memory?)");
    }
}

template<class T>
dra::vector<T>::vector(iterator_t first, iterator_t last):
    v_(nullptr),
    sz_(last-first),
    msz_(sz_ + DEFAULT_BUFFER_SIZE),
    buffer_(DEFAULT_BUFFER_SIZE),
    first_(first),
    last_(last)
{
    if(msz_ > MAX_SIZE)
        throw exception::length_error("Exceeded max vector size 'MAX_SIZE'");
    try{
        v_ = new T[msz_];
    }catch(...){
        throw exception::mem_error("Memory error (full memory?)");
    }
}

template<class T>
dra::vector<T>::vector(const vector<T>& vec):
    v_(nullptr)
{
    *this = vec;
}

dra::vector<T>(const vector<T>& vec, dra::iterator_t first, dra::iterator_t last):
    v_(nullptr),
    sz_(last-first),
    msz_(sz_ + DEFAULT_BUFFER_SIZE),
    buffer_(DEFAULT_BUFFER_SIZE),
    first_(first),
    last_(last)
{
    
}

template<class T>
dra::vector<T>::vector(std::initializer_list<T> il):
    v_(nullptr),
    sz_(il.size()),
    msz_(sz_ + DEFAULT_BUFFER_SIZE),
    buffer_(DEFAULT_BUFFER_SIZE),
    first_(UNINITIALIZED_VALUE),
    last_(sz_)
{
    if(msz_ > MAX_SIZE)
        throw exception::length_error("Exceeded max vector size 'MAX_SIZE'");
    try{
        v_ = new T[msz_];
    }catch(...){
        throw exception::mem_error("Memory error (full memory?)");
    }

    iterator_t it = 0;
    for(auto &i : il){
        v_[it] = i;
        it++;
    }
}

template<class T>
dra::vector<T>::~vector(void)
{
    if(v_ != nullptr)
        delete[] v_;
}

//==============================================================================
//==================================================================== Capacidad
//==============================================================================
template<class T>
dra::size_t dra::vector<T>::size(void) const
{
    return sz_;
}

template<class T>
dra::size_t dra::vector<T>::max_size(void) const
{
    return MAX_SIZE;
}

template<class T>
void dra::vector<T>::resize(dra::size_t new_sz)
{
    sz_ = new_sz;
    if(new_sz > msz_){

        if(sz_ > MAX_SIZE)
            throw exception::length_error("Exceeded max vector size 'MAX_SIZE'");

        if((sz_ + buffer_) > (MAX_SIZE))
            buffer_ = 0; //Pasamos de usar el buffer

        msz_ = sz_ + buffer_;

        T* tmp_ptr = nullptr;
        try{
            tmp_ptr = new T[msz_];
        }catch(...){
            throw exception::mem_error("Memory error (full memory?)");
        }
        memcpy(tmp_ptr, v_, sz_*sizeof(T));

        delete[] v_;
        v_ = tmp_ptr;
    }
    last_ = sz_+first_;
}

template<class T>
inline dra::size_t dra::vector<T>::capacity(void) const
{
    return msz_;
}

template<class T>
bool dra::vector<T>::empty(void) const
{
    return (sz_ == 0);
}

//==============================================================================
//======================================================= Acceso a los elementos
//==============================================================================
template<class T>
T& dra::vector<T>::operator[](iterator_t position)
{
    return at(position);
}

template<class T>
T dra::vector<T>::operator[](iterator_t position) const
{
    return at(position);
}
template<class T>
T& dra::vector<T>::at(iterator_t position)
{
    //std::cout << *this << std::endl;
    if((position < first_) || (position >= last_) || empty())
        throw exception::out_of_range();
    else
        return v_[position-first_];
}

template<class T>
T dra::vector<T>::at(iterator_t position) const
{
    if((position < first_) || (position >= last_) || empty())
        throw exception::out_of_range();
    else
        return v_[position-first_];
}

template<class T>
T& dra::vector<T>::front(void)
{
    return at(first_);
}

template<class T>
T dra::vector<T>::front(void) const
{
    return at(first_);
}

template<class T>
T& dra::vector<T>::back(void)
{
    return at(last_-1);
}

template<class T>
T dra::vector<T>::back(void) const
{
    return at(last_-1);
}

template<class T>
T* dra::vector<T>::data(void)
{
    return v_;
}

//==============================================================================
//================================================================ Modificadores
//==============================================================================
template<class T>
void dra::vector<T>::push_back(const T& val)
{
    resize(sz_+1);
    back() = val;
}

template<class T>
void dra::vector<T>::pop_back(void)
{
    resize(sz_-1);
}

template<class T>
void dra::vector<T>::insert(dra::iterator_t there, const T& val)
{
    there-=first_;
    push_back(val);
    
    T temp;
    for(int i = there; i < sz_; i++){
        temp = back();
        back() = v_[i];
        v_[i] = temp;
    }
}

template<class T>
void dra::vector<T>::erase(dra::iterator_t that)
{
    that-=first_;
    T temp;
    
    for(int i = sz_-1; i > that; i--){
        temp = v_[i];
        v_[i] = v_[that];
        v_[that] = temp;
    }
    
    pop_back();
}

//==============================================================================
//========================================================================== E/S
//==============================================================================
template<class T>
std::ostream& dra::vector<T>::toStream(std::ostream& os) const
{
    for(int i = 0; i < sz_; i++)
        os << v_[i] << ", ";
    os << "\b\b";
    return os;
}


//==============================================================================
//=============================================Fin de implementación de la clase
//==============================================================================
template<class T>
std::ostream& operator<<(std::ostream& os, const dra::vector<T>& it)
{
    return it.toStream(os);
}

#endif
