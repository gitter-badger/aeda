#include <iostream>

#include "binarysearchtree.h"

int main(void)
{
	dra::binarySearchTree<int> mi_arbol;
	
	mi_arbol.dra::binaryTree<int>::insert(50);
	
	mi_arbol.dra::binaryTree<int>::insert(25);
	mi_arbol.dra::binaryTree<int>::insert(75);
	
	mi_arbol.dra::binaryTree<int>::insert(10);
	mi_arbol.dra::binaryTree<int>::insert(30);
	mi_arbol.dra::binaryTree<int>::insert(70);
	mi_arbol.dra::binaryTree<int>::insert(80);
	
	mi_arbol.dra::binaryTree<int>::insert(5);
	mi_arbol.dra::binaryTree<int>::insert(11);
	
	mi_arbol.dra::binaryTree<int>::insert(29);
	mi_arbol.dra::binaryTree<int>::insert(31);
	
	mi_arbol.dra::binaryTree<int>::insert(69);
	mi_arbol.dra::binaryTree<int>::insert(71);
	
	mi_arbol.dra::binaryTree<int>::insert(79);
	mi_arbol.dra::binaryTree<int>::insert(81);
	
	mi_arbol.toStream(std::cout);
	
	return 0;
}
