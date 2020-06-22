//
// Created by Matilde Pulidori on 22/06/2020.
//

#include <iostream>
#include "File2.h"


File2::File2(std::string name, uintmax_t size): Base2(name), size(size){
}

int File2::mType() const {
    return this->type;
}

uintmax_t File2::getSize() const {
    return this->size;
}


void File2::ls(int indent, int level) const {
    for(int i=0; i<level; i++){
        std::cout<<"\t";
    }
    std::cout<<this->getName()<<", size:"<<this->getSize()<<std::endl;

}



