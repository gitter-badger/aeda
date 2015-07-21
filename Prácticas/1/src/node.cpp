#include "node.hpp"

node_t::node_t(void):
data_(),
next_(nullptr)
{}

node_t::node_t(TDATO data):
data_(data),
next_(nullptr)
{}

node_t::~node_t(void)
{}

void node_t::set_next(node_t* next)
{
	next_ = next;
}

/*inline*/ node_t* node_t::get_next(void) const //revisar lo del inline con Marcos
{
	return next_;
}
/*
void node_t::set_data(TDATO data) //preguntar a marcos, para poder poner un numero entero aqui
{
	data_ = data;
}
*/
/*inline*/ TDATO& node_t::data(void) //revisar lo del inline con Marcos
{
	return data_;
}

std::ostream& operator<<(std::ostream& os, const node_t& it)
{
	if(it.next_ == nullptr)
		os << "[ " << it.data_ << " ][nullptr]";
	else{
		os << "[ " << it.data_ << " ][" << it.next_ << "]-->";
	}
}