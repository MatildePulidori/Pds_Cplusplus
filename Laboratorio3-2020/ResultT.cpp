//
// Created by Matilde Pulidori on 18/05/2020.
//

#include <ntsid.h>
#include <vector>
#include "ResultT.h"

ResultT::ResultT() = default;
ResultT::ResultT(std::string key, int value) : key(std::move(key)), value(std::move(value)) {
    this->serialize();
}

std::string ResultT::getKey() const {
    return key;
}

int ResultT::getValue() const {
    return value;
}

std::vector<char> ResultT::serialize() {
    ushort sizeInt = sizeof(int);
    ushort sizeString = sizeof(std::string);
    std::vector<char> buff(2*sizeof(short)+sizeInt+sizeString);

    std::copy((char*)&sizeString, (char*)&sizeString + sizeof(ushort), buff.begin()); // key dimension
    std::copy((char*)&this->key, (char*)&this->key + sizeString, buff.begin()+ sizeof(ushort)); // key
    std::copy((char*)&sizeInt, (char*)&sizeInt + sizeof(ushort), buff.begin()+sizeof(ushort)+sizeString); // value dimension
    std::copy((char*)&value, (char*)&value + sizeof(int), buff.begin()+sizeof(ushort)+sizeString+ sizeof(ushort)); //value

    return buff;
};

void ResultT::deserialize(std::vector<char> buff) {
        std::copy(buff.begin(), buff.begin()+sizeof(int), (char*)&value);
}