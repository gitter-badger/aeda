#ifndef _SIMPLELINKEDLIST_HPP_
#define _SIMPLELINKEDLIST_HPP_

#include <iostream>

#include "node.hpp"
#include "exceptions.hpp"
//#include "debug.hpp"

namespace dra{
    template<class T> class simplelinkedlist;
}

template<class T>
class dra::simplelinkedlist
{
private:
    dra::node<T>* start_; //puntero al primer elemento de la lista enlazada
    dra::node<T>* end_; //puntero al último elemento de la lista enlazada
private:
    void first(dra::node<T>*); //se llama para la primera incersión
public:
    simplelinkedlist(void);
    ~simplelinkedlist(void);
    
    inline bool empty(void) const; //devuelve 1 si la lista está vacía
    
    void push_back(dra::node<T>*); //mete un nodo al final de la lista
    void push_front(dra::node<T>*); //mete un nodo al principio de la lista
    
    dra::node<T>* extract_back(void); //extrae el último nodo
    dra::node<T>* extract_front(void); //extrae el primer nodo
    
    simplelinkedlist<T>& operator=(const simplelinkedlist<T>&);
    
    std::ostream& toStream(std::ostream&) const;
};

template<class T>
dra::simplelinkedlist<T>::simplelinkedlist(void):
start_(nullptr),
end_(nullptr)
{}

template<class T>
dra::simplelinkedlist<T>::~simplelinkedlist(void)
{
    dra::node<T>* tmp_ptr = start_;
    while(start_ != nullptr)
    {
        start_ = start_ -> next();
        delete tmp_ptr;
        tmp_ptr = start_;
    }
}

template<class T>
void dra::simplelinkedlist<T>::first(dra::node<T>* node)
{
    node->next() = nullptr;
    start_ = node;
    end_ = node;
}

template<class T>
bool dra::simplelinkedlist<T>::empty(void) const
{
    return (start_ == nullptr);
}

template<class T>
void dra::simplelinkedlist<T>::push_back(dra::node<T>* node)
{
    if(empty()) first(node);
    else{
        node->next() = nullptr;
        end_->next() = node;
        end_ = node;
    }
}

template<class T>
void dra::simplelinkedlist<T>::push_front(dra::node<T>* node)
{
    if(empty()) first(node);
    else{
        node->next() = start_;
        start_ = node;
    }
}

template<class T>
dra::node<T>* dra::simplelinkedlist<T>::extract_back(void)
{
    if(empty())
        throw exception::length_error("List was empty");
    dra::node<T>* tmp_ptr = start_;
    if(start_ == end_){
        start_ = nullptr;
        end_ = nullptr;
    }
    else{
        while(tmp_ptr->next() != end_) //al final, tmp_ptr apunta al penúltimo nodo
            tmp_ptr = tmp_ptr->next();
        end_ = tmp_ptr;
        tmp_ptr = tmp_ptr->next();
        end_->next() = nullptr;
    }
    return tmp_ptr;
}

template<class T>
dra::node<T>* dra::simplelinkedlist<T>::extract_front(void)
{
    if(empty())
        throw exception::length_error("List was empty");
    dra::node<T>* tmp_ptr = start_;
    if(start_ == end_){
        start_ = nullptr;
        end_ = nullptr;
    }
    else{
        start_ = start_->next();
        tmp_ptr->next() = nullptr;
    }
    return tmp_ptr;
}

template<class T>
dra::simplelinkedlist<T>& dra::simplelinkedlist<T>::operator=(const simplelinkedlist<T>& list)
{
    this->~simplelinkedlist();
    dra::node<T>* tmp_ptr = list.start_;
    while(tmp_ptr != nullptr)
    {
        push_back(new dra::node<T>(tmp_ptr->data()));
        tmp_ptr = tmp_ptr->next();
    }
    return *this;
}

template<class T>
std::ostream& dra::simplelinkedlist<T>::toStream(std::ostream& os) const
{
    dra::node<T>* tmp_ptr = start_;
    while(tmp_ptr != nullptr)
    {
        os << *tmp_ptr;
        tmp_ptr = tmp_ptr->next();
    }
    return os;
}

//==============================================================================
// Fin de implementación de la clase
//==============================================================================

template<class T>
std::ostream& operator<<(std::ostream& os, const dra::simplelinkedlist<T>& list)
{
    return list.toStream(os);
}

#endif