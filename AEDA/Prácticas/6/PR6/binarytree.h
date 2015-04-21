#ifndef BINARYTREE
#define BINARYTREE

#include "binarynode.h"

namespace dra{



template<class T>
class binaryTree{
private:
	binaryNode<T>* root;
public:
	/** @name Constructores y destructor*/
	///@{
	/** \brief Constructor por defecto */
	binaryTree(void);
	/** \brief Destructor */
	~binaryTree(void);
	///@}


	bool empty(void) const;
};

}

#endif // BINARYTREE

