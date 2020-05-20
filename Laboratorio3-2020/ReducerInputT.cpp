//
// Created by Matilde Pulidori on 18/05/2020.
//

#include <vector>
#include <iomanip>
#include <sstream>
#include <ios>
#include "ReducerInputT.h"

#define MAX_DIM 8

ReducerInputT::ReducerInputT(const std::string key, int value, int accum) : key(key), value(value), accum(accum) {
}

const std::string &ReducerInputT::getKey() const {
    return key;
}

int ReducerInputT::getValue() const {
    return value;
}


int ReducerInputT::getAccum() const {
    return accum;
}

std::vector<char> ReducerInputT::serialize() const {

    std::vector<char> serialized;

    for(int i=0, n=sizeof(this); i< MAX_DIM, n>0; i++, n=n/2) {
        serialized.push_back(n % 2);
    }

    serialized.push_back( std::for_each(this->getKey().begin(), this->getKey().end(), this->getKey().));


    return serialized;
}

void ReducerInputT::deserialize(std::vector<char *> vector) {

}