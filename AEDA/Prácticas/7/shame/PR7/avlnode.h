/** \file AVLNode.h
  * \version 1.0
  * \date 24/04/2015
  * \author Daniel Ramos Acosta
  * \brief Contiene la definición e implementación de la clase AVLNode.
  * \code
  * //Código de ejemplo
  *
  * int main(void){
  *		//...
  *
  *		mi_arbol_binario.insertar(new AVLNode<int>(8));
  *		//Esto insertaría un nodo de valor ocho en un árbol binario.
  * }
  *
  * \endcode
*/

#ifndef AVLNODE
#define AVLNODE

#include <iostream>

#include "node.h"


namespace dra{

template<class T>
class AVLNode : public dra::node<T>{
	/*!
     * \class AVLNode<T>
	 * \brief Esta clase representa un nodo binario
	 * \details
	 * Esta clase representa a un nodo binario para usarse en un árbol binario de
	 * un grafo. Tiene enlaces a la derecha y a la izquierda que conectan con más
	 * nodos. Los datos del nodo en sí, se guardan en la clase padre nodo genérico.
	 */
private:
    AVLNode* left_;
    AVLNode* right_;
    int bal_;
public:
	/*! \name Constructores y destructor*/
	///@{
	/*!
	 * \brief Este es el constructor por defecto, los enlaces serán nulos.
	 */
    AVLNode(void);

	/*!
	 * \brief Este constructor se le pasa un dato que se almacenará en la clase padre.
	 * \param data es el dato a almacenar.
	 */
    AVLNode(const T data);

	/*!
	 * \brief Destructor de la clase, no hace nada especial.
	 */
    virtual ~AVLNode(void);
	///@}

	/*! \name Métodos de acceso a los punteros izquierdo y derechos*/
	///@{
	/*!
	 * \brief Este metodo sirve para modificar el enlace izquierdo del nodo.
	 * \return Devuelve una referencia al puntero izquierdo.
	 */
    AVLNode*& left(void);

	/*!
	 * \brief Este metodo sirve para leer el enlace izquierdo del nodo.
	 * \return Devuelve una copia del puntero izquierdo.
	 */
    AVLNode* left(void) const;

	/*!
	 * \brief Este metodo sirve para modificar el enlace derecho del nodo.
	 * \return Devuelve una referencia al puntero derecho.
	 */
    AVLNode*& right(void);

	/*!
	 * \brief Este metodo sirve para leer el enlace derecho del nodo.
	 * \return Devuelve una copia del puntero derecho.
	 */
    AVLNode* right(void) const;
	///@}

    int& bal(void);
    int bal(void) const;
};


template<class T>
AVLNode<T>::AVLNode(void):
node<T>(),
	left_(nullptr),
    right_(nullptr),
    bal_(0)
{}

template<class T>
AVLNode<T>::AVLNode(const T data):
	node<T>(data),
	left_(nullptr),
    right_(nullptr),
    bal_(0)
{}

template<class T>
AVLNode<T>::~AVLNode(void)
{}

template<class T>
AVLNode<T>*& AVLNode<T>::left(void)
{
	return left_;
}

template<class T>
AVLNode<T>* AVLNode<T>::left(void) const
{
	return left_;
}

template<class T>
AVLNode<T>*& AVLNode<T>::right(void)
{
	return right_;
}

template<class T>
AVLNode<T>* AVLNode<T>::right(void) const
{
	return right_;
}

template<class T>
int& AVLNode<T>::bal(void)
{
    return bal_;
}

template<class T>
int AVLNode<T>::bal(void) const
{
    return bal_;
}

}

#endif // AVLNODE
