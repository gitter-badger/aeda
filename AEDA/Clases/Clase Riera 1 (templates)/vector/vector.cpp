

#define DEFAULT_BUFF_VECTOR_SZ 50

#include <cstdio>
#include <cstring>
#include <algorithm>

template<class T>

class vector_t
{
	T* V_;
	int sz_;
	int msz_;
	int buff_sz_;
public:
	//============================================
	vector_t(void);
	vector_t(const vector_t& c);
	vector_t(int sz);
	vector_t(int sz, int buff_sz);
	virtual ~vector_t(void)
	{
		if(V_!=nullptr)
		{
			delete[] V_;
			V_ = nullptr;
		}
	}
	//============================================
	void resize(int new_sz);
	void push_back(T it);
	T pop_back(void);
	//============================================
	T operator[](int pos) const;
	//============================================
};

vector_t<T>::vector_t(void):
V_(nullptr),
sz_(0),
msz_(0),
buff_sz_(DEFAULT_BUFF_VECTOR_SZ){}

vector_t<T>::vector_t:
V_(nullptr),
sz_(c.sz_),
msz_(c.msz_),
buff_sz_(c.buff_sz_)
{
	V_ = new T[msz_];
	memcpy(V_, c.V_, sz_*sizeof(T));	
}

vector_t<T>::vector_t(int sz):
V_(nullptr),
sz_(0),
msz_(0),
buff_sz_(DEFAULT_BUFF_VECTOR_SZ)
{
	msz_ = sz_ + buff_sz_;
	V_ = new T[msz_];
}

vector_t<T>::vector_t(int sz, int buff_sz):
V_(nullptr),
sz_(sz),
msz_(0),
buff_sz_(buff_sz)
{
	msz_= sz + buff_sz_;
	V_ = new T[msz_];
}

//FALTA DESTRUCTOR AQUI

void vector_t<T>::resize(int new_sz)
{
	if(new_sz <= msz_)
		sz_ = new_sz;
	else{
		T* aux = new T[new_sz];
		memcpy(aux, V_, sz_*sizeof(T));
		sz_ = new_sz;
		msz_ = sz + buff_sz_;
		delete[] V_;
		V_ = aux;
	}
}

void vector_t<T>::push_back(T it)
{
	resize(sz_ + 1);
	V_[sz_ -1 ] = it;
}

T vector_t<T>::pop_back(void)
{
	resize(sz_ - 1);
	return V_[sz_];
}

T vector_t<T>::operator[](int pos) const
{
	#ifdef _DEBUG
		assert(pos < sz);
	#endif
		return V_[pos];
}

T& operator[](int pos)
{
	return V_[pos];
}