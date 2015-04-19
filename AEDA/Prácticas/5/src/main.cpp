#include <iostream>
#include <vector>

#include "key.hpp"
#include "key_human.hpp"
#include "key_human_dni.hpp"
#include "human.hpp"
#include "algorithm.hpp"


/*
void menu(unsigned &modo, unsigned &algoritmo, unsigned &tamano, bool &salir);
void get_modo(int indice);
void get_algoritmo(int indice);
void editar_modo(unsigned &modo);
void editar_algor4itmo(unsigned &algoritmo);
void editar_tamano(unsigned &tamano);
void ejecutar_algoritmo(unsigned &modo, unsigned &algoritmo, unsigned &tamano);
*/
int main(void)
{

	std::vector<dra::key*> test;

	for(int i = 0; i < 5; i++){
		dra::key* dummy2 = new dra::key_human_dni(new dra::human);
		test.push_back(dummy2);
	}

	for(int i = 0; i < 5; i++){
		std::cout << test[i] << std::endl;
	}

	for(int i = 0; i < 5; i++){
		delete test[i];
	}
}
/*

void menu(unsigned &modo, unsigned &algoritmo, unsigned &tamano, bool &salir)
{
	system("clear");

	int seleccion;

	std::cout << "=======================" << std::endl;
	std::cout << "|| Practica 5 | AEDA ||" << std::endl;
	std::cout << "=======================" << std::endl;
	std::cout << std::endl;
	std::cout << "1. Modo: "; get_modo(modo);
	std::cout << "2. Algoritmo: "; get_algoritmo(algoritmo);
	std::cout << "3. Tamano: " << tamano << std::endl;
	std::cout << "4. Ejecutar" << std::endl;
	std::cout << "5. Salir" << std::endl;
	std::cout << std::endl;
	std::cout << "   >";

	switch(seleccion){

	case 1: std::cout << "Editando el modo" << std::endl; editar_modo(modo); break;
	case 2: std::cout << "Editando el algoritmo" << std::endl; editar_algoritmo(algoritmo); break;
	case 3: std::cout << "Editando el tamano" << std::endl; editar_tamano(tamano); break;
	case 4: std::cout << "Ejecutando" << std::endl; break;
	case 5: std::cout << "Saliendo" << std::endl; salir = true; break;
	case 6: std::cout << "Opcion invalida..." << std::endl; break;
	}
	std::cin.ignore().get();
}

void get_modo(int indice)
{
	switch(indice){
	case 1: std::cout << "Demostracion" << std::endl; break;
	case 2: std::cout << "Estadistica" << std::endl; break;
	default: std::cout << "DESCONOCIDO" << std::endl; break;
	}
}

void get_algoritmo(int indice)
{
	switch(indice){
	case 1: std::cout << "Insercion" << std::endl; break;
	case 2: std::cout << "Selección" << std::endl; break;
	case 3: std::cout << "Shellsort" << std::endl; break;
	case 4: std::cout << "QuickSort" << std::endl; break;
	case 5: std::cout << "MergeSort" << std::endl; break;
	default: std::cout << "DESCONOCIDO" << std::endl; break;
	}
}

void editar_modo(unsigned &modo)
{
	modo = 999;
	std::cout << "1. Modo demostracion" << std::endl;
	std::cout << "2. Modo estadistica" << std::endl;

	while(modo == 999)
	{
		std::cout << "   >";
		std::cin >> modo;
		switch(modo){
		case 1:
		case 2: std::cout << "Introducido correctamente" << std::endl; break;
		default: modo = 999; std::cout << "Eleccion erronea, introduce otra" << std::endl;
		}
	}
}

void editar_algoritmo(unsigned &algoritmo)
{
	algoritmo = 999;
	std::cout << "1. Insercion" << std::endl;
	std::cout << "2. Seleccion" << std::endl;
	std::cout << "3. Shellsort" << std::endl;
	std::cout << "4. QuickSort" << std::endl;
	std::cout << "5. MergeSort" << std::endl;

	while(algoritmo == 999)
	{
		std::cout << "   >";
		std::cin >> algoritmo;
		switch(algoritmo){
		case 1:
		case 2:
		case 3:
		case 4:
		case 5: std::cout << "Introducido correctamente" << std::endl; break;
		default: algoritmo = 999; std::cout << "Eleccion erronea, introduce otra" << std::endl;
		}
	}
}

void editar_tamano(unsigned &tamano)
{
	std::cout << "   >";
	std::cin >> tamano;
	std::cout << "Introducido correctamente" << std::endl;
}

void ejecutar_algoritmo(unsigned &modo, unsigned &algoritmo, unsigned &tamano)
{

}
*/
