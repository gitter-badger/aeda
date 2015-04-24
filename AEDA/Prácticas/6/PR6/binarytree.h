/*! \file binarytree.h
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

#include <iostream>
#include <algorithm>

#include "binarynode.h"

namespace dra{

template<class T>
class binaryTree{
private:
	binaryNode<T>* root_;
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
	void insert(binaryNode<T>*);

	std::ostream& toStream(std::ostream&);
protected:
	virtual void process(binaryNode<T>*)=0; //metodo usado por los metodos para explorar el arbol
	virtual void insert(binaryNode<T>*, binaryNode<T>*)=0;
private:
	void prune(binaryNode<T>*);

	void preOrder(binaryNode<T>*);
	void postOrder(binaryNode<T>*);
	void inOrder(binaryNode<T>*);

	bool leave(binaryNode<T>*) const;
	bool empty(binaryNode<T>*) const;
	unsigned size(binaryNode<T>*) const;
	unsigned height(binaryNode<T>*) const;

	std::ostream& toStream(std::ostream&, binaryNode<T>*);
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
void binaryTree<T>::preOrder(void)
{
	preOrder(root_);
}

template<class T>
void binaryTree<T>::postOrder(void)
{
	postOrder(root_);
}

template<class T>
void binaryTree<T>::inOrder(void)
{
	inOrder(root_);
}

template<class T>
void binaryTree<T>::preOrder(binaryNode<T>* node)
{
	if(node == nullptr)
		return;
	process(node);
	postOrder(node->left());
	postOrder(node->right());
}

template<class T>
void binaryTree<T>::postOrder(binaryNode<T>* node)
{
	if(node == nullptr)
		return;
	postOrder(node->left());
	postOrder(node->right());
	process(node);
}

template<class T>
void binaryTree<T>::inOrder(binaryNode<T>* node)
{
	if(node == nullptr)
		return;
	postOrder(node->left());
	process(node);
	postOrder(node->right());
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
		return 0;

	return std::max(height(node->left()), height(node->right()))+1;
}

template<class T>
void binaryTree<T>::insert(binaryNode<T> *node)
{
	insert(node, root_);
}

template<class T>
std::ostream& binaryTree<T>::toStream(std::ostream& os)
{
	toStream(os, root_);
	return os;
}

template<class T>
std::ostream& binaryTree<T>::toStream(std::ostream& os, binaryNode<T>* root)
{
	std::cout << "Soy el metodo que imprime padre" << std::endl;er
	return os;
}

}

#endif // BINARYTREE
