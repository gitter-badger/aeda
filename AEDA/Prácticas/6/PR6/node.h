#ifndef NODE
#define NODE

namespace dra{
	template<class T> class node;
}


template<class T>
class dra::node{
protected:
	T data_;
public:
	node(void);
	node(const T data);
	~node(void);

	T& data(void);
	T data(void) const;

	std::ostream& toStream(std::ostream& os) const=0;
};

template<class T>
dra::node<T>::node(void)
{}

template<class T>
dra::node<T>::node(const T data):
	data_(data)
{}

template<class T>
dra::node<T>::~node(void)
{}

template<class T>
T& dra::node<T>::data(void)
{
	return data;
}

template<class T>
T dra::node<T>::data(void) const
{
	return data;
}


#endif // NODE

