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
		dra::binaryNode* nodo_ptr = new dra::binaryNode(7);
		binaryTree.insert(nodo_ptr)
		dra::binaryNode* nodo_ptr = new dra::binaryNode(1);
		binaryTree.insert(nodo_ptr)
		dra::binaryNode* nodo_ptr = new dra::binaryNode(9);
		binaryTree.insert(nodo_ptr)
		dra::binaryNode* nodo_ptr = new dra::binaryNode(2);
		binaryTree.insert(nodo_ptr)
		std::cout << test3 << std::endl;
	}
  * \endcode
*/


#ifndef BINARYTREE
#define BINARYTREE

#include "binarynode.h"

#include <iostream>

namespace dra{
	template<class T> class binaryTree;
}


template<class T>
class dra::binaryTree{
private:
	dra::binaryNode<T>* root_;
public:
	//constructores
	binaryTree(void);
	~binaryTree(void);

	//metodos para explorar el arbol
	void preOrder(void);
	void postOrder(void);
	void inOrder(void);

	//metodos de informacion del arbol
	bool empty(void) const;
	unsigned size(void) const;
	unsigned height(void) const;

	//metodos para insertar el arbol
	void insert(dra::binaryNode<T>*);
protected:
	//metodos para podar el arbol
	void prune(dra::binaryNode<T>*);

	//metodos para explorar el arbol
	void preOrder(dra::binaryNode<T>*);
	void postOrder(dra::binaryNode<T>*);
	void inOrder(dra::binaryNode<T>*);

	virtual void process(dra::binaryNode<T>*)=0; //metodo usado por los metodos para explorar el arbol

	//metodos de informacion del arbol
	bool leave(dra::binaryNode<T>*) const;
	bool empty(dra::binaryNode<T>*) const;
	unsigned size(dra::binaryNode<T>*) const;
	unsigned height(dra::binaryNode<T>*) const;

	virtual void insert(dra::binaryNode<T>*, dra::binaryNode<T>*)=0;
};

template<class T>
dra::binaryTree<T>::binaryTree(void):
root_(nullptr)
{}

template<class T>
dra::binaryTree<T>::~binaryTree(void)
{
	prune(root_);
}

template<class T>
void dra::binaryTree<T>::preOrder(void)
{
	preOrder(root_);
}

template<class T>
void dra::binaryTree<T>::postOrder(void)
{
	postOrder(root_);
}

template<class T>
void dra::binaryTree<T>::inOrder(void)
{
	inOrder(root_);
}

template<class T>
void dra::binaryTree<T>::preOrder(dra::binaryNode<T>* node)
{
	if(node == nullptr)
		return;
	process(node->data());
	postOrder(node->left());
	postOrder(node->right());
}

template<class T>
void dra::binaryTree<T>::postOrder(dra::binaryNode<T>* node)
{
	if(node == nullptr)
		return;
	postOrder(node->left());
	postOrder(node->right());
	process(node->data());
}

template<class T>
void dra::binaryTree<T>::inOrder(dra::binaryNode<T>* node)
{
	if(node == nullptr)
		return;
	postOrder(node->left());
	process(node->data());
	postOrder(node->right());
}

template<class T>
void dra::binaryTree<T>::prune(dra::binaryNode<T>* node)
{
	if(empty(node))
		return;
	prune(node->left());
	prune(node->right());
	delete node;
	node = nullptr;
}

template<class T>
unsigned dra::binaryTree<T>::size(void) const
{
	return size(root_);
}

template<class T>
unsigned dra::binaryTree<T>::size(dra::binaryNode<T>* node) const
{
	if(empty(node))
		return 0;
	return(1 + size(node->left()) + size(node->right()));
}

template<class T>
bool dra::binaryTree<T>::leave(dra::binaryNode<T>* node) const
{
	return empty(node->left()) && empty(node->right());
}

template<class T>
bool dra::binaryTree<T>::empty(void) const
{
	return empty(root_);
}

template<class T>
bool dra::binaryTree<T>::empty(dra::binaryNode<T>* node) const
{
	return node == nullptr;
}

template<class T>
unsigned dra::binaryTree<T>::height(void) const
{
	return height(root_);
}

template<class T>
unsigned dra::binaryTree<T>::height(dra::binaryNode<T> *node) const
{
	if(node == nullptr)
		return 1;

	unsigned left_height = height(node->left());
	unsigned right_height = height(node->right());

	return left_height>right_height?left_height:right_height;
}

#endif // BINARYTREE
