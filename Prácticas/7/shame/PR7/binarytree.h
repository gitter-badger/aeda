/*! \file binarytree.h
  * \version 1.0
  * \date 17/03/2015
  * \author Daniel Ramos Acosta
  * \brief Header que contiene la clase del Árbol Binario
  * \code
  * //Código de ejemplo
  * <iostream>
  *
  * int main(void){
        binaryTree<int> mi_arbol;
        //Insertar de algun modo definido en la clase hija
        binaryTree.insert(new AVLNode(7))
        binaryTree.insert(new AVLNode(8))
        binaryTree.insert(new AVLNode(9))
        binaryTree.insert(new AVLNode(2))
        //Imprimir usando la clase padre
        std::cos << mi_arbol << std::endl;
    }
  * \endcode
*/

#ifndef BINARYTREE
#define BINARYTREE

#include <iostream> //std::ostream
#include <algorithm> //std::max
#include <deque> //std::deque
#include <iomanip> //std::setfill, std::setw
#include <cmath> //pow
#include <utility> //std::pair

#include "avlnode.h"

namespace dra{

template<class T>
class binaryTree{
protected:
    AVLNode<T>* root_;
public:
    //constructores
    binaryTree(void);
    ~binaryTree(void);

    //metodos para explorar el arbol
    void preOrder(void);
    void postOrder(void);
    void inOrder(void);
    void levelOrder(void);

    //metodos de informacion del arbol
    bool empty(void) const;
    unsigned size(void) const;
    unsigned height(void) const;

    //metodos para insertar el arbol

    //elminar del arbol
    void erase(T);

    //buscar un elemento en el arbo
    bool search(T, unsigned&);

    std::ostream& toStream(std::ostream&);

    //===============================================
    unsigned insert(T);
    unsigned insert(AVLNode<T>*, AVLNode<T>*&, bool&);
    bool isBalanced(void);
public:
    //void printPretty(std::ostream& os);
    void printLeaves(int indentSpace, int level, int nodesInThisLevel, const std::deque<dra::AVLNode<T>*>& nodesQueue, std::ostream& os);
    void printNodes(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const std::deque<dra::AVLNode<T>*>& nodesQueue, std::ostream& os);
    void printBranches(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const std::deque<dra::AVLNode<T>*>& nodesQueue, std::ostream& os);

public:
    void process(AVLNode<T>*); //metodo usado por los metodos para explorar el arbol
    void erase(T, AVLNode<T>*&, bool&);
    bool search(T, AVLNode<T>*, unsigned&);

    unsigned height(AVLNode<T>*) const;
public:
    void prune(AVLNode<T>*);

    void preOrder(AVLNode<T>*);
    void postOrder(AVLNode<T>*);
    void inOrder(AVLNode<T>*);
    void levelOrder(AVLNode<T>*);

    bool leave(AVLNode<T>*) const;
    bool empty(AVLNode<T>*) const;
    unsigned size(AVLNode<T>*) const;

    std::ostream& toStream(std::ostream&, AVLNode<T>*);
    //===============================================
    bool isBalanced(AVLNode<T>*);
    void insert_re_balancea_izada(AVLNode<T>*&, bool&);
    void insert_re_balancea_dcha(AVLNode<T>*&, bool&);

    //rotaciones
    void rotacion_II(AVLNode<T>*&);
    void rotacion_DD(AVLNode<T>*&);
    void rotacion_ID(AVLNode<T>*&);
    void rotacion_DI(AVLNode<T>*&);

    void eliminar_re_balancea_izda(AVLNode<T>*, bool&);
    void eliminar_re_balancea_dcha(AVLNode<T>*, bool&);

