#ifndef _NODE_HPP_
#define _NODE_HPP_

#include <iostream>

namespace dra{
    template<class T> class node;
}

template<class T>
class dra::node{
private:
    node *next_;
    T data_;
public:
    node(void);
    node(const T& data);
    ~node(void);
    
    node*& next(void);
    node* next(void) const;
    
    T& data(void);
    T data(void) const;
    
    node<T>& operator=(const node<T>&);
    
    std::ostream& toStream(std::ostream& os) const;
};

template<class T>
dra::node<T>::node(void):
next_(nullptr),
data_()
{}

template<class T>
dra::node<T>::node(const T& data):
next_(nullptr),
data_(data)
{}

template<class T>
dra::node<T>::~node(void)
{}

template<class T>
dra::node<T>*& dra::node<T>::next(void)
{
    return next_;
}

template<class T>
dra::node<T>* dra::node<T>::next(void) const
{
    return next_;
}

template<class T>
T& dra::node<T>::data(void)
{
    return data_;
}

template<class T>
T dra::node<T>::data(void) const
{
    return data_;
}

template<class T>
dra::node<T>& dra::node<T>::operator=(const node<T>& n)
{
    data_ = n.data_;
    return *this;
}

template<class T>
std::ostream& dra::node<T>::toStream(std::ostream& os) const
{
    if(next_ != nullptr)
        os << "[ " << data_ << " ][" << next_ << "]->";
    else
        os << "[ " << data_ << " ][nullptr]";
    return os;
}

//==============================================================================
// Fin de implementación de la clase
//==============================================================================

template<class T>
std::ostream& operator<<(std::ostream& os, const dra::node<T>& n)
{
    return n.toStream(os);
}

#endif