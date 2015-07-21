/** \file binarynode.h
  * \version 1.0
  * \date 24/04/2015
  * \author Daniel Ramos Acosta
  * \brief Contiene la definición e implementación de la clase binaryNode.
  * \code
  * //Código de ejemplo
  *
  * int main(void){
  *		//...
  *
  *		mi_arbol_binario.insertar(new binaryNode<int>(8));
  *		//Esto insertaría un nodo de valor ocho en un árbol binario.
  * }
  *
  * \endcode
*/

#ifndef BINARYNODE
#define BINARYNODE

#include <iostream>

#include "node.h"


namespace dra{

template<class T>
class binaryNode : public dra::node<T>{
	/*!
	 * \class binaryNode<T>
	 * \brief Esta clase representa un nodo binario
	 * \details
	 * Esta clase representa a un nodo binario para usarse en un árbol binario de
	 * un grafo. Tiene enlaces a la derecha y a la izquierda que conectan con más
	 * nodos. Los datos del nodo en sí, se guardan en la clase padre nodo genérico.
	 */
private:
	binaryNode* left_;
	binaryNode* right_;
public:
	/*! \name Constructores y destructor*/
	///@{
	/*!
	 * \brief Este es el constructor por defecto, los enlaces serán nulos.
	 */
    binaryNode(void);

	/*!
	 * \brief Este constructor se le pasa un dato que se almacenará en la clase padre.
	 * \param data es el dato a almacenar.
	 */
    binaryNode(const T data);

	/*!
	 * \brief Destructor de la clase, no hace nada especial.
	 */
    virtual ~binaryNode(void);
	///@}

	/*! \name Métodos de acceso a los punteros izquierdo y derechos*/
	///@{
	/*!
	 * \brief Este metodo sirve para modificar el enlace izquierdo del nodo.
	 * \return Devuelve una referencia al puntero izquierdo.
	 */
	binaryNode*& left(void);

	/*!
	 * \brief Este metodo sirve para leer el enlace izquierdo del nodo.
	 * \return Devuelve una copia del puntero izquierdo.
	 */
	binaryNode* left(void) const;

	/*!
	 * \brief Este metodo sirve para modificar el enlace derecho del nodo.
	 * \return Devuelve una referencia al puntero derecho.
	 */
	binaryNode*& right(void);

	/*!
	 * \brief Este metodo sirve para leer el enlace derecho del nodo.
	 * \return Devuelve una copia del puntero derecho.
	 */
	binaryNode* right(void) const;
	///@}
};


template<class T>
binaryNode<T>::binaryNode(void):
node<T>(),
	left_(nullptr),
	right_(nullptr)
{}

template<class T>
binaryNode<T>::binaryNode(const T data):
	node<T>(data),
	left_(nullptr),
	right_(nullptr)
{}

template<class T>
binaryNode<T>::~binaryNode(void)
{}

template<class T>
binaryNode<T>*& binaryNode<T>::left(void)
{
	return left_;
}

template<class T>
binaryNode<T>* binaryNode<T>::left(void) const
{
	return left_;
}

template<class T>
binaryNode<T>*& binaryNode<T>::right(void)
{
	return right_;
}

template<class T>
binaryNode<T>* binaryNode<T>::right(void) const
{
	return right_;
}

}

#endif // BINARYNODE
