#ifndef BINARYSEARCHTREE
#define BINARYSEARCHTREE

#include "binarytree.h"

namespace dra{

template<class T>
class binarySearchTree : public binaryTree<T>{
protected:
	virtual void process(binaryNode<T>*);
	virtual void insert(binaryNode<T>*, binaryNode<T>*&);
    virtual void erase(T, binaryNode<T>*&);
    virtual bool search(T, binaryNode<T>*);
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
void binarySearchTree<T>::insert(binaryNode<T>* node, binaryNode<T>*& root)
{
	if(root == nullptr){
		root = node;
		return;
	}
	if(node->data() <= root->data())
		insert(node, root->left());
	else
		insert(node, root->right());
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
bool binarySearchTree<T>::search(T element, binaryNode<T>* root)
{
    if(root == nullptr)
        return false;
    if(element == root->data())
        return true;
    if(element < root->data())
        return search(element, root->left());
    return search(element, root->right());
}

}

#endif // BINARYSEARCHTREE

