#pragma once


template <class T>
class nodo_t
{
private:
	nodo_t* next_;
	T data_;
public:
	nodo_t(T data):
		next_(nullptr),
		data_(data){}

 	virtual ~nodo_t(void){}

 	nodo_t* get_next(void) const
 	{
 		return next_;
 	}

 	void set_next(nodo_t* next)
 	{
 		next_ = next;
 	}

 	T& get_data(void)
 	{
 		return data_;
 	}

 	T get_data(void) const
 	{
 		return data_;
 	}
};