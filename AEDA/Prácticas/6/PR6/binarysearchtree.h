#ifndef BINARYSEARCHTREE
#define BINARYSEARCHTREE

#include "binarytree.h"

namespace dra{

template<class T>
class binarySearchTree : public binaryTree<T>{
public:
	virtual void process(binaryNode<T>*);
	virtual void insert(binaryNode<T>*, binaryNode<T>*&);
};

template<class T>
void binarySearchTree<T>::process(binaryNode<T>* node)
{
	std::cout << node->data() << " ";
}

template<class T>
void binarySearchTree<T>::insert(binaryNode<T>* node, binaryNode<T>*& root)
{
	if(root == nullptr){
		root = node;
		return;
	}
	if(node->data() <= root->data())
		insert(node, root->left());
	else
		insert(node, root->right());
}

}

#endif // BINARYSEARCHTREE

