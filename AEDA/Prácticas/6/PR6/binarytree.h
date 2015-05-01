
#ifndef BINARYTREE
#define BINARYTREE

#include "binarynode.h"

#include <iostream>
#include <iomanip> //std::setw
#include <vector>

namespace dra{


template<class T>
class binaryTree{
private: //atributes
	binaryNode<T>* root_;
public: //methods
	//constructores
	binaryTree(void);
	~binaryTree(void);

	//metodos para sacar el arbol
	void postOrder(void);

	//metodos de insericon
	void insert(const T& data);

	//metodos de informacion del arbol
	bool empty(void) const;
	unsigned size(void) const;
	unsigned height(void) const;

	//utilidades del arbol
	binaryNode<T>* find(T& data);
private:
	//metodos para sacar el arbol
	void preOrder(binaryNode<T>* node);
	void postOrder(binaryNode<T>* node);
	void inOrder(binaryNode<T>* node);

	//metodos para insertar algo en el arbol
	void insert(binaryNode<T>* node, binaryNode<T>*& root);
	void insertBalanced(binaryNode<T>* node);
	void insertOrdered(binaryNode<T>* node);

	//metodos para podar el arbol
	void prune(binaryNode<T>* node);

	//metodos de informacion del arbol
	bool leave(binaryNode<T>* node) const;
	bool empty(binaryNode<T> *node) const;
	unsigned size(binaryNode<T> *node) const;
	unsigned height(binaryNode<T> *node) const;
};

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
void binaryTree<T>::postOrder(void)
{
	postOrder(root_);
	std::cout << std::endl;
}

template<class T>
void binaryTree<T>::postOrder(binaryNode<T>* node)
{
	if(node == nullptr)
		return;
	postOrder(node->left());
	postOrder(node->right());
	std::cout << node->data() << " ";
}

template<class T>
void binaryTree<T>::insert(const T& data)
{
	insert(new dra::binaryNode<T>(data), root_);
}

template<class T>
void binaryTree<T>::insert(binaryNode<T>* node, binaryNode<T>*& root)
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

template<class T>
void binaryTree<T>::prune(binaryNode<T>* node)
{
	if(empty(node))
		return;
	prune(node->left());
	prune(node->right());
	delete node;
	node = nullptr;
}

template<class T>
unsigned binaryTree<T>::size(void) const
{
	return size(root_);
}

template<class T>
unsigned binaryTree<T>::size(binaryNode<T>* node) const
{
	if(empty(node))
		return 0;
	return(1 + size(node->left()) + size(node->right()));
}

template<class T>
bool binaryTree<T>::leave(binaryNode<T>* node) const
{
	return empty(node->left()) && empty(node->right());
}

template<class T>
bool binaryTree<T>::empty(void) const
{
	return empty(root_);
}

template<class T>
bool binaryTree<T>::empty(binaryNode<T>* node) const
{
	return node == nullptr;
}

template<class T>
unsigned binaryTree<T>::height(void) const
{
	return height(root_);
}

template<class T>
unsigned binaryTree<T>::height(binaryNode<T> *node) const
{
	if(node == nullptr)
		return 1;

	unsigned left_height = height(node->left());
	unsigned right_height = height(node->right());

	return left_height>right_height?left_height:right_height;
}

}

#endif // BINARYTREE
