//
// Created by Matilde Pulidori on 18/05/2020.
//

#include <ntsid.h>
#include <vector>
#include "ResultT.h"

ResultT::ResultT() = default;
ResultT::ResultT(std::string key, int value) : key(std::move(key)), value(std::move(value)) {
    std::vector<char> ser = this->serialize();
    this->deserialize(ser);
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
    ushort sizeTot = 2*sizeof(short)+sizeInt+sizeString;
    std::vector<char> buff(sizeTot);

    ushort position = 0;
    std::copy((char*)&sizeString, (char*)&sizeString + sizeof(ushort), buff.begin()); // key dimension
    position += sizeof(ushort);
    std::copy((char*)&this->key, (char*)&this->key + sizeString, buff.begin()+position); // key
    position += sizeString;
    std::copy((char*)&sizeInt, (char*)&sizeInt + sizeof(ushort), buff.begin()+position); // value dimension
    position += sizeof(ushort);
    std::copy((char*)&value, (char*)&value + sizeof(int), buff.begin()+position); //value

    return buff;
};

void ResultT::deserialize(std::vector<char> buff) {

    ushort sizeTot = buff.size();

    ushort position = 0;
    ushort toAdd = position+sizeof(ushort);
    ushort toAddNext = sizeof(ushort);
    bool key = false ;


    while (toAdd <= sizeTot) {

        if(toAddNext == sizeof(ushort)) {
            std::copy(buff.begin() + position, buff.begin() + toAdd, (char *) &toAddNext);

        } else {
            if(key==false){
                std::copy(buff.begin() + position, buff.begin() + toAdd, (char *) &this->key);
                key=true;
                toAddNext= sizeof(ushort);
            }
            else std::copy(buff.begin() + position, buff.begin() + toAdd, (char *) &this->value);
        }

        position =toAdd;
        toAdd += toAddNext;
    }
}