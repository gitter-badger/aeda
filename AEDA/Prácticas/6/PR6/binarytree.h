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
	/** @name Constructores y destructor*/
	///@{
	/** \brief Constructor por defecto */
	binaryTree(void);
	/** \brief Destructor */
	~binaryTree(void);
	///@}
	/** @name Recorridos */
	///@{
	preOrder(void);
	postOrder(void);
	inOrder(void);
	///@}
	/** @name Inserciones */
	///@{
	void insertLeave(binaryNode<T>* leave);
	void insertRoot(binaryNode<T>* root);
	void insertBalanced(binaryNode<T>* node);
	void insertOrdered(binaryNode<T>* node);
	///@}
	/** @name Eliminaciones */
	///@{
	void delete(T& data);
	///@}
	/** @name Utilidades */
	///@{
	bool empty(void) const;
	binaryNode<T>* find(T& data);
	///@}
};

binaryTree::binaryTree(void):
root_(nullptr)
{}

binaryTree::~binaryTree(void)
{
	if(!empty())
		delete root_
}

}

#endif // BINARYTREE

