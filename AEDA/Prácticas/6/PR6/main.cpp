#include <iostream>

#include "binarysearchtree.h"
#include "dni.h"

void test_uno(void);
void test_dos(void);
void test_tres(void);
void test_cuatro(void);

int main()
{
    test_cuatro();
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

void test_tres(void)
{
    dra::binarySearchTree<dra::dni> mi_arbol;

    mi_arbol.dra::binaryTree<dra::dni>::insert(new dra::binaryNode<dra::dni>(30));
    mi_arbol.dra::binaryTree<dra::dni>::insert(new dra::binaryNode<dra::dni>(25));
    mi_arbol.dra::binaryTree<dra::dni>::insert(new dra::binaryNode<dra::dni>(15));
    mi_arbol.dra::binaryTree<dra::dni>::insert(new dra::binaryNode<dra::dni>(40));

    mi_arbol.toStream(std::cout);

    std::cout << "PreOrder.... "; mi_arbol.preOrder(); std::cout << std::endl;
    std::cout << "postOrder... "; mi_arbol.postOrder(); std::cout << std::endl;
    std::cout << "inOrder..... "; mi_arbol.inOrder(); std::cout << std::endl;
    std::cout << "levelOrder:\n"; mi_arbol.levelOrder(); std::cout << std::endl;

    mi_arbol.dra::binaryTree<dra::dni>::erase(15);

    mi_arbol.toStream(std::cout);

    std::cout << "PreOrder.... "; mi_arbol.preOrder(); std::cout << std::endl;
    std::cout << "postOrder... "; mi_arbol.postOrder(); std::cout << std::endl;
    std::cout << "inOrder..... "; mi_arbol.inOrder(); std::cout << std::endl;
    std::cout << "levelOrder:\n"; mi_arbol.levelOrder(); std::cout << std::endl;
}

void test_cuatro(void)
{
    dra::binarySearchTree<dra::dni> mi_arbol;

    mi_arbol.dra::binaryTree<dra::dni>::insert(new dra::binaryNode<dra::dni>(52));

    mi_arbol.dra::binaryTree<dra::dni>::insert(new dra::binaryNode<dra::dni>(28));
    mi_arbol.dra::binaryTree<dra::dni>::insert(new dra::binaryNode<dra::dni>(79));

    mi_arbol.dra::binaryTree<dra::dni>::insert(new dra::binaryNode<dra::dni>(14));
    mi_arbol.dra::binaryTree<dra::dni>::insert(new dra::binaryNode<dra::dni>(40));
    mi_arbol.dra::binaryTree<dra::dni>::insert(new dra::binaryNode<dra::dni>(76));
    mi_arbol.dra::binaryTree<dra::dni>::insert(new dra::binaryNode<dra::dni>(92));

    mi_arbol.dra::binaryTree<dra::dni>::insert(new dra::binaryNode<dra::dni>(10));
    mi_arbol.dra::binaryTree<dra::dni>::insert(new dra::binaryNode<dra::dni>(26));
    mi_arbol.dra::binaryTree<dra::dni>::insert(new dra::binaryNode<dra::dni>(33));
    mi_arbol.dra::binaryTree<dra::dni>::insert(new dra::binaryNode<dra::dni>(63));
    mi_arbol.dra::binaryTree<dra::dni>::insert(new dra::binaryNode<dra::dni>(81));

    mi_arbol.dra::binaryTree<dra::dni>::insert(new dra::binaryNode<dra::dni>(56));
    mi_arbol.dra::binaryTree<dra::dni>::insert(new dra::binaryNode<dra::dni>(67));
    mi_arbol.dra::binaryTree<dra::dni>::insert(new dra::binaryNode<dra::dni>(86));

    mi_arbol.dra::binaryTree<dra::dni>::insert(new dra::binaryNode<dra::dni>(73));
    mi_arbol.dra::binaryTree<dra::dni>::insert(new dra::binaryNode<dra::dni>(89));

    mi_arbol.toStream(std::cout);

    mi_arbol.dra::binaryTree<dra::dni>::erase(10);
    mi_arbol.dra::binaryTree<dra::dni>::erase(33);
    mi_arbol.dra::binaryTree<dra::dni>::erase(73);

    mi_arbol.toStream(std::cout);

    mi_arbol.dra::binaryTree<dra::dni>::erase(86);

    mi_arbol.toStream(std::cout);

    mi_arbol.dra::binaryTree<dra::dni>::erase(44);

    mi_arbol.toStream(std::cout);

    mi_arbol.dra::binaryTree<dra::dni>::erase(76);

    mi_arbol.toStream(std::cout);

    std::cout << mi_arbol.dra::binaryTree<dra::dni>::search(63) << std::endl;
}
