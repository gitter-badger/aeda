#include <iostream>

#include "binarysearchtree.h"


int main()
{

	dra::binarySearchTree<int> mi_arbol;
	//Funciona

	mi_arbol.dra::binaryTree<int>::insert(new dra::binaryNode<int>(5));
	mi_arbol.dra::binaryTree<int>::insert(new dra::binaryNode<int>(1));
	mi_arbol.dra::binaryTree<int>::insert(new dra::binaryNode<int>(6));

	mi_arbol.dra::binaryTree<int>::toStream(std::cout);

	//No funciona
	/*
	mi_arbol.insert(new dra::binaryNode<int>(5));
	mi_arbol.insert(new dra::binaryNode<int>(1));
	mi_arbol.insert(new dra::binaryNode<int>(6));

	mi_arbol.dra::toStream(std::cout);*/


	return 0;
}

