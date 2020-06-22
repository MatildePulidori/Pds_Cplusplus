//
// Created by Matilde Pulidori on 20/06/2020.
//

#include "Base2.h"
Base2::Base2(std::string name):name(name) {
}

Base2::~Base2() {
}

Base2::Base2(const Base2 &other):name(other.name) {
}

Base2& Base2::operator=(const Base2 &other){
    if(this!=&other) {
        this->name = other.name;
    }
    return *this;
}

std::string Base2::getName() const {
    return this->name;
}

int Base2::mType() const {
    return this->type;
}
