#ifndef _ALGORITHM_HPP_
#define _ALGORITHM_HPP_

#include <vector>

#include "key.hpp"
#include "key_human.hpp"
#include "key_human_dni.hpp"
#include "human.hpp"

namespace dra{

unsigned insercion(std::vector<dra::key*> &vec, bool demo = false)
{
	unsigned comparaciones = 0;

	if(demo){
		system("clear");

		std::cout << "[PROGRAMA] Tu vector antes de empezar esta asi:" << std::endl;
		for(int i = 0; i < vec.size(); i++)
			std::cout << i << ". " << vec[i]->value() << std::endl;

		std::cin.ignore().get();
	}

	vec.insert(vec.begin(), nullptr);

	if(demo){
		system("clear");
		std::cout << "[PROGRAMA] Acabo de poner el centinela, para saber cuando hay que parar" << std::endl;
		for(int i = 0; i < vec.size(); i++){
			if(i == 0){
				std::cout << "-1. XXXXXXXX" << std::endl;
			}
			else
				std::cout << i-1 << ". " << vec[i]->value() << std::endl;
		}

		std::cin.ignore().get();
	}

	for(unsigned i = 1; i < vec.size(); i++)
	{
		unsigned j = i;

		dra::key* x = vec[i];

		vec.front() = x; //Hacer que el centinela sea igual que X

		if(demo){
			system("clear");
			std::cout << "[PROGRAMA] es x(" << x->value() << ") < el que estoy mirando(" << vec[j-1]->value() << ")? ";
			if(x->value() < vec[j-1]->value())
				std::cout << "Si, asi que voy a tener que buscar" << std::endl;
			else
				std::cout << "No, asi que voy a insertar directamente" << std::endl;

			for(int i = 0; i < vec.size(); i++){
				std::cout << i-1 << ". " << vec[i]->value();
				if(i == j-1)
					std::cout << " <--";
				std::cout << std::endl;
			}

			std::cin.ignore().get();
		}
		comparaciones++;
		while(x->value() < vec[j-1]->value())
		{
			comparaciones++;
			vec[j] = vec[j-1];
			j--;

			if(demo){
				system("clear");
				std::cout << "[PROGRAMA] es x(" << x->value() << ") < el que estoy mirando(" << vec[j-1]->value() << ")? ";
				if(x->value() < vec[j-1]->value())
					std::cout << "Si, sigo buscando" << std::endl;
				else
					std::cout << "No, asi que lo inserto" << std::endl;

				for(int i = 0; i < vec.size(); i++){
					std::cout << i-1 << ". " << vec[i]->value();
					if(i == j-1)
						std::cout << " <--";
					std::cout << std::endl;
				}

				std::cin.ignore().get();
			}
		}

		vec[j] = x;

		if(demo){
			system("clear");
			std::cout << "[PROGRAMA] La clave " << x->value() << " ha sido insertada en la posicion " << j-1 << "!" << std::endl;
			for(int i = 0; i < vec.size(); i++){
				std::cout << i-1 << ". " << vec[i]->value() << std::endl;
			}
			std::cin.ignore().get();
		}

	}

	vec.erase(vec.begin());

	if(demo){

		system("clear");
		std::cout << "[PROGRAMA] Hecho! tu vector ya esta ordenado, me ha tomado " << comparaciones << " pasos" << std::endl;

		for(int i = 0; i < vec.size(); i++)
			std::cout << vec[i] << std::endl;

		std::cin.ignore().get();
	}

	return comparaciones;
}

unsigned seleccion(std::vector<dra::key*> &vec, bool demo = false)
{
	unsigned comparaciones = 0;

	if(demo){
		system("clear");

		std::cout << "[PROGRAMA] Tu vector antes de empezar esta asi:" << std::endl;
		for(int i = 0; i < vec.size(); i++)
			std::cout << i << ". " << vec[i]->value() << std::endl;

		std::cin.ignore().get();
	}

	for(int i = 0; i < vec.size(); i++){
		unsigned min = i;

		for(int j = i+1; j < vec.size(); j++){

			if(demo){
				system("clear");
				std::cout << "[PROGRAMA] el que miro ahora(" << vec[j]->value() << ") < el minimo provisinal(" << vec[min]->value() << ")? ";
				if(vec[j]->value() < vec[min]->value())
					std::cout << "Si, asi que este es el nuevo minimo" << std::endl;
				else
					std::cout << "No, asi que dejo el minimo como estaba" << std::endl;

				for(int k = 0; k < vec.size(); k++){
					std::cout << k << ". " << vec[k]->value();
					if(k == i)
						std::cout << "<--- Por el que voy a cambiar";
					else if(k == min)
						std::cout << "<--- El minimo por ahora";
					else if(k == j)
						std::cout << "<--- El que estoy mirando ahora";
					std::cout << std::endl;
				}

				std::cin.ignore().get();
			}
			comparaciones++;
			if(vec[j]->value() < vec[min]->value())
				min = j;
		}
		dra::key* x = vec[min];
		vec[min] = vec[i];
		vec[i] = x;
	}

	if(demo){

		system("clear");
		std::cout << "[PROGRAMA] Hecho! tu vector ya esta ordenado, me ha tomado " << comparaciones << " pasos" << std::endl;

		for(int i = 0; i < vec.size(); i++)
			std::cout << vec[i] << std::endl;

		std::cin.ignore().get();
	}

	return comparaciones;
}

}

#endif
