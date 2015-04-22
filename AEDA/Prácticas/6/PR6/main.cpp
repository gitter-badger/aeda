#include <iostream>

#include "binarytree.h"


int main()
{
	dra::binaryTree<int> my_tree;

	my_tree.insert(18);
	my_tree.insert(45);
	my_tree.insert(28);



	std::cout << "Ya estan insertados los nodos" << std::endl;

	std::cin.ignore().get();

	my_tree.postOrder();


	std::cout << "\n\nYa lo acabo de sacar por pantalla" << std::endl;
	std::cin.ignore().get();


	return 0;
}

