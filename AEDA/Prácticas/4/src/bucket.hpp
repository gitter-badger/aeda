#ifndef _BUCKET_HPP_
#define _BUCKET_HPP_

#include "common.hpp"
#include "key.hpp"

class dra::bucket{
private:
    dra::cells_n_t cells_n_;
    
    dra::key** cell_;
public:
    bucket(void);
    bucket(cells_n_t);
    ~bucket(void);
    bool search(dra::key*);
    bool insert(dra::key*);
    std::ostream& toStream(std::ostream& os);
};

dra::bucket::bucket(void):
cell_(nullptr)
{}

dra::bucket::bucket(dra::cells_n_t cells_n):
cells_n_(cells_n)
{
    std::cout << "Voy a construir un array de punteros a keys, " << cells_n_ << " en total." << std::endl;
    cell_ = new dra::key*[cells_n];
}

dra::bucket::~bucket(void)
{
    if(cell_ != nullptr)
        delete[] cell_;
        
    std::cout << "Desutrido un bucket" << std::endl;
}

bool dra::bucket::insert(dra::key* ikey)
{
    for(unsigned i = 0; i < cells_n_; i++){
        if(cell_[i] == nullptr){
            cell_[i] = ikey;
            return true;
        }
    }
    return false;
}


std::ostream& dra::bucket::toStream(std::ostream& os)
{
    for(int i = 0; i < cells_n_; i++){
        if(cell_[i] == nullptr)
            std::cout << "NULL" << std::endl;
        else
            std::cout << cell_[i] << std::endl;
    }
}

#endif