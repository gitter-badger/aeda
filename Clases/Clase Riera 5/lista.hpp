#pragma once

#include <cstdio>
#include <iostream>

#include "nodo.hpp"

using namespace std;

namespace AEDA
{
    class list_t{
    private:
        nodo_t* first_;
        nodo_t* last_;
    public:
        list_t(void):
        first_(nullptr),
        last_(nullptr)
        {}
        
        virtual ~list_t(void)
        {
            nodo_t* aux;
            while(first_ != nullptr){
                aux = first_;
                first_ = first_->get_next();
                delete aux;
            }
        }
        bool empty(void)
        {
            return (first_ == nullptr)
        }
        ostream& toStream(ostream& os)
        {
            nodo_t aux = first_;
            while(aux != nullptr){
                aux->toStream(os);
                aux = aux -> get_next();
            }
            return os;
        }
        void insert_first(node_t* n)
        {
            if(empty())
            {
                first_ = n;
                last_ = n;
            }
            else{
                n->set_next(first_);
                first_ = n;
            }
        }
        node_t* extract_first(void)
        {
            node_t* aux = first_;
            if(first_ == last_)
                last_ = nullptr;
            first_ = first_->get_next();
            aux->set_next(nullptr)
            return aux;
        }
        void insert_last(nodo_t* n)
        {
            if(empty())
            {
                first_ = n;
                last_ = n;
            }
            else{
                last_->set_next(n);
                last_ = n;
            }
        }
    };
}