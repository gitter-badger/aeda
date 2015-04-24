/*! \file node.h
  * \version 1.0
  * \date 24/04/2015
  * \author Daniel Ramos Acosta
  * \title Clase plantilla nodo
  * \brief Contiene la definición e implementación de la clase node
  * \code
  * //Código de ejemplo
  *
  * template<class T>
  * class listNode : public dra::node<T>{
  *	private:
  *		listNode* next_;
  *		listNode* prev_;
  * public:
  *		//....
  * };
  *
  * \endcode
*/

#ifndef NODE
#define NODE

namespace dra{

template<class T>
class node{
	/*!
	 * \class node<T>
	 * \brief Esta clase representa un nodo genérico
	 * \details
	 * Esta clase representa a un nodo genérico de un grafo. para usarlo, uno hereda
	 * de esta clase, y añade la cantidad de enlaces que desee. Puede servir para
	 * una lista enlazada, un árbol binario, o simplemente un grafo.
	 */
private:
	T data_;
public:
	/*! \name Constructores y destructor*/
	///@{
	/*!
	 * \brief Este es el constructor por defecto del nodo.
	 */
	node(void);

	/*!
	 * \brief Este es el constructor al que se le pasa un dato a almacenar
	 * \param data Es el dato que se le pasa al consutructor del nodo
	 */
	node(const T data);

	/*!
	 * \brief Este es el destructor, no hace nada especial.
	 */
	~node(void);
	///@}

	/*! \name Métodos de acceso al dato*/
	///@{
	/*!
	 * \brief Este metodo devuelve el dato para poder modificarlo
	 * \return Devuelve una referencia al dato del nodo, por lo que se puede modificar.
	 */
	T& data(void);

	/*!
	 * \brief Este metodo devuelve el dato para poder leerlo
	 * \return Devuelve una copia del dato, por lo tanto no se edita el dato del nodo
	 */
	T data(void) const;
	///@}
};

template<class T>
node<T>::node(void)
{}

template<class T>
node<T>::node(const T data):
	data_(data)
{}

template<class T>
node<T>::~node(void)
{}

template<class T>
T& node<T>::data(void)
{
	return data_;
}

template<class T>
T node<T>::data(void) const
{
	return data_;
}

}

#endif // NODE

