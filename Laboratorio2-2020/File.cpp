//
// Created by Matilde Pulidori on 28/04/2020.
//

#include "File.h"


File::File(std::string name, uintmax_t size): Base(name), size(size) {}

File::~File() {}

uintmax_t File::getSize() const {
    return this->size;
}

int File::getType() const {
    return this->type;
}

void File::ls(int indent) const {

    std::cout<<this->getName()<<" "<<this->getSize()<<" MB"<<std::endl;
}