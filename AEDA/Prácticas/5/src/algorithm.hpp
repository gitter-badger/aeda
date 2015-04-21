#ifndef _ALGORITHM_HPP_
#define _ALGORITHM_HPP_

#include <vector>

#include "key.hpp"
#include "key_human.hpp"
#include "key_human_dni.hpp"
#include "human.hpp"

#include <unistd.h>
#include <algorithm>

namespace dra{

unsigned insercion(std::vector<dra::key*> &vec, bool demo = false)
{
	unsigned comparaciones = 0;

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

		std::cin.get();
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

			std::cin.get();
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

				std::cin.get();
			}
		}

		vec[j] = x;

		if(demo){
			system("clear");
			std::cout << "[PROGRAMA] La clave " << x->value() << " ha sido insertada en la posicion " << j-1 << "!" << std::endl;
			for(int i = 0; i < vec.size(); i++){
				std::cout << i-1 << ". " << vec[i]->value() << std::endl;
			}
			std::cin.get();
		}

	}

	vec.erase(vec.begin());

	return comparaciones;
}

unsigned seleccion(std::vector<dra::key*> &vec, bool demo = false)
{
	unsigned comparaciones = 0;

	for(int i = 0; i < vec.size(); i++){
		unsigned min = i;

		for(int j = i+1; j < vec.size(); j++){

			if(demo){
				system("clear");
				std::cout << "[PROGRAMA] el que miro ahora(" << vec[j]->value() << ") < el minimo provisional(" << vec[min]->value() << ")? ";
				if(vec[j]->value() < vec[min]->value())
					std::cout << "Si, asi que este es el nuevo minimo" << std::endl;
				else
					std::cout << "No, asi que dejo el minimo como estaba" << std::endl;

				for(int k = 0; k < vec.size(); k++){
					std::cout << k << ". " << vec[k]->value();
					if(k == i)
						std::cout << "<--- Por el que voy a cambiar";
					if(k == min)
						std::cout << "<--- El minimo por ahora";
					else if(k == j)
						std::cout << "<--- El que estoy mirando ahora";
					std::cout << std::endl;
				}

				std::cin.get();
			}
			comparaciones++;
			if(vec[j]->value() < vec[min]->value())
				min = j;
		}
		std::swap(vec[min], vec[i]);
	}

	return comparaciones;
}

unsigned shellsort(std::vector<dra::key*> &vec, bool demo = false)
{
	unsigned comparaciones = 0;


	double alpha;

	if(demo){
		do{
			std::cout << "Elije el alfa que quieras entre 0 y 1: a=";
			std::cin >> alpha;
		}while(alpha > 1 || alpha < 0);
	}
	else
		alpha = 0.45454;

	int delta = vec.size();

	while(delta > 1){
		delta = delta * alpha;
		if(demo){

			system("clear");
			std::cout << "[PROGRAMA] Voy a ordenar con delta = " << delta << std::endl;
			unsigned k = 0;
			for(int i = 0; i < vec.size(); i++){
				std::cout << vec[i]->value();
				if(k == i){
					std::cout << " <--- ";
					k+=delta;
				}
				std::cout << std::endl;
			}

			std::cin.get();
		}

		for(unsigned i = delta; i<vec.size(); i++){
			dra::key* x = vec[i];
			unsigned j = i;
			comparaciones++;
			while((j >= delta) && (x->value() < vec[j-delta]->value())){
				vec[j] = vec[j-delta];
				j = j - delta;
				comparaciones++;
			}
			vec[j] = x;
		}
		if(demo){

			system("clear");
			std::cout << "[PROGRAMA] Ya deberia estar ordenado con delta = " << delta << std::endl;
			unsigned k = 0;
			for(int i = 0; i < vec.size(); i++){
				std::cout << vec[i]->value();
				if(k == i){
					std::cout << " <--- ";
					k+=delta;
				}
				std::cout << std::endl;
			}

			std::cin.get();
		}
	}
	return comparaciones;
}

