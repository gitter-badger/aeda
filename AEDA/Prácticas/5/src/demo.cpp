#include <iostream>
#include <vector>

#include "key.hpp"
#include "key_human.hpp"
#include "key_human_dni.hpp"
#include "human.hpp"
#include "algorithm.hpp"

void cabecera_demo(int tamano, int error){
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
	
	switch(error){
		case 0: break;
		case 1: std::cout << "El modo introducido es invalido\n"; break;
		case 2: std::cout << "El tamano no puede ser mayor que 25\n"; break;
		default: std::cout << "Error desconocido\n"; break;
	}
	std::cout << "   >";
	
	std::cout.flush();
}

void editar_tamano(unsigned& tamano, unsigned& error)
{
    std::cout << "Escribe el tamano del vector\n";
	std::cout << "   >";
	std::cout.flush();
	
	std::cin >> tamano;
	
	if(tamano > 25){
		tamano = 10;
		error = 2;
	}
}

void modo_demostracion(void)
{
	char modo = 'f';
	bool quedarse = true;
	unsigned error = 0;
	
	unsigned tamano = 10;
	unsigned algoritmo = 0;
	
	while(quedarse){
		
		cabecera_demo(tamano, error);
		
		std::cin >> modo;
		
		error = 0;
		
		switch(modo){
			case 't':
			case 'T': editar_tamano(tamano, error);
			case 'a': 
			case 'A': quedarse = false; break;
			default: error = 1;
		}
	}
}