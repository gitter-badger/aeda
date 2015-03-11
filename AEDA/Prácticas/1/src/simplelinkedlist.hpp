#ifndef __simplelinkedlist__
#define __simplelinkedlist__
#include "common.hpp"
#include "node.hpp"

class simplelinkedlist_t{
private:
	node_t* start_; //puntero al primer elemento de la lista enlazada
	node_t* end_; //puntero al último elemento de la lista enlazada

	void first(node_t* node); //se llama para la primera incersión
public:
	simplelinkedlist_t(void);
	~simplelinkedlist_t(void);

	bool empty(void) const;

	void push_back(node_t* node); //mete un nodo al final de la lista
	void push_front(node_t* node); //mete un nodo al principio de la lista
	void insert(node_t* node, node_t* after); //mete un nodo después del nodo "afer"

	node_t* extract_back(void); //extrae el último nodo
	node_t* extract_front(void); //extrae el primer nodo

	node_t* extract(node_t* node); //extrae el nodo pasado por parámetro

	friend std::ostream& operator<<(std::ostream& os, const simplelinkedlist_t& it);
};

#endif