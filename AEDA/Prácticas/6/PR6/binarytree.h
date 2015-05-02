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
        binaryTree.insert(new binaryNode(7))
        binaryTree.insert(new binaryNode(8))
        binaryTree.insert(new binaryNode(9))
        binaryTree.insert(new binaryNode(2))
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

#include "binarynode.h"

namespace dra{

template<class T>
class binaryTree{
private:
    binaryNode<T>* root_;
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
    void insert(binaryNode<T>*);

    std::ostream& toStream(std::ostream&);
private:
    //void printPretty(std::ostream& os);
    void printLeaves(int indentSpace, int level, int nodesInThisLevel, const std::deque<dra::binaryNode<T>*>& nodesQueue, std::ostream& os);
    void printNodes(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const std::deque<dra::binaryNode<T>*>& nodesQueue, std::ostream& os);
    void printBranches(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const std::deque<dra::binaryNode<T>*>& nodesQueue, std::ostream& os);

protected:
    virtual void process(binaryNode<T>*)=0; //metodo usado por los metodos para explorar el arbol
    virtual void insert(binaryNode<T>*, binaryNode<T>*&)=0;
private:
    void prune(binaryNode<T>*);

    void preOrder(binaryNode<T>*);
    void postOrder(binaryNode<T>*);
    void inOrder(binaryNode<T>*);
    void levelOrder(binaryNode<T>*, unsigned, std::vector<std::vector<binaryNode<T>*>>&);

    bool leave(binaryNode<T>*) const;
    bool empty(binaryNode<T>*) const;
    unsigned size(binaryNode<T>*) const;
    unsigned height(binaryNode<T>*) const;

