#include "stack.hpp"

void stack_t::build(void)
{
	S_ = new TDATO[size_];
	top_ = EMPTY_STACK;
}

void stack_t::destroy(void)
{
	if(S_ != nullptr){
		delete[] S_;
		S_ = nullptr;
		top_ = EMPTY_STACK;
		size_ = 0;
	}
}

void stack_t::resize(int n)
{
	TDATO* tmp_ptr = new TDATO[n];
	for(int i = 0; i < size_; i++){
		tmp_ptr[i] = S_[i]; //no hace comprobar si la pila decrece (no tiene sentido que la pila decrezca)
	}
	delete[] S_;
	S_ = tmp_ptr;
	size_ = n;
}

stack_t::stack_t(void):
S_(nullptr),
size_(0),
top_(EMPTY_STACK)
{
	build();
}

stack_t::stack_t(unsigned int size):
S_(nullptr),
size_(size),
top_(EMPTY_STACK)
{
	build();
}

stack_t::~stack_t(void)
{
	destroy();
}

void stack_t::push(TDATO it)
{
	if(!full()){
		top_++;
		S_[top_] = it;
	}
	else
		std::cerr << "STACK OVERFLOW" << std::endl;
}

TDATO stack_t::top(void) const
{
	if(!empty())
		return S_[top_];
	else{
		std::cerr << "STACK UNDERFLOW" << std::endl;
		return (-1);
	}
}

TDATO stack_t::pop(void)
{
	if(!empty()){
		TDATO tmp = S_[top_];
		top_--;
		return tmp;
	}
	else{
		std::cerr << "STACK UNDERFLOW" << std::endl;
		return (-1);
	}
}

void stack_t::swap(stack_t& it)
{
	TDATO* tmp_ptr = S_;
	S_ = it.S_;
	it.S_ = tmp_ptr;
	//==================
	unsigned int tmp_sz = size_;
	size_ = it.size_;
	it.size_ = tmp_sz;
	//=========================
	int tmp_top = top_;
	top_ = it.top_;
	it.top_ = tmp_top;
}

void stack_t::emplace(TDATO it)
{
	if(!full())
		push(it);
	else{
		resize(size_+1);
		push(it);
	}
}

inline bool stack_t::full(void) const
{
	return (top_ == size_-1);
}

inline bool stack_t::empty(void) const
{
	return (top_ == EMPTY_STACK);
}

std::ostream& operator<<(std::ostream& os, stack_t& it) //para imprimir la pila, hay que hacerlo desde top, hasta 0.
{
	if(it.empty())
		os << "EMPTY STACK";
	for(int i = it.top_; i != EMPTY_STACK; i--){
		if(i-1 == EMPTY_STACK)
			os << it.S_[i];
		else
			os << it.S_[i] << std::endl;
	}
	return os;
}