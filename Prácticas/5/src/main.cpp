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
void probar_algoritmo(unsigned tamano, unsigned algoritmo);
unsigned ejecutar_algoritmo(std::vector<dra::key*> &vec, unsigned modo, unsigned algoritmo);


void modo_estadistica(void);

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
		case 'A': modo_estadistica(); break;
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
	std::cout << " x) Radi[x]Sort\n"; //4
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
		case 'x':
		case 'X': algoritmo = 5; break;
		case 'a':
		case 'A': quedarse = false; break;
		default: error = 1;
		}
		if(algoritmo != 999)
			probar_algoritmo(tamano, algoritmo);
	}
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

void probar_algoritmo(unsigned tamano, unsigned algoritmo)
{
	std::vector<dra::key*> test;

	for(unsigned i = 0; i < tamano; i++)
		test.push_back(new dra::key_human_dni(new dra::human));

	system("clear");
	std::cout << "[PROGRAMA] Tu vector antes de empezar esta asi:" << std::endl;
	for(int i = 0; i < test.size(); i++)
		std::cout << test[i]->value() << std::endl;
	std::cin.ignore().get();


	unsigned comparaciones = ejecutar_algoritmo(test, 1, algoritmo);


	system("clear");
	std::cout << "[PROGRAMA] Hecho! tu vector ya esta ordenado, me ha tomado " << comparaciones << " pasos" << std::endl;
	for(int i = 0; i < test.size(); i++)
		std::cout << test[i] << std::endl;
	std::cin.get();

	for(unsigned i = 0; i < tamano; i++)
		delete test[i];

}

unsigned ejecutar_algoritmo(std::vector<dra::key*> &vec, unsigned modo, unsigned algoritmo)
{
	unsigned comparaciones = 0;

	switch(algoritmo){
	case 0: comparaciones = dra::insercion(vec, modo); break;
	case 1: comparaciones = dra::seleccion(vec, modo); break;
	case 2: comparaciones = dra::shellsort(vec, modo); break;
	case 3: comparaciones = dra::quickSort(vec, modo); break;
	case 4: comparaciones = dra::mergeSort(vec, modo); break;
	case 5: comparaciones = dra::radixSort(vec, modo); break;
	}

	return comparaciones;
}


/**********************************************************
 * Modo estadistica
 **********************************************************/

void modo_estadistica(void)
{
	unsigned tamano;
	unsigned pruebas;

	const unsigned cantidad_algoritmos = 5;


	std::cout << "==========================================\n";
	std::cout << "|| AEDA | Practica 5 | Modo estadistica ||\n";
	std::cout << "==========================================\n";
	std::cout << "\n";
	std::cout << "Escribe el tamano de la secuencia a ordenar:\n";
	std::cout << "   >";

	std::cout.flush();

	std::cin >> tamano;

	std::cout << "Escribe la cantidad de pruebas a realizar\n";
	std::cout << "   >";

	std::cout.flush();

	std::cin >> pruebas;


	long unsigned comparaciones[cantidad_algoritmos][5]; //0=actual 1=minimo, 2=medio, 3=maximo, 4=acumulado

	for(int i = 0; i < cantidad_algoritmos; i++){
		for(int j = 0; j < 5; j++){
			if(j!=1)
				comparaciones[i][j] = 0;
			else
				comparaciones[i][j] = 99999;
		}
	}



	for(unsigned z = 0; z < pruebas; z++){
		std::vector<dra::key*> test;

		for(unsigned j = 0; j < tamano; j++)
			test.push_back(new dra::key_human_dni(new dra::human));

		std::vector<dra::key*> test_backup = test;

		for(unsigned j = 0; j < cantidad_algoritmos; j++){
			test = test_backup;
			comparaciones[j][0] = ejecutar_algoritmo(test, 0, j);
			if(comparaciones[j][1] > comparaciones[j][0])
				comparaciones[j][1] = comparaciones[j][0];
			if(comparaciones[j][3] < comparaciones[j][0])
				comparaciones[j][3] = comparaciones[j][0];
			comparaciones[j][4] += comparaciones[j][0];


			system("clear");
			std::cout << "==========================================\n";
			std::cout << "|| AEDA | Practica 5 | Modo estadistica ||\n";
			std::cout << "==========================================\n";
			std::cout << "\n";
			printf("|%10s|%10s|%10s|%10s|%10s|\n", "Algoritmo", "Minimo", "Medio", "Maximo", "Acumulado");
			for(int k = 0; k < cantidad_algoritmos; k++){
				switch(k){
				case 0: printf("|%10s", "Insercion"); break;
				case 1: printf("|%10s", "Seleccion"); break;
				case 2: printf("|%10s", "ShellSort"); break;
				case 3: printf("|%10s", "QuickSort"); break;
				case 4: printf("|%10s", "MergeSort"); break;
				default: printf("|%10s", "???????"); break;
				}
				printf("|%10lu|%10lu|%10lu|%10lu|\n", comparaciones[k][1], comparaciones[k][2], comparaciones[k][3], comparaciones[k][4]);
			}
		}
		//usleep(50000);
		for(unsigned j = 0; j < tamano; j++)
			delete test[j];
	}
	for(unsigned j = 0; j < cantidad_algoritmos; j++){
		comparaciones[j][2] = comparaciones[j][4] / pruebas;
	}


	system("clear");
	std::cout << "==========================================\n";
	std::cout << "|| AEDA | Practica 5 | Modo estadistica ||\n";
	std::cout << "==========================================\n";
	std::cout << "\n";
	printf("|%10s|%10s|%10s|%10s|%10s|\n", "Algoritmo", "Minimo", "Medio", "Maximo", "Acumulado");
	for(int k = 0; k < cantidad_algoritmos; k++){
		switch(k){
		case 0: printf("|%10s", "Insercion"); break;
		case 1: printf("|%10s", "Seleccion"); break;
		case 2: printf("|%10s", "ShellSort"); break;
		case 3: printf("|%10s", "QuickSort"); break;
		case 4: printf("|%10s", "MergeSort"); break;
		default: printf("|%10s", "???????"); break;
		}
		printf("|%10lu|%10lu|%10lu|%10lu|\n", comparaciones[k][1], comparaciones[k][2], comparaciones[k][3], comparaciones[k][4]);
	}
	std::cin.ignore().get();
}

