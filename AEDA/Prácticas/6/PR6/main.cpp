#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

#include "binarysearchtree.h"
#include "dni.h"

void modo_demo(void);
void modo_esta(void);

void demo_insertar(dra::binarySearchTree<dra::dni>&, bool demo = false);
void demo_eliminar(dra::binarySearchTree<dra::dni>&, bool demo = false);

unsigned digits(unsigned i);
std::ostream& indent(unsigned cuantity, unsigned value, std::ostream& os);

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
	
	dra::binarySearchTree<dra::dni> arbol;
	
	do{
		system("clear");
		std::cout << "┌────────────┬───────────────────────────┬───────────────────┐" << "\n";
		std::cout << "│ Práctica 6 │ Árbol Binario de Búsqueda │ Modo demostración │" << "\n";
		std::cout << "├────────────┴───────────────────────────┴───────────────────┤" << "\n";
		std::cout << "│ [1] Insertar Clave                                         │" << "\n";
		std::cout << "│ [2] Eliminar Clave                                         │" << "\n";
		std::cout << "│ [3] Mostrar árbol                                          │" << "\n";
		std::cout << "│ [4] Atrás                                                  │" << "\n";
		std::cout << "└────────────────────────────────────────────────────────────┘" << "\n";
		
		
		
		if(opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4)
			std::cout << "✖  >";
		else
			std::cout << "   >";
		
		std::cout.flush();
		
		std::cin >> opcion;
		
		switch(opcion){
			case 1: demo_insertar(arbol, true); break;
			case 2: demo_eliminar(arbol, true); break;
			case 3: arbol.toStream(std::cout); std::cin.ignore().get(); break;
		}
		
		
	}while(opcion != 4);
}

void demo_insertar(dra::binarySearchTree<dra::dni>& arbol, bool demo)
{
	dra::dni dummy;
	
	if(demo){
		unsigned clave;
		std::cout << "Introduce una clave (int): "; std::cout.flush();
		std::cin >> clave;
		dummy.value() = clave;
	}
		
	arbol.dra::binaryTree<dra::dni>::insert(dummy);
}

void demo_eliminar(dra::binarySearchTree<dra::dni>& arbol, bool demo)
{
	dra::dni dummy;
	
	if(demo){
		unsigned clave;
		std::cout << "Introduce una clave (int): "; std::cout.flush();
		std::cin >> clave;
		dummy.value() = clave;
	}
		
	arbol.dra::binaryTree<dra::dni>::erase(dummy);
}

void modo_esta(void)
{
	unsigned opcion = 1; //0 = demostracion, 1 = estadistica
	unsigned numero_pruebas = 10;
	unsigned cantidad_nodos = 10;
	
	dra::binarySearchTree<dra::dni> arbol;
	
	do{
		system("clear");
		std::cout << "┌────────────┬───────────────────────────┬──────────────────┐" << "\n";
		std::cout << "│ Práctica 6 │ Árbol Binario de Búsqueda │ Modo estadística │" << "\n";
		std::cout << "├────────────┴───────────────────────────┴──────────────────┤" << "\n";
		std::cout << "│ Cantidad de nodos actuales: " << cantidad_nodos << std::setw(33 - digits(cantidad_nodos)) << "│" <<"\n";
		std::cout << "│ Numero de pruebas actual: "   << numero_pruebas << std::setw(35 - digits(numero_pruebas)) << "│" <<"\n";
		std::cout << "│ [1] Cambiar numero de nodos en el árbol                   │" << "\n";
		std::cout << "│ [2] Cambiar número de pruebas                             │" << "\n";
		std::cout << "│ [3] Ejecutar                                              │" << "\n";
		std::cout << "│ [4] Atrás                                                 │" << "\n";
		std::cout << "└───────────────────────────────────────────────────────────┘" << "\n";
		
		if(opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4)
			std::cout << "✖  >";
		else
			std::cout << "   >";
		
		std::cout.flush();
		
		std::cin >> opcion;
		
		switch(opcion){
			case 1:{
				std::cout << "Introduce la cantidad de nodos: "; std::cout.flush();
				std::cin >> cantidad_nodos;
			} break;
			case 2:{
				std::cout << "Introduce la cantidad de pruebas: "; std::cout.flush();
				std::cin >> numero_pruebas;
			} break;
			case 3:{
				unsigned insercion_datos[3];
				unsigned busqueda_datos[3];
				
				for(int i = 0; i < numero_pruebas; i++){
					for(int j = 0; j < cantidad_nodos; j++){
						system("clear");
						std::cout << "┌────────────┬───────────────────────────┬──────────────────┐" << "\n";
						std::cout << "│ Práctica 6 │ Árbol Binario de Búsqueda │ Modo estadística │" << "\n";
						std::cout << "├────────────┴───────────────────────────┴──────────────────┤" << "\n";
						std::cout << "│ Cantidad de nodos actuales: " << cantidad_nodos << std::setw(33 - digits(cantidad_nodos)) << "│" <<"\n";
						std::cout << "│ Numero de pruebas actual: "   << numero_pruebas << std::setw(35 - digits(numero_pruebas)) << "│" <<"\n";
						std::cout << "│ [1] Cambiar numero de nodos en el árbol                   │" << "\n";
						std::cout << "│ [2] Cambiar número de pruebas                             │" << "\n";
						std::cout << "│ [3] Ejecutar                                              │" << "\n";
						std::cout << "│ [4] Atrás                                                 │" << "\n";
						std::cout << "└───────────────────────────────────────────────────────────┘" << "\n";
						std::cout << "┌───────────┬───────┬─────────┬────────┬───────┬────────┐" << "\n";
						std::cout << "│ Operación │ Nodos │ Pruebas │ Minimo │ Medio │ Máximo │" << "\n";
						std::cout << "│ Inserción │" << j << std::setw(10 - digits(j)) << "│" << i << std::setw(12 - digits(i)) << "│" << "\n";
						std::cout << "│ Búsqueda  │" << j << std::setw(10 - digits(j)) << "│" << i << std::setw(12 - digits(i)) << "│" << "\n";
						std::cin.ignore().get();
					}
				}
			} break;
		}
	
	}while(opcion != 4);
}

unsigned digits(unsigned i)
{
    return i > 0 ? (int) log10 ((double) i) + 1 : 1;
}