    void replace(AVLNode<T>*&, AVLNode<T>*&, bool&);

};

template<class T>
binaryTree<T>::binaryTree(void):
    root_(nullptr)
{}

template<class T>
binaryTree<T>::~binaryTree(void)
{
    prune(root_);
}

template<class T>
void binaryTree<T>::preOrder(void)
{
    preOrder(root_);
}

template<class T>
void binaryTree<T>::postOrder(void)
{
    postOrder(root_);
}

template<class T>
void binaryTree<T>::inOrder(void)
{
    inOrder(root_);
}

template<class T>
void binaryTree<T>::levelOrder(void)
{
    levelOrder(root_);
}


template<class T>
void binaryTree<T>::preOrder(AVLNode<T>* root)
{
    if(root == nullptr)
        return;
    process(root);
    preOrder(root->left());
    preOrder(root->right());
}

template<class T>
void binaryTree<T>::postOrder(AVLNode<T>* root)
{
    if(root == nullptr)
        return;
    postOrder(root->left());
    postOrder(root->right());
    process(root);
}

template<class T>
void binaryTree<T>::inOrder(AVLNode<T>* root)
{
    if(root == nullptr)
        return;
    inOrder(root->left());
    process(root);
    inOrder(root->right());
}

template<class T>
void binaryTree<T>::process(AVLNode<T>* node)
{
    if(node == nullptr)
        std::cout << "[.]";
    else
        node->data();
}

template<class T>
void binaryTree<T>::levelOrder(AVLNode<T>* root)
{
    std::deque<std::pair<AVLNode<T>*, unsigned>> q;

    q.push_back(std::pair<AVLNode<T>*, unsigned>(root, 0));

    unsigned currentLevel = 0;

    while(!q.empty())
    {
        auto node = std::get<0>(q.front());
        auto level = std::get<1>(q.front());
        q.pop_front();

        if(level > currentLevel){
            currentLevel = level;
            std::cout << std::endl;
        }

        if(node != nullptr){
            process(node);
            q.push_back(std::pair<AVLNode<T>*,unsigned>(node->left(), level+1));
            q.push_back(std::pair<AVLNode<T>*,unsigned>(node->right(), level+1));
        }
        else
            process(nullptr);
    }
}

template<class T>
void binaryTree<T>::prune(AVLNode<T>* node)
{
    if(empty(node))
        return;
    prune(node->left());
    prune(node->right());
    delete node;
    node = nullptr;
}

template<class T>
unsigned binaryTree<T>::size(void) const
{
    return size(root_);
}

template<class T>
unsigned binaryTree<T>::size(AVLNode<T>* node) const
{
    if(empty(node))
        return 0;
    return(1 + size(node->left()) + size(node->right()));
}

template<class T>
bool binaryTree<T>::leave(AVLNode<T>* node) const
{
    return empty(node->left()) && empty(node->right());
}

template<class T>
bool binaryTree<T>::empty(void) const
{
    return empty(root_);
}

template<class T>
bool binaryTree<T>::empty(AVLNode<T>* node) const
{
    return node == nullptr;
}

template<class T>
unsigned binaryTree<T>::height(void) const
{
    return height(root_);
}

template<class T>
unsigned binaryTree<T>::height(AVLNode<T>* node) const
{
    if(node == nullptr)
        return 0;

    return std::max(height(node->left()), height(node->right()))+1;
}

template<class T>
unsigned binaryTree<T>::insert(T element)
{
    AVLNode<T>* node = new AVLNode<T>(element);
    bool crece = false;
    return insert(node, root_, crece);
}

template<class T>
unsigned binaryTree<T>::insert(AVLNode<T>* node, AVLNode<T>*& root, bool& crece)
{
    if(root == nullptr){
        root = node;
        crece = true;
        node->bal() = 0;
        return 0;
    }


    if(node->data() <= root->data()){
        insert(node, root->left(), crece);
        if(crece){
            insert_re_balancea_izada(root, crece);
        }
    }
    else{
        insert(node, root->right(), crece);
        if(crece){
            insert_re_balancea_dcha(root, crece);
        }
    }
    return 0;
}


template<class T>
void binaryTree<T>::insert_re_balancea_izada(AVLNode<T>*& root, bool& crece)
{

    switch(root->bal()){
    case -1: root->bal() = 0;
             crece = false;
             break;
    case 0:  root->bal() = 1;
             break;
    case 1:  AVLNode<T>* aux = root->left();
             if(aux->bal() == 1)
                rotacion_II(root);
             else
                rotacion_ID(root);
             crece = false;
    }
}

template<class T>
void binaryTree<T>::insert_re_balancea_dcha(AVLNode<T>*& root, bool& crece)
{
    switch(root->bal()){
    case 1: root->bal() = 0;
             crece = false;
             break;
    case 0:  root->bal() = -1;
             break;
    case -1:  AVLNode<T>* aux = root->right();
             if(aux->bal() == -1)
                rotacion_DD(root);
             else
                rotacion_DI(root);
             crece = false;
    }
}

template<class T>
void binaryTree<T>::rotacion_II(AVLNode<T>*& node)
{
    AVLNode<T>* node1 = node->left();
    node->left() = node1->right();
    node1->right() = node;
    if(node1->bal() == 1){
        node->bal() = 0;
        node1->bal() = 0;
    }
    else{
        node->bal() = 1;
        node1->bal() = -1;
    }
    node = node1;
}

template<class T>
void binaryTree<T>::rotacion_DD(AVLNode<T>*& node)
{
    AVLNode<T>* node1 = node->right();
    node->right() = node1->left();
    node1->left() = node;
    if(node1->bal() == -1){
        node->bal() = 0;
        node1->bal() = 0;
    }
    else{
        node->bal() = -1;
        node1->bal() = 1;
    }
    node = node1;
}

template<class T>
void binaryTree<T>::rotacion_ID(AVLNode<T>*& node)
{

    AVLNode<T>* node1 = node->left();
    AVLNode<T>* node2 = node1->right();
    node->left() = node2->right();
    node2->right() = node;
    node1->right() = node2->left();
    node2->left() = node1;
    if(node2->bal() == -1)
        node1->bal() = 1;
    else
        node1->bal() = 0;
    if(node2->bal() == 1)
        node->bal() = -1;
    else
        node->bal() = 0;

    node2->bal() = 0;
    node = node2;
}

template<class T>
void binaryTree<T>::rotacion_DI(AVLNode<T>*& node)
{
    AVLNode<T>* node1 = node->right();
    AVLNode<T>* node2 = node1->left();



    std::cin.ignore().get();

    node->right() = node2->left();
    node2->left() = node;
    node1->left() = node2->right();
    node2->right() = node1;

    if(node2->bal() == 1)
        node1->bal() = -1;
    else
        node1->bal() = 0;
    if(node2->bal() == -1)
        node->bal() = 1;
    else
        node->bal() = 0;
    node2->bal() = 0;
    node = node2;
}

template<class T>
bool binaryTree<T>::isBalanced(void)
{
    return isBalanced(binaryTree<T>::root_);
}


template<class T>
bool binaryTree<T>::isBalanced(AVLNode<T>* root)
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

template<class T>
void binaryTree<T>::erase(T element)
{
    bool decrece = false;
    erase(element, root_, decrece);
}

template<class T>
void binaryTree<T>::erase(T element, AVLNode<T>*& node, bool& decrece)
{
    std::cout << "Soy el erase, quieres eliminar el " << element << " y estas en " << node->data() << std::endl;
    if(node == nullptr)
        return;
    if(element < node->data()){
        erase(element, node->left(), decrece);
        if(decrece)
            eliminar_re_balancea_izda(node, decrece);
    }
    else if(element > node->data()){
        erase(element, node->right(), decrece);
        if(decrece)
            eliminar_re_balancea_dcha(node, decrece);
    }
    else{
        AVLNode<T>* eliminado = node;
        if(node->left() == nullptr){
            node = node->right();
            decrece = true;
        }
        else if(node->right() == nullptr){
            node = node->left();
            decrece = true;
        }
        else{
            replace(eliminado, node->left(), decrece);
            if(decrece)
                eliminar_re_balancea_izda(node, decrece);
        }
        delete eliminado;
    }
}

template<class T>
void binaryTree<T>::eliminar_re_balancea_izda(AVLNode<T>* node, bool& decrece)
{
    switch(node->bal()){
    case -1: {AVLNode<T>* nodo1 = node->right();
        if(nodo1->bal() > 0)
            rotacion_DI(node);
        else{
            if(nodo1->bal() == 0)
                decrece = false;
            rotacion_DD(node);
        }
        break;}
    case 0: node->bal() = -1;
            decrece = false;
    case 1: node->bal() = 0;
    }
}

template<class T>
void binaryTree<T>::eliminar_re_balancea_dcha(AVLNode<T>* node, bool& decrece)
{
    switch(node->bal()){
    case 1: {AVLNode<T>* nodo1 = node->left();
        if(nodo1->bal() < 0)
            rotacion_ID(node);
        else{
            if(nodo1->bal() == 0)
                decrece = false;
            rotacion_II(node);
        }
        break;}
    case 0: node->bal() = 1;
            decrece = false;
    case -1: node->bal() = 0;
    }
}

template<class T>
void binaryTree<T>::replace(AVLNode<T>*& eliminado, AVLNode<T>*& sust, bool& decrece)
{
    if(sust->right() != nullptr){
        replace(eliminado, sust->right(), decrece);
        if(decrece)
            eliminar_re_balancea_dcha(sust, decrece);
    }
    else{
        eliminado->data() = sust->data();
        eliminado = sust;
        sust = sust->left();
        decrece = true;
    }
}

template<class T>
bool binaryTree<T>::search(T element, unsigned& comp)
{
    return search(element, root_, comp);
}

template<class T>
std::ostream& binaryTree<T>::toStream(std::ostream& os)
{
    toStream(os, root_);
    return os;
}

//==============================================================================
// Métodos para imprimir el arbol, sacado de:
// http://articles.leetcode.com/2010/09/how-to-pretty-print-binary-tree.html
//==============================================================================

template<typename T>
void binaryTree<T>::printBranches(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const std::deque<dra::AVLNode<T>*>& nodesQueue, std::ostream& out)
{
    auto iter = nodesQueue.begin();
    for (int i = 0; i < nodesInThisLevel / 2; i++) {
        out << ((i == 0) ? std::setw(startLen-1) : std::setw(nodeSpaceLen-2)) << "" << ((*iter++) ? "╱" : " ");
        out << std::setw(2*branchLen+2) << "" << ((*iter++) ? "╲" : " ");
    }
    out << std::endl;
}

template<typename T>
void binaryTree<T>::printNodes(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const std::deque<dra::AVLNode<T>*>& nodesQueue, std::ostream& out) {
    auto iter = nodesQueue.begin();
    for (int i = 0; i < nodesInThisLevel; i++, iter++) {
        out << ((i == 0) ? std::setw(startLen) : std::setw(nodeSpaceLen)) << "" << ((*iter != nullptr && (*iter)->left()) ? std::setfill('_') : std::setfill(' '));
        out << std::setw(branchLen+2);

        if(*iter != nullptr){
            out << (*iter)->data();/*
            out << "(";
            out << (*iter)->bal();
            out << ")";*/
        }
        else
            out << "";



        out << ((*iter != nullptr && (*iter)->right()) ? std::setfill('_') : std::setfill(' ')) << std::setw(branchLen) << "" << std::setfill(' ');
    }
    out << std::endl;
}

template<typename T>
void binaryTree<T>::printLeaves(int indentSpace, int level, int nodesInThisLevel, const std::deque<dra::AVLNode<T>*>& nodesQueue, std::ostream& out) {
    auto iter = nodesQueue.begin();
    for (int i = 0; i < nodesInThisLevel; i++, iter++) {
        out << ((i == 0) ? std::setw(indentSpace+2) : std::setw(2*level+2));


        if(*iter != nullptr)
            out << (*iter)->data();
        else
            out << "";
    }
    out << std::endl;
}

template<typename T>
std::ostream& binaryTree<T>::toStream(std::ostream& out, dra::AVLNode<T> *root)
{
    int level = 1;
    int indentSpace = 0;



    int h = height(root);
    int nodesInThisLevel = 1;

    int branchLen = 2*((int)pow(2.0,h)-1) - (3-level)*(int)pow(2.0,h-1);
    int nodeSpaceLen = 2 + (level+1)*(int)pow(2.0,h);
    int startLen = branchLen + (3-level) + indentSpace;

    std::deque<dra::AVLNode<T>*> nodesQueue;
    nodesQueue.push_back(root);
    for (int r = 1; r < h; r++) {
        printBranches(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);
        branchLen = branchLen/2 - 1;
        nodeSpaceLen = nodeSpaceLen/2 + 1;
        startLen = branchLen + (3-level) + indentSpace;
        printNodes(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);

        for (int i = 0; i < nodesInThisLevel; i++) {
            dra::AVLNode<T> *currNode = nodesQueue.front();
            nodesQueue.pop_front();
            if (currNode) {
                nodesQueue.push_back(currNode->left());
                nodesQueue.push_back(currNode->right());
            } else {
                nodesQueue.push_back(NULL);
                nodesQueue.push_back(NULL);
            }
        }
        nodesInThisLevel *= 2;
    }
    printBranches(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);
    printLeaves(indentSpace, level, nodesInThisLevel, nodesQueue, out);
    return out;
}

}

#endif // BINARYTREE
