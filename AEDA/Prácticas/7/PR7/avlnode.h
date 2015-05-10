#ifndef AVLNODE
#define AVLNODE

#include <iostream>

#include "node.h"


namespace dra{

template<class T>
class AVLNode : public dra::binaryNode<T>{
private:
    int bal_;
public:
    AVLNode(T, int);
    int& bal(void);
    int bal(void) const;
};

template<class T>
AVLNode<T>::AVLNode(T data, int bal):
    binaryNode<T>(data),
    bal_(bal)
{}

template<class T>
int& AVLNode<T>::bal(void)
{
    return bal_;
}

template<class T>
int AVLNode<T>::bal(void) const
{
    return bal_;
}

}

#endif // AVLNODE

