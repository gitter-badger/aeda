/** \file binarytree.h
  * \version 1.0
  * \date 17/03/2015
  * \author Daniel Ramos Acosta
  * \brief Header que contiene la clase del Árbol Binario
  * \code
  * //Código de ejemplo
  * <iostream>
  * 
  * int main(void){
        binaryTree<int> mi_arbol;
        binaryNode* nodo_ptr = new binaryNode(7);
        binaryTree.insert(nodo_ptr)
        binaryNode* nodo_ptr = new binaryNode(1);
        binaryTree.insert(nodo_ptr)
        binaryNode* nodo_ptr = new binaryNode(9);
        binaryTree.insert(nodo_ptr)
        binaryNode* nodo_ptr = new binaryNode(2);
        binaryTree.insert(nodo_ptr)
        std::cout << test3 << std::endl;
    }
  * \endcode
*/


#ifndef BINARYTREE
#define BINARYTREE

#include "binarynode.h"

namespace dra{



template<class T>
class binaryTree{
private:
	binaryNode<T>* root_;
public:
	binaryTree(void);
	~binaryTree(void);


	void preOrder(binaryNode<T>* node = root_);
	void postOrder(binaryNode<T>* node_ = root_);
	void inOrder(binaryNode<T>* node = root_);

	void insert(binaryNode<T>* node);
	void insertBalanced(binaryNode<T>* node);
	void insertOrdered(binaryNode<T>* node);

	void prune(binaryNode<T>* node = root_);
	bool leave(binaryNode<T>* node = root_) const;

	bool empty(binaryNode<T> *node = root_) const;
	unsigned size(binaryNode<T> *node = root_) const;
	unsigned height(binaryNode<T> *node = root_) const;

	binaryNode<T>* find(T& data);
};
/*
template<class T>
binaryTree<T>::binaryTree(void):
root_(nullptr)
{}

template<class T>
binaryTree<T>::~binaryTree(void)
{
	prune(root_);
}

template<class T>
void binaryTree<T>::prune(binaryNode<T>* node = root_)
{
	if(empty(node))
		return;
	prune(node->left());
	prune(node->right());
	delete node;
	node = nullptr;
}

template<class T>
unsigned binaryTree<T>::size(binaryNode<T>* node = root_) const
{
	if(empty(node))
		return 0;
	return(1 + size(node->left()) + size(node->right()));
}

template<class T>
bool binaryTree<T>::leave(binaryNode<T>* node = root_) const
{
	return empty(node->left()) && empty(node->right());
}

template<class T>
bool binaryTree<T>::empty(binaryNode<T>* node = root_) const
{
	return node == nullptr;
}

template<class T>
unsigned binaryTree<T>::height(binaryNode<T> *node = root_) const
{
	return 0;
}
*/
}

#endif // BINARYTREE

