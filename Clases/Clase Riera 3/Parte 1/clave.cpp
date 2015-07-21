#include "clave.hpp"

clave_t::clave_t(void):
clave_(nullptr)
{
	clave_ = new int[KEY_MAX_SZ];
	for(int i = 0; i < KEY_MAX_SZ; i++)
		clave_[i] = 0;
}

clave_t::~clave_t(void)
{
	if(clave_ != nullptr){
		delete[] clave_;
		clave_ = nullptr;
	}
}

bool clave_t::less_than(const clave_t* k)
{
	bool less  = true;
	bool end = false;
	int i = 0;
	while((i < clave_MAX_SZ) && (!end))
	{
		if(clave_[i] < k->clave_[i])
			end = true;
		else if(clave_[i] > k->clave_[i]){
			less = false;
			end = true;
		}
		i++;
	}
	return less;
}