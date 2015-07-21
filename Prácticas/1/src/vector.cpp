#include "vector.hpp"


//==================================================== Constructores, destructores y operador=
void vector_t::build(void)
{
	V_ = new TDATO[size_];
	if(V_ == nullptr)
		std::cerr << "Error creando el vector" << std::endl;
}

void vector_t::destroy(void)
{
	if(V_ != nullptr){
		delete[] V_;
		V_ = nullptr;
	}
}

vector_t::vector_t(void):
size_(0),
first_(0),
last_(0),
V_(nullptr)
{}

vector_t::vector_t(const unsigned int size):
size_(size),
first_(0),
last_(size-1),
V_(nullptr)
{
	build();
}

vector_t::vector_t(const vector_t& mv):
size_(mv.size_),
first_(mv.first_),
last_(mv.last_),
V_(nullptr)
{
	*this = mv;
}

vector_t::vector_t(unsigned int first, unsigned int last): //(3, 14) 14-3+1=11+1=12 <- size[12] 0..11
size_(last-first+1),
first_(first),
last_(last),
V_(nullptr)
{
	if(first_ <= last_)
		build();
	else
		std::cerr << "First is bigger than last" << std::endl;
}

vector_t::~vector_t(void)
{
	destroy();
}

vector_t& vector_t::operator=(const vector_t& it)
{
	resize(it.size_);

	first_ = it.first_;
	last_ = it.last_;

	for(int i = first_; i <= last_; i++)
		V_[i] = it.V_[i];

	return *this;
}

//==================================================== Capacidad

void vector_t::resize(const unsigned int size)
{
	destroy();
	size_ = size;
	last_ = size-1;
	build();
}

void vector_t::resize_safe(const unsigned int size)
{
	TDATO *tmp_ptr = new TDATO[size];

	for(int i = 0; i < min(size, size_); i++)
		tmp_ptr[i] = V_[i];

	destroy();

	size_ = size;
	last_ = size - 1;
	V_ = tmp_ptr;
}

inline unsigned int vector_t::min(unsigned int first, unsigned int second) const
{
	return (first>second)?first:second;
}

inline int vector_t::size(void) const
{
	return size_;
}

bool vector_t::empty(void) const
{
	return (size_ == 0);
}

//==================================================== Acceso a los elementos

TDATO& vector_t::operator[](const int it)
{
	if( (it < first_ ) || (it > last_) )
		std::cerr << "Position " << it << " is out of range (" << first_ << ", " << last_ << ")" /*<< (#*this)*/ << std::endl; //no me deja poner lo de *this...
	else
		return V_[it-first_];
}

TDATO& vector_t::at(const int it)
{
	return V_[it];
}

TDATO& vector_t::front(void)
{
	return V_[0];
}

TDATO& vector_t::back(void)
{
	return V_[last_];
}

TDATO* vector_t::data(void)
{
	return V_;
}

//==================================================== Modificadores

void vector_t::push_back(const TDATO& it)
{
	size_++;
	last_++;

	resize_safe(size_);
	V_[last_] = it;
}

TDATO vector_t::pop_back(void)
{
	size_--;
	last_--;

	TDATO tmp = V_[size_];

	resize_safe(size_);

	return tmp;
}

void vector_t::insert(const unsigned int place, TDATO it)
{
	TDATO *tmp_ptr = new TDATO[size_++];

	for(int i = 0; i < size_; i++){
		if(i <  place){tmp_ptr[i] = V_[i];}
		if(i == place){tmp_ptr[i] = it;}
		if(i >  place){tmp_ptr[i] = V_[i-1];}
	}
	destroy();
	V_ = tmp_ptr;
}

void vector_t::earse(const unsigned int place)
{
	TDATO *tmp_ptr = new TDATO[size_];
	for(int i = 0; i < size_-1; i++){
		if(i < place){tmp_ptr[i] = V_[i];}
		if(i >=  place){tmp_ptr[i] = V_[i+1];}
	}
	destroy();
	V_ = tmp_ptr;
	size_--;
	last_--;
}

void vector_t::swap(vector_t& it)
{
	TDATO* tmp_ptr = V_;
	V_ = it.V_;
	it.V_ = tmp_ptr;
	//=====================
	unsigned int tmp_size = size_;
	size_ = it.size_;
	it.size_ = tmp_size;
	//============================
	unsigned int tmp_first = first_;
	first_ = it.first_;
	it.first_ = tmp_first;
	//==============================
	unsigned int tmp_last = last_;
	last_ = it.last_;
	it.last_ = tmp_last;
}

void vector_t::clear(void)
{
	destroy();
	size_ = 0;
	first_ = 0;
	last_ = 0;
}

//==================================================== E/S

std::ostream &operator<<(std::ostream &os, const vector_t &it)
{
	os << "[";
	
	for(int i = it.first_; i <= it.last_; i++)
		os << it.V_[i] << " ";
	os << "\b]";
	/* No funciona!!
	for(auto i : it.V_)
		os << it.V_[i] << " ";
	os << "\b]";
	*/
	return os;
}

