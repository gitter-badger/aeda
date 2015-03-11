#ifndef __vector__
#define __vector__
#include "common.hpp"

class vector_t
{
private:
	TDATO *V_ ;
	unsigned int size_;
	unsigned int first_;
	unsigned int last_;
//==================================================== Constructores, destructores y operador=
private: 
	void build(void);
	void destroy(void);
public:
	vector_t(void);
	vector_t(const unsigned int size);
	vector_t(const vector_t& mv); //WIP
	vector_t(unsigned int first, unsigned int last); //WIP
	~vector_t(void);
	vector_t& operator=(const vector_t& it);
private:
	unsigned int min(unsigned int first, unsigned int second) const;
//==================================================== Capacidad
public:
	void resize(const unsigned int size);
	void resize_safe(const unsigned int size); //WIP
	int size(void) const;
	bool empty(void) const;
//==================================================== Acceso a los elementos
public:
	TDATO& operator[](const int it);
	TDATO& at(const int it);
	TDATO& front(void);
	TDATO& back(void);
	TDATO* data(void);

//==================================================== Modificadores
public:
	void push_back(const TDATO& it); //WIP
	TDATO pop_back(void);
	void insert(const unsigned int place, TDATO it);
	void earse(const unsigned int place);
	void swap(vector_t& it);
	void clear(void);
//==================================================== E/S
public:
	friend std::ostream& operator<<(std::ostream& os, const vector_t& it);
};

#endif