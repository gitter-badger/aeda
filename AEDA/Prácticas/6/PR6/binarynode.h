#ifndef BINARYNODE
#define BINARYNODE

namespace dra{

template<class T>
class binaryNode{
private:
	T data_;
	binaryNode* left_;
	binaryNode* right_;
public:
	binaryNode(void);
	binaryNode(const T& data);
	~binaryNode(void);

	binaryNode*& left(void);
	binaryNode* left(void) const;

	binaryNode*& right(void);
	binaryNode* right(void) const;

	T& data(void);
	T data(void) const;

	binaryNode<T>& operator=(const binaryNode<T>&);
	std::ostream& toStream(std::ostream& os) const;
};


template<class T>
binaryNode<T>::binaryNode(void):
left_(nullptr),
right_(nullptr),
data_()
{}

template<class T>
binaryNode<T>::binaryNode(const T& data):
left_(nullptr),
right_(nullptr),
data_(data)
{}

template<class T>
binaryNode<T>::~binaryNode(void)
{}

template<class T>
binaryNode<T>*& binaryNode<T>::left(void)
{
	return left_;
}

template<class T>
binaryNode<T>* binaryNode<T>::left(void) const
{
	return left_;
}

template<class T>
binaryNode<T>*& binaryNode<T>::right(void)
{
	return right_;
}

template<class T>
binaryNode<T>* binaryNode<T>::right(void) const
{
	return right_;
}

template<class T>
T& binaryNode<T>::data(void)
{
	return data_;
}

template<class T>
T binaryNode<T>::data(void) const
{
	return data_;
}


template<class T>
std::ostream& binaryNode<T>::toStream(std::ostream& os) const
{
	if(right_ != nullptr)
		os << "[ " << data_ << " ][" << right_ << "]->";
	else
		os << "[ " << data_ << " ][nullptr]";

	if(left_ != nullptr)
		std::cout << "|\nv\n" << left_;
	return os;
}

}

//==============================================================================
// Fin de implementación de la clase
//==============================================================================

template<class T>
std::ostream& operator<<(std::ostream& os, const dra::binaryNode<T>& n)
{
	return n.toStream(os);
}

#endif // BINARYNODE
