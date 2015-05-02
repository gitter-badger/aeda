#include <iostream>

#include "binarysearchtree.h"
#include "dni.h"

/*

		_____52_____
	   /            \
	__28__        __79__
   /      \      /      \
  14      40    76      92
 /  \    /      /       /
10  26  33     63      81

Preorden.... 52 28 14 10 26 40 33 79 76 63 92 81
Postorden... 10 26 14 33 40 28 63 76 81 92 79 52
InOrden..... 10 14 26 28 33 40 52 63 76 79 81 92
Por Niveles. 52 28 79 14 40 76 92 10 26 33 63 81


*/

void test_uno(void);
void test_dos(void);

int main()
{
	test_dos();
	return 0;
}

void test_uno(void)
{
	dra::binarySearchTree<int> mi_arbol;

	//mi_arbol.insert(new dra::binaryNode<int>(5)); //No funciona, y debería

	mi_arbol.dra::binaryTree<int>::insert(new dra::binaryNode<int>(52));

	mi_arbol.dra::binaryTree<int>::insert(new dra::binaryNode<int>(28));
	mi_arbol.dra::binaryTree<int>::insert(new dra::binaryNode<int>(79));

	mi_arbol.dra::binaryTree<int>::insert(new dra::binaryNode<int>(14));
	mi_arbol.dra::binaryTree<int>::insert(new dra::binaryNode<int>(40));
	mi_arbol.dra::binaryTree<int>::insert(new dra::binaryNode<int>(76));
	mi_arbol.dra::binaryTree<int>::insert(new dra::binaryNode<int>(92));

	mi_arbol.dra::binaryTree<int>::insert(new dra::binaryNode<int>(10));
	mi_arbol.dra::binaryTree<int>::insert(new dra::binaryNode<int>(26));
	mi_arbol.dra::binaryTree<int>::insert(new dra::binaryNode<int>(33));
	mi_arbol.dra::binaryTree<int>::insert(new dra::binaryNode<int>(63));
	mi_arbol.dra::binaryTree<int>::insert(new dra::binaryNode<int>(81));


	std::cout << "PreOrder.... "; mi_arbol.preOrder(); std::cout << std::endl;
	std::cout << "postOrder... "; mi_arbol.postOrder(); std::cout << std::endl;
	std::cout << "inOrder..... "; mi_arbol.inOrder(); std::cout << std::endl;
	std::cout << "levelOrder.. "; mi_arbol.levelOrder(); std::cout << std::endl;

    mi_arbol.toStream(std::cout);


	std::cout << "Voy a hacer una instancia de un DNI" << std::endl;
	
	dra::dni mi_dni;
	
	std::cout << "El valor que ha cogido fue: " << mi_dni.value() << std::endl;
}

void test_dos(void)
{
	dra::binarySearchTree<dra::dni> mi_arbol;
	
	mi_arbol.dra::binaryTree<dra::dni>::insert(new dra::binaryNode<dra::dni>);
	mi_arbol.dra::binaryTree<dra::dni>::insert(new dra::binaryNode<dra::dni>);
	mi_arbol.dra::binaryTree<dra::dni>::insert(new dra::binaryNode<dra::dni>);
	mi_arbol.dra::binaryTree<dra::dni>::insert(new dra::binaryNode<dra::dni>);
	mi_arbol.dra::binaryTree<dra::dni>::insert(new dra::binaryNode<dra::dni>);
	mi_arbol.dra::binaryTree<dra::dni>::insert(new dra::binaryNode<dra::dni>);
	mi_arbol.dra::binaryTree<dra::dni>::insert(new dra::binaryNode<dra::dni>);
	mi_arbol.dra::binaryTree<dra::dni>::insert(new dra::binaryNode<dra::dni>);
	mi_arbol.dra::binaryTree<dra::dni>::insert(new dra::binaryNode<dra::dni>);
	mi_arbol.dra::binaryTree<dra::dni>::insert(new dra::binaryNode<dra::dni>);
	mi_arbol.dra::binaryTree<dra::dni>::insert(new dra::binaryNode<dra::dni>);
	mi_arbol.dra::binaryTree<dra::dni>::insert(new dra::binaryNode<dra::dni>);
	mi_arbol.dra::binaryTree<dra::dni>::insert(new dra::binaryNode<dra::dni>);
	
	
	std::cout << "PreOrder.... "; mi_arbol.preOrder(); std::cout << std::endl;
	std::cout << "postOrder... "; mi_arbol.postOrder(); std::cout << std::endl;
	std::cout << "inOrder..... "; mi_arbol.inOrder(); std::cout << std::endl;
	std::cout << "levelOrder.. "; mi_arbol.levelOrder(); std::cout << std::endl;

    mi_arbol.toStream(std::cout);
}