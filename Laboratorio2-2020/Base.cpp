#include <string>
#include "Base.h"

//
// Created by Matilde Pulidori on 27/04/2020.
//



Base::Base(std::string name) : name(name){
    std::cout<<"Costruttore Base: "<<name<<", @"<<std::hex<<this<<std::endl;
}

Base::~Base() {
    std::cout<<"Distruttore Base: "<<name<<", @"<<std::hex<<this<<std::endl;
}

std::string Base::getName() {
    return this->name;
}