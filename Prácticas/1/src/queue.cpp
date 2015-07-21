#include "queue.hpp"

queue_t::queue_t(void):
Q_(nullptr),
size_(0),
rear_(EMPTY_QUEUE)
{}

queue_t::queue_t(unsigned int size):
Q_(nullptr),
size_(size),
rear_(EMPTY_QUEUE)
{
	build();
}

queue_t::~queue_t(void)
{
	destroy();
}

inline void queue_t::build(void)
{
	Q_ = new TDATO[size_];
}

inline void queue_t::destroy(void)
{
	if(Q_ != nullptr){
		delete[] Q_;
		Q_ = nullptr;
		size_ = 0;
		rear_ = EMPTY_QUEUE;
	}
}

void queue_t::resize(unsigned int size)
{
	TDATO* tmp_data = new TDATO[size];
	for(int i = 0; i < (min(size, size_)); i++) //el bucle solo llega hasta el minimo tamaño, para no sobrepasarnos de memoria.
		tmp_data[i] = Q_[i];
	delete[] Q_;

	Q_ = tmp_data;
	size_ = size;
}

inline unsigned int queue_t::min(unsigned int first, unsigned int second) const
{
	return (first>second)?first:second;
}

inline void queue_t::ifemptybuild(void)
{
	if(empty()){
		size_ = 1;
		build();
	}
}

void queue_t::push(TDATO it)
{
	if(!full()){
		rear_++;
		Q_[rear_] = it;
	}
	else
		std::cerr << "QUEUE OVERFLOW" << std::endl;
}

TDATO queue_t::pop(void)
{
	if(!empty()){
		TDATO tmp_data = Q_[0];
		for(int i = 1; i <= rear_; i++)
			Q_[i-1] = Q_[i];
		rear_--;

		return tmp_data;
	}
	else
		std::cerr << "QUEUE UNDERFLOW" << std::endl;
}

inline TDATO& queue_t::front(void) const
{
	if(!empty()) return Q_[0];
	else std::cerr << "EMPTY QUEUE!" << std::endl;
}

inline TDATO& queue_t::rear(void) const
{
	if(!empty()) return Q_[rear_];
	else std::cerr << "EMPTY QUEUE!" << std::endl;
}

void queue_t::emplace(TDATO it)
{
	ifemptybuild(); //Esto hay que ponerlo por si inicializa la cola con void.
	if(!full())
		push(it);
	else{
		size_++;
		resize(size_); //Preguntarle a Marcos por que no puedo poner directamente size_++;
		push(it);
	}
}

inline unsigned int queue_t::size(void) const
{
	return size_;
}

inline bool queue_t::empty(void) const
{
	return (rear_ == EMPTY_QUEUE);
}

inline bool queue_t::full(void) const
{
	return (rear_ == size_-1);
}

void queue_t::swap(queue_t& it)
{
	TDATO* tmp_ptr = Q_;
	Q_ = it.Q_;
	it.Q_ = tmp_ptr;
	//==========================
	unsigned int tmp_sz = size_;
	size_ = it.size_;
	it.size_ = tmp_sz;
	//==========================
	int tmp_rear = rear_;
	rear_ = it.rear_;
	it.rear_ = tmp_rear;
}

std::ostream& operator<<(std::ostream& os, queue_t& it)
{
	if(it.empty()) return os << "{}";
	os << "{";
	for(int i = 0; i <= it.rear_; i++)
		os << it.Q_[i] << ", ";
	os << "\b\b}";
	return os;
}