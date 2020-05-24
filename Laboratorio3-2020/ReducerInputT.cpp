//
// Created by Matilde Pulidori on 18/05/2020.
//

#include <utility>
#include <vector>
#include <iomanip>
#include <sstream>
#include <ios>
#include "ReducerInputT.h"

#define MAX_DIM 8

ReducerInputT::ReducerInputT(std::string key, int value, int accum) : key(std::move(key)), value(value), accum(accum) {
    this->serialize();
}

ReducerInputT::~ReducerInputT()= default;

std::string ReducerInputT::getKey() const{
    return key;
}

int ReducerInputT::getValue() const{
    return value;
}


int ReducerInputT::getAccum() const{
    return accum;
}

std::vector<char> ReducerInputT::serialize() {

    ushort sizeInt = sizeof(int);
    ushort sizeString = sizeof(std::string);
    std::vector<char> buff(3* sizeof(ushort) + sizeString + 2*sizeInt);

    std::copy((char*)&sizeString, (char*)&sizeString + sizeof(ushort), buff.begin()); // key dimension
    std::copy((char*)&this->key, (char*)&this->key + sizeString, buff.begin()+ sizeof(ushort)); // key
    std::copy((char*)&sizeInt, (char*)&sizeInt + sizeof(ushort), buff.begin()+sizeof(ushort)+sizeString); // value dimension
    std::copy((char*)&value, (char*)&value + sizeof(int), buff.begin()+sizeof(ushort)+sizeString+ sizeof(ushort)); //value

    std::copy((char*)&sizeInt, (char*)&sizeInt + sizeof(ushort), buff.begin()+sizeof(ushort)+sizeString+sizeof(ushort)+sizeInt); // value dimension
    std::copy((char*)&value, (char*)&value + sizeof(int), buff.begin()+sizeof(ushort)+sizeString+ 2*sizeof(ushort)+sizeInt); //value

    buff.shrink_to_fit();

    return buff;
}

void ReducerInputT::deserialize(std::vector<char> buff) {
   // std::copy(buff.begin()+ sizeof(ushort), buff.begin()+sizeof(std::string), (char*)&this->);
}


