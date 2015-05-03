#ifndef BINARYSEARCHTREE
#define BINARYSEARCHTREE

#include "binarytree.h"

namespace dra{

template<class T>
class binarySearchTree : public binaryTree<T>{
protected:
	virtual void process(binaryNode<T>*);
	virtual unsigned insert(binaryNode<T>*, binaryNode<T>*&, unsigned=0);
    virtual void erase(T, binaryNode<T>*&);
    virtual bool search(T, binaryNode<T>*, unsigned&);
private:
    void substitute(binaryNode<T>*&, binaryNode<T>*&);
};

template<class T>
void binarySearchTree<T>::process(binaryNode<T>* node)
{
    if(node == nullptr){
        std::cout << "[.]";
        return;
    }
	std::cout << node->data() << " ";
}

template<class T>
unsigned binarySearchTree<T>::insert(binaryNode<T>* node, binaryNode<T>*& root, unsigned comp)
{
    comp++;
	if(root == nullptr){
		root = node;
		return comp;
	}
	if(node->data() <= root->data())
		comp = insert(node, root->left(), comp);
	else
		comp = insert(node, root->right(), comp);
	
	return comp;
}

template<class T>
void binarySearchTree<T>::erase(T element, binaryNode<T>*& root)
{
    if(root == nullptr)
        return;

    if(element < root->data())
        erase(element, root->left());
    else if(element > root->data())
        erase(element, root->right());
    else{
        auto old = root;

        if(root->right() == nullptr)
            root = root->left();
        else if(root->left() == nullptr)
            root = root->right();
        else
            substitute(old, root->left());

        delete old;
    }
}

template<class T>
void binarySearchTree<T>::substitute(binaryNode<T>*& old, binaryNode<T>*& candidate)
{
    if(candidate->right() != nullptr)
        substitute(old, candidate->right());
    else{
        old->data() = candidate->data();
        old = candidate;
        candidate = candidate->left();
    }
}

template<class T>
bool binarySearchTree<T>::search(T element, binaryNode<T>* root, unsigned& comp)
{
    comp++;
    if(root == nullptr)
        return false;
    comp++;
    if(element == root->data())
        return true;
    comp++;
    if(element < root->data())
        return search(element, root->left(), comp);
    return search(element, root->right(), comp);
}

}

#endif // BINARYSEARCHTREE

