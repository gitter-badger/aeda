#ifndef AVLTREE
#define AVLTREE

#include "binarysearchtree.h"
#include "avlnode.h"

namespace dra{

template<class T>
class AVLTree : public binarySearchTree<T>{
public:
    void insert(T);
    void insert(AVLNode<T>*, binaryNode<T>*&, bool&);
    bool isBalanced(void);
private:
    bool isBalanced(binaryNode<T>*);
    void insert_re_balancea_izada(binaryNode<T>*&, bool&);
    void insert_re_balancea_dcha(binaryNode<T>*&, bool&);
};

template<class T>
void AVLTree<T>::insert(T data)
{
    bool crece = false;
    std::cout << "El puntero root es binaryNode y apunta a: " << binaryTree<T>::root_ << std::endl;
    
    
    
    
    insert(new AVLNode<T>(data, 0), binaryTree<T>::root_, crece);
}

template<class T>
void AVLTree<T>::insert(AVLNode<T>* node, binaryNode<T>*& root, bool& crece)
{
    if(root == nullptr){
        root = node;
        crece = true;
        return;
    }
    else if(node->data() <= root->data()){
        insert(node, root->left(), crece);
        if(crece) insert_re_balancea_izada(root, crece);
    }
    else{
        insert(node, root->right(), crece);
        if(crece) insert_re_balancea_dcha(root, crece);
    }
}

template<class T>
void AVLTree<T>::insert_re_balancea_izada(binaryNode<T>*& root, bool& crece)
{
    std::cout << "insert_re_balancea_izda" << std::endl;
}

template<class T>
void AVLTree<T>::insert_re_balancea_dcha(binaryNode<T>*& root, bool& crece)
{
    std::cout << "insert_re_balancea_dcha" << std::endl;
}

template<class T>
bool AVLTree<T>::isBalanced(void)
{
    return isBalanced(binaryTree<T>::root_);
}


template<class T>
bool AVLTree<T>::isBalanced(binaryNode<T>* root)
{
    if(root == nullptr)
        return true;

    int balance_factor = this->height(root->left()) - this->height(root->right());

    switch(balance_factor){
    case -1:
    case  0:
    case  1:
        return isBalanced(root->left()) && isBalanced(root->right());
    }
    return false;
}



}

/*
class ArbolAVL {
private:
    class nodoAVL { // nodo de ArbolAVL
    public:
        // Constructor:
        nodoAVL(int dat, int cl, nodoAVL *iz=NULL, nodoAVL *de=NULL):
            dato(dat),
            clave(cl),
            bal(0),
            izdo(iz),
            dcho(de) {}
        // Miembros:
        int dato; int clave; int bal;
        nodoAVL *izdo; nodoAVL *dcho;
    };
    nodoAVL *raiz;
public:
    ...
}*/

#endif // AVLTREE

