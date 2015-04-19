#ifndef _ALGORITHM_HPP_
#define _ALGORITHM_HPP_



#include <vector>

#include "key.hpp"
#include "key_human.hpp"
#include "key_human_dni.hpp"
#include "human.hpp"

namespace dra{

unsigned insercion(std::vector<dra::key*> &vec, bool demo = false, unsigned p=0)
{
	std::cout << "Hola, soy el algoritmo de insercion" << std::endl;


	std::cout << "Hecho! tu vector ya esta ordenado, me ha tomado " << p << " pasos" << std::endl;
}

}
#endif
