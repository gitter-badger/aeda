#ifndef __node__
#define __node__
#include "common.hpp"

class node_t{
private:
	node_t* next_;
	TDATO data_;
public:
	node_t(void);
	node_t(TDATO data);
	~node_t(void);

	void set_next(node_t* next);
	node_t* get_next(void) const; //aquí lo dejo así ya que no me sale bien mi_nodo.next() = new node_t, lo he intentado pero me da errores...

	//void set_data(TDATO data); no hace falta, ya que podemos hacer directamente mi_nodo.data() = 7;
	TDATO& data(void);

	friend std::ostream& operator<<(std::ostream& os, const node_t& it);
};

#endif