#include <iostream>

#include "binarysearchtree.h"

void modo_demo(void);
void modo_esta(void);

void demo_insertar(dra::binarySearchTree<int>&);
void demo_eliminar(dra::binarySearchTree<int>&);

int main(void)
{
	unsigned modo = 1; //0 = demostracion, 1 = estadistica
	
	do{
		system("clear");
		std::cout << "┌────────────┬───────────────────────────┐" << "\n";
		std::cout << "│ Práctica 6 │ Árbol Binario de Búsqueda │" << "\n";
		std::cout << "├────────────┴───────────────────────────┤" << "\n";
		std::cout << "│ [1] Modo demostración                  │" << "\n";
		std::cout << "│ [2] Modo estadistica                   │" << "\n";
		std::cout << "│ [3] Salir                              │" << "\n";
		std::cout << "└────────────────────────────────────────┘" << "\n";
		if(modo != 1 && modo != 2 && modo != 3)
			std::cout << "✖  >";
		else
			std::cout << "   >";
		
		std::cout.flush();
		
		std::cin >> modo;
		
		switch(modo){
			case 1: modo_demo(); break;
			case 2: modo_esta(); break;
			case 3: std::cout << "Adios!" << std::endl;
		}
		
		
	}while(modo != 3);
	
	return 0;
}

void modo_demo(void)
{
	unsigned opcion = 1; //0 = demostracion, 1 = estadistica
	
	dra::binarySearchTree<int> arbol;
	
	do{
		system("clear");
		std::cout << "┌────────────┬───────────────────────────┐" << "\n";
		std::cout << "│ Práctica 6 │ Árbol Binario de Búsqueda │" << "\n";
		std::cout << "├────────────┴───────────────────────────┤" << "\n";
		std::cout << "│ [1] Insertar Clave                     │" << "\n";
		std::cout << "│ [2] Eliminar Clave                     │" << "\n";
		std::cout << "│ [3] Mostrar árbol                      │" << "\n";
		std::cout << "│ [4] Atrás                              │" << "\n";
		std::cout << "└────────────────────────────────────────┘" << "\n";
		if(opcion != 1 && opcion && 2 && opcion != 3 && opcion != 4)
			std::cout << "✖  >";
		else
			std::cout << "   >";
		
		std::cout.flush();
		
		std::cin >> opcion;
		
		switch(opcion){
			case 1: demo_insertar(arbol); break;
			case 2: demo_eliminar(arbol); break;
			case 3: arbol.toStream(std::cout); std::cin.ignore().get(); break;
		}
		
		
	}while(opcion != 4);
}

void demo_insertar(dra::binarySearchTree<int>& arbol)
{
	unsigned clave;
	std::cout << "Introduce una clave (int): "; std::cout.flush();
	std::cin >> clave;
	
	arbol.dra::binaryTree<int>::insert(clave);
}

void demo_eliminar(dra::binarySearchTree<int>& arbol)
{
	unsigned clave;
	std::cout << "Introduce una clave (int): "; std::cout.flush();
	std::cin >> clave;
	
	arbol.dra::binaryTree<int>::erase(clave);
}

void modo_esta(void)
{
	//bar
}