#include <iostream>
#include <vector>

//#include "key.hpp"
//#include "key_human.hpp"
//#include "key_human_dni.hpp"
//#include "human.hpp"
//#include "algorithm.hpp"


#include "demo.hpp"
//#include "estadistica.hpp"

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