void quickSort(std::vector<dra::key*> &vec, int ini, int fin, unsigned &comparaciones, bool demo = false)
{

	comparaciones++;
	if (ini >= fin)
		return;

	int mid = ini + (fin - ini) / 2;
	dra::key* pivot = vec[mid];

	//Ordenar la parte izquierda y derecha del pivote
	std::swap(vec[mid], vec[ini]); //poner pivote al principio

	int i = ini + 1;
	int f = fin;
	while (i <= f){
		comparaciones++;
		while(i <= f && vec[i]->value() <= pivot->value()){
			i++;
			comparaciones++;
		}
		comparaciones++;
		while(i <= f && vec[f]->value() >  pivot->value()){
			f--;
			comparaciones++;
		}


		if(demo){
			system("clear");
			std::cout << "[PROGRAMA] He encontrado dos elementos a intercambiar:" << std::endl;
			for(int j = ini; j < fin+1; j++){
				std::cout << j << ". " << vec[j]->value();
				if(j == i)
					std::cout << " <--- i";
				if(j == f)
					std::cout << " <--- f";
				std::cout << std::endl;
			}
			std::cin.get();
		}

		comparaciones++;
		if (i < f)
			std::swap(vec[i], vec[f]);
	}
	std::swap(vec[i - 1], vec[ini]); //recolocar pivote
	int part = i -1;

	//Ordenar las dos mitades

	quickSort(vec, ini, part - 1, comparaciones, demo);
	quickSort(vec, part + 1, fin, comparaciones, demo);
}

unsigned quickSort(std::vector<dra::key*> & vec, bool demo = false)
{
	unsigned comparaciones=0;
	quickSort(vec, 0, vec.size()-1, comparaciones, demo);
	return comparaciones;
}

void merge(std::vector<dra::key*> &vec, std::vector<dra::key*> &izq, std::vector<dra::key*> &der, unsigned &comparaciones)
{
	std::vector<dra::key*> resultado;

	unsigned izq_it = 0, der_it = 0;

	comparaciones++;
	while(izq_it < izq.size() && der_it < der.size())
	{
		comparaciones++;
		comparaciones++;
		if(izq[izq_it]->value() < der[der_it]->value()){
			resultado.push_back(izq[izq_it]);
			izq_it++;
		}
		else{
			resultado.push_back(der[der_it]);
			der_it++;
		}
	}

	//Puede que nos haya sobrado algo de algun vector, asi que lo terminamos de meter
	comparaciones++;
	while(izq_it < izq.size())
	{
		comparaciones++;
		resultado.push_back(izq[izq_it]);
		izq_it++;
	}
	comparaciones++;
	while(der_it < der.size())
	{
		comparaciones++;
		resultado.push_back(der[der_it]);
		der_it++;
	}

	vec = resultado;
}

void mergeSortVerdadero(std::vector<dra::key*> &vec, unsigned &comparaciones, bool demo = false)
{
	comparaciones++;
	if(vec.size() == 1)
		return;

	auto middle = vec.begin() + (vec.size()/2);

	std::vector<dra::key*> izq(vec.begin(), middle);
	std::vector<dra::key*> der(middle, vec.end());

	mergeSortVerdadero(izq, comparaciones, demo);
	mergeSortVerdadero(der, comparaciones, demo);

	if(demo){
		system("clear");
		std::cout << "Voy a hacer la fusion de estos dos vectores: " << std::endl;
		for(int i = 0; i < izq.size(); i++){
			std::cout << izq[i]->value() << std::endl;
		}
		std::cout << "     +" << std::endl;
		for(int i = 0; i < der.size(); i++){
			std::cout << der[i]->value() << std::endl;
		}
		std::cin.get();
	}



	merge(vec, izq, der, comparaciones);

	if(demo){
		std::cout << "     =" << std::endl;
		for(int i = 0; i < vec.size(); i++){
			std::cout << vec[i]->value() << std::endl;
		}
		std::cin.get();
	}
}

unsigned mergeSort(std::vector<dra::key*> &vec, bool demo = false)
{
	unsigned comparaciones=0;
	mergeSortVerdadero(vec, comparaciones, demo);
	return comparaciones;
}

}


#endif
