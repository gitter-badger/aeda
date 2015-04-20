#include <iostream>
#include <vector>

#include "key.hpp"
#include "key_human.hpp"
#include "key_human_dni.hpp"
#include "human.hpp"
#include "algorithm.hpp"

void cabecera_demo(int tamano, int error);
void modo_demostracion(void);
void editar_tamano(unsigned& tamano, unsigned& error);
void ejecutar_algoritmo(unsigned modo, unsigned tamano, unsigned algoritmo);

int main(void)
{
	char modo = 'f';
	bool quedarse = true;
	bool error = false;

	while(quedarse){
		system("clear");

		std::cout << "=======================\n";
		std::cout << "|| AEDA | Practica 5 ||\n";
		std::cout << "=======================\n";
		std::cout << "\n";
		std::cout << "Elije el modo del programa:\n";
		std::cout << " o) Dem[o]stracion\n";
		std::cout << " a) Est[a]distica\n";
		std::cout << " q) Salir\n";
		
		
		if(error)
			std::cout << "Modo invalido, introduce otro\n";
		std::cout << "   >";

		std::cout.flush();

		std::cin >> modo;
		
		error = false;
		
		switch(modo){
		case 'o':
		case 'O': modo_demostracion(); break;
		case 'a':
		case 'A': //modo_estadistica(); break;
		case 'q':
		case 'Q': quedarse = false;
		default: error = true;
		}
	}
}

/**************************************************************************
 * Demostracion
 **************************************************************************/

void cabecera_demo(int tamano, int error)
{
	system("clear");

	std::cout << "===========================================\n";
	std::cout << "|| AEDA | Practica 5 | Modo demostracion ||\n";
	std::cout << "===========================================\n";
	std::cout << "\n";
	std::cout << "Tamano del vector actual: " << tamano << "\n";
	std::cout << " t) Edi[t]ar tamano del vector\n";
	std::cout << "Elije el algoritmo:\n";
	std::cout << " i) Inserc[i]on\n"; //0
	std::cout << " e) S[e]leccion\n"; //1
	std::cout << " o) Shells[o]rt\n"; //2
	std::cout << " u) Q[u]ickSort\n"; //3
	std::cout << " g) Mer[g]eSort\n"; //4
	std::cout << " a) Atr[a]s\n";

	switch(error){
	case 0: break;
	case 1: std::cout << "El modo introducido es invalido\n"; break;
	case 2: std::cout << "El tamano no puede ser mayor que 25\n"; break;
	default: std::cout << "Error desconocido\n"; break;
	}
	std::cout << "   >";

	std::cout.flush();
}

void modo_demostracion(void)
{
	char modo = 'f';
	bool quedarse = true;
	unsigned error = 0;

	unsigned tamano = 10;

	while(quedarse){
		unsigned algoritmo = 999;

		cabecera_demo(tamano, error);

		std::cin >> modo;

		error = 0;

		switch(modo){
		case 't':
		case 'T': editar_tamano(tamano, error); break;
		case 'i':
		case 'I': algoritmo = 0; break;
		case 'e':
		case 'E': algoritmo = 1; break;
		case 'o':
		case 'O': algoritmo = 2; break;
		case 'u':
		case 'U': algoritmo = 3; break;
		case 'g':
		case 'G': algoritmo = 4; break;
		case 'a':
		case 'A': quedarse = false; break;
		default: error = 1;
		}
		if(algoritmo != 999)
			ejecutar_algoritmo(1, tamano, algoritmo);
	}
}

void editar_tamano(unsigned& tamano, unsigned& error)
{
	std::cout << "Escribe el tamano del vector\n";
	std::cout << "   >";
	std::cout.flush();

	std::cin >> tamano;

	if(tamano > 200){
		tamano = 10;
		error = 2;
	}
}

void ejecutar_algoritmo(unsigned modo, unsigned tamano, unsigned algoritmo)
{
	std::vector<dra::key*> test;

	for(unsigned i = 0; i < tamano; i++)
		test.push_back(new dra::key_human_dni(new dra::human));

	switch(algoritmo){
		case 0: dra::insercion(test, modo); break;
		case 1: dra::seleccion(test, modo); break;
	}

	for(unsigned i = 0; i < tamano; i++)
		delete test[i];
}


/**********************************************************
 * Modo estadistica
 **********************************************************/

void modo_estadistica(void)
{
	system("clear");
	std::cout << "Foo" << std::endl;
	std::cin.ignore().get();
}
