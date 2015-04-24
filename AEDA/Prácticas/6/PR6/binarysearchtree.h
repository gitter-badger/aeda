#ifndef BINARYSEARCHTREE
#define BINARYSEARCHTREE


#include "binarytree.h"


namespace dra{
	template<class T> class binarySearchTree;
}


template<class T>
class dra::binarySearchTree : public dra::binaryTree<T>{
public:
	void process(dra::binaryNode<T>*);
};


#endif // BINARYSEARCHTREE