    std::ostream& toStream(std::ostream&, binaryNode<T>*);
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
    std::vector<std::vector<binaryNode<T>*>> vec;
    levelOrder(root_, 0, vec);
    for(unsigned i = 0; i < vec.size(); i++)
        for(unsigned j = 0; j < vec[i].size(); j++)
            process(vec[i][j]);
}


template<class T>
void binaryTree<T>::preOrder(binaryNode<T>* node)
{
    if(node == nullptr)
        return;
    process(node);
    preOrder(node->left());
    preOrder(node->right());
}

template<class T>
void binaryTree<T>::postOrder(binaryNode<T>* node)
{
    if(node == nullptr)
        return;
    postOrder(node->left());
    postOrder(node->right());
    process(node);
}

template<class T>
void binaryTree<T>::inOrder(binaryNode<T>* node)
{
    if(node == nullptr)
        return;
    inOrder(node->left());
    process(node);
    inOrder(node->right());
}

template<class T>
void binaryTree<T>::levelOrder(binaryNode<T>* node, unsigned level, std::vector<std::vector<binaryNode<T>*>>& vec)
{
    if(node == nullptr)
        return;

    if(level >= vec.size()){
        std::vector<binaryNode<T>*> dummy;
        vec.push_back(dummy);
    }

    vec[level].push_back(node);

    levelOrder(node->left(), level+1, vec);
    levelOrder(node->right(), level+1, vec);
}

template<class T>
void binaryTree<T>::prune(binaryNode<T>* node)
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
unsigned binaryTree<T>::size(binaryNode<T>* node) const
{
    if(empty(node))
        return 0;
    return(1 + size(node->left()) + size(node->right()));
}

template<class T>
bool binaryTree<T>::leave(binaryNode<T>* node) const
{
    return empty(node->left()) && empty(node->right());
}

template<class T>
bool binaryTree<T>::empty(void) const
{
    return empty(root_);
}

template<class T>
bool binaryTree<T>::empty(binaryNode<T>* node) const
{
    return node == nullptr;
}

template<class T>
unsigned binaryTree<T>::height(void) const
{
    return height(root_);
}

template<class T>
unsigned binaryTree<T>::height(binaryNode<T>* node) const
{
    if(node == nullptr)
        return 0;

    return std::max(height(node->left()), height(node->right()))+1;
}

template<class T>
void binaryTree<T>::insert(binaryNode<T>* node)
{
    insert(node, root_);
}

template<class T>
std::ostream& binaryTree<T>::toStream(std::ostream& os)
{
    toStream(os, root_);
    return os;
}

/*
template<typename T>
void binaryTree<T>::printBranches(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const std::deque<dra::binaryNode<T>*>& nodesQueue, std::ostream& os)
{
    auto iter = nodesQueue.begin();
    for (int i = 0; i < nodesInThisLevel / 2; i++) {
        os << ((i == 0) ? std::setw(startLen-1) : std::setw(nodeSpaceLen-2)) << "" << ((*iter++) ? "/" : " ");
        os << std::setw(2*branchLen+2) << "" << ((*iter++) ? "\\" : " ");
    }
    os << std::endl;
}

template<typename T>
void binaryTree<T>::printNodes(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const std::deque<dra::binaryNode<T>*>& nodesQueue, std::ostream& os) {
    auto iter = nodesQueue.begin();
    for (int i = 0; i < nodesInThisLevel; i++, iter++) {
        
        os << ((i == 0) ? std::setw(startLen) : std::setw(nodeSpaceLen)) << "";
        
        if(*iter != nullptr && (*iter)->left() != nullptr)
            os << std::setfill('_');
        else
            os << std::setfill(' ');
        
        os << std::setw(branchLen+2);
        
        if(*iter != nullptr) os << (*iter)->data();
        
        if(*iter != nullptr && (*iter)->right() != nullptr)
            os << std::setfill('_');
        else
            os << std::setfill(' ');
        
        os << std::setw(branchLen) << "" << std::setfill(' ');
    }
    os << std::endl;
}

template<typename T>
void binaryTree<T>::printLeaves(int indentSpace, int level, int nodesInThisLevel, const std::deque<dra::binaryNode<T>*>& nodesQueue, std::ostream& os)
{
    auto iter = nodesQueue.begin();
    for (int i = 0; i < nodesInThisLevel; i++, iter++) {
        
        if(i == 0)
            os << std::setw(indentSpace+2);
        else
            os << std::setw(2*level+2);
        
        if(*iter != nullptr)
            os << (*iter)->data();
        else
            os << "";
    }
    os << std::endl;
}

template<typename T>
std::ostream& binaryTree<T>::toStream(std::ostream& os, binaryNode<T>* root)
{
    int h = height(root);
    int nodesInThisLevel = 1;

    int branchLen = 2*(pow(2,h)-1) - 2*pow(2,h-1);
    int nodeSpaceLen = 2 + 2*pow(2,h);
    int startLen = branchLen + 2;

    std::deque<dra::binaryNode<T>*> nodesQueue;
    nodesQueue.push_back(root);
    
    for (int r = 1; r < h; r++) {
        printBranches(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, os);
        branchLen = branchLen/2 - 1;
        nodeSpaceLen = nodeSpaceLen/2 + 1;
        startLen = branchLen + (2);
        printNodes(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, os);

        for (int i = 0; i < nodesInThisLevel; i++) {
            dra::binaryNode<T> *currNode = nodesQueue.front();
            nodesQueue.pop_front();
            if (currNode) {
                nodesQueue.push_back(currNode->left());
                nodesQueue.push_back(currNode->right());
            } else {
                nodesQueue.push_back(nullptr);
                nodesQueue.push_back(nullptr);
            }
        }
        nodesInThisLevel *= 2;
    }
    printBranches(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, os);
    printLeaves(0, 1, nodesInThisLevel, nodesQueue, os);
    
    return os;
}

template<class T>
// Convert an integer value to string
std::string binaryTree<T>::intToString(int val) {
    std::ostringstream ss;
    ss << val;
    return ss.str();
}*/

template<typename T>
void binaryTree<T>::printBranches(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const std::deque<dra::binaryNode<T>*>& nodesQueue, std::ostream& out)
{
    auto iter = nodesQueue.begin();
    for (int i = 0; i < nodesInThisLevel / 2; i++) {
        out << ((i == 0) ? std::setw(startLen-1) : std::setw(nodeSpaceLen-2)) << "" << ((*iter++) ? "/" : " ");
        out << std::setw(2*branchLen+2) << "" << ((*iter++) ? "\\" : " ");
    }
    out << std::endl;
}

// Print the branches and node (eg, ___10___ )
template<typename T>
void binaryTree<T>::printNodes(int branchLen, int nodeSpaceLen, int startLen, int nodesInThisLevel, const std::deque<dra::binaryNode<T>*>& nodesQueue, std::ostream& out) {
    auto iter = nodesQueue.begin();
    for (int i = 0; i < nodesInThisLevel; i++, iter++) {
        out << ((i == 0) ? std::setw(startLen) : std::setw(nodeSpaceLen)) << "" << ((*iter != nullptr && (*iter)->left()) ? std::setfill('_') : std::setfill(' '));
        out << std::setw(branchLen+2);
        
        if(*iter != nullptr)
            out << (*iter)->data();
        else
            out << "";
        
        
        
        out << ((*iter != nullptr && (*iter)->right()) ? std::setfill('_') : std::setfill(' ')) << std::setw(branchLen) << "" << std::setfill(' ');
    }
    out << std::endl;
}

// Print the leaves only (just for the bottom row)
template<typename T>
void binaryTree<T>::printLeaves(int indentSpace, int level, int nodesInThisLevel, const std::deque<dra::binaryNode<T>*>& nodesQueue, std::ostream& out) {
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

// Pretty formatting of a binary tree to the output stream
// @ param
// level  Control how wide you want the tree to sparse (eg, level 1 has the minimum space between nodes, while level 2 has a larger space between nodes)
// indentSpace  Change this to add some indent space to the left (eg, indentSpace of 0 means the lowest level of the left node will stick to the left margin)


template<typename T>
std::ostream& binaryTree<T>::toStream(std::ostream& out, dra::binaryNode<T> *root)
{
    int level = 1;
    int indentSpace = 0;



    int h = height(root);
    int nodesInThisLevel = 1;

    int branchLen = 2*((int)pow(2.0,h)-1) - (3-level)*(int)pow(2.0,h-1);  // eq of the length of branch for each node of each level
    int nodeSpaceLen = 2 + (level+1)*(int)pow(2.0,h);  // distance between left neighbor node's right arm and right neighbor node's left arm
    int startLen = branchLen + (3-level) + indentSpace;  // starting space to the first node to print of each level (for the left most node of each level only)

    std::deque<dra::binaryNode<T>*> nodesQueue;
    nodesQueue.push_back(root);
    for (int r = 1; r < h; r++) {
        printBranches(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);
        branchLen = branchLen/2 - 1;
        nodeSpaceLen = nodeSpaceLen/2 + 1;
        startLen = branchLen + (3-level) + indentSpace;
        printNodes(branchLen, nodeSpaceLen, startLen, nodesInThisLevel, nodesQueue, out);

        for (int i = 0; i < nodesInThisLevel; i++) {
            dra::binaryNode<T> *currNode = nodesQueue.front();
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
