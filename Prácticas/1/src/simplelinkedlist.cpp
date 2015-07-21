#include "simplelinkedlist.hpp"

simplelinkedlist_t::simplelinkedlist_t(void):
start_(nullptr),
end_(nullptr)
{}

simplelinkedlist_t::~simplelinkedlist_t(void)
{
	node_t* tmp_ptr = start_;
	while(start_ != nullptr)
	{
		//std::cout << "start_ -> " << start_ << ", por lo tanto eliminamos y pillamos el siguiente" << std::endl;
		start_ = start_ -> get_next();
		delete tmp_ptr;
		tmp_ptr = start_;
	}
}

inline bool simplelinkedlist_t::empty(void) const
{
	return (start_ == nullptr);
}

void simplelinkedlist_t::first(node_t* node)
{
	start_ = node;
	end_ = node;
}

void simplelinkedlist_t::push_back(node_t* node)
{
	if(empty()) first(node);
	else{
		end_ -> set_next(node);
		end_ = node;
	}

}

void simplelinkedlist_t::push_front(node_t* node)
{
	if(empty()) first(node);
	else{
		node->set_next(start_);
		start_ = node;
	}

}

void simplelinkedlist_t::insert(node_t* node, node_t* after)
{
	if(empty()) first(node); //por seguridad...
	node->set_next(after->get_next());
	after->set_next(node);
}

node_t* simplelinkedlist_t::extract_back(void)
{
	node_t* tmp_ptr = start_;
	if (start_ == end_){
		start_ = nullptr;
		end_ = nullptr;
		return tmp_ptr;
	}
	else{
		while(tmp_ptr->get_next() != end_) //conseguir que tmp_ptr apunte al nodo anterior, esto sería más eficiente si fuese doblemente enlazada
			tmp_ptr = tmp_ptr->get_next();
		end_ = tmp_ptr;
		tmp_ptr = tmp_ptr->get_next();
		end_->set_next(nullptr);
		return tmp_ptr;
	}
}

node_t* simplelinkedlist_t::extract_front(void)
{
	node_t* tmp_ptr = start_;
	if (start_ == end_){
		start_ = nullptr;
		end_ = nullptr;
		return tmp_ptr;
	}
	else{
		start_ = start_->get_next();
		return tmp_ptr;
	}
}

node_t* simplelinkedlist_t::extract(node_t* node)
{
	node_t* tmp_ptr = start_; //por seguridad tambien
	if (start_ == end_){
		start_ = nullptr;
		end_ = nullptr;
		return tmp_ptr;
	}
	else{
		while(tmp_ptr->get_next() != node)
			tmp_ptr = tmp_ptr->get_next(); //ahora mismo, el puntero del nodo al que apunta tmp_ptr, apunta a node
		tmp_ptr->set_next(node->get_next());
		node->set_next(nullptr);
		return node;
	}
}

std::ostream& operator<<(std::ostream& os, const simplelinkedlist_t& it) //PREGUNTAR A MARCOS
{
	node_t* tmp_ptr = it.start_;
	
	while(true){
		os << *tmp_ptr;
		
		tmp_ptr = tmp_ptr->get_next();

		if(tmp_ptr == nullptr){
			std::cout << std::endl;
			break;
		}
	}
}