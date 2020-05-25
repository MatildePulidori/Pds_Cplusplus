//
// Created by Matilde Pulidori on 18/05/2020.
//

#include <utility>
#include <vector>
#include <iomanip>
#include "ReducerInputT.h"


ReducerInputT::ReducerInputT(std::string key, int value, int accum) : key(std::move(key)), value(value), accum(accum) {
    std::vector<char> ser = this->serialize();
    this->deserialize(ser);
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
    ushort sizeTot = 3*sizeof(ushort) + sizeString + 2*sizeInt;


    ushort position = 0;
    std::vector<char> buff(3* sizeof(ushort) + sizeString + 2*sizeInt);

    std::copy((char*)&sizeString, (char*)&sizeString + sizeof(ushort), buff.begin()); // key dimension
    position += sizeof(ushort);
    std::copy((char*)&this->key, (char*)&this->key + sizeString, buff.begin()+position); // key
    position += sizeString;
    std::copy((char*)&sizeInt, (char*)&sizeInt + sizeof(ushort), buff.begin()+position); // value dimension
    position += sizeof(ushort);
    std::copy((char*)&this->value, (char*)&this->value + sizeInt, buff.begin()+position); //value
    position+= sizeInt;
    std::copy((char*)&sizeInt, (char*)&sizeInt + sizeof(ushort), buff.begin()+position); // accumulator dimension
    position += sizeof(ushort);
    std::copy((char*)&this->accum, (char*)&this->accum + sizeInt, buff.begin()+position); // accumulator

    buff.shrink_to_fit();

    return buff;
}

void ReducerInputT::deserialize(std::vector<char> buff) {

    ushort sizeTot = buff.size();

    ushort position = 0;
    ushort toAdd = position+sizeof(ushort);
    ushort toAddNext = sizeof(ushort);
    bool key = false ;
    bool val = false ;


    while (toAdd <= sizeTot) {

        if(toAddNext == sizeof(ushort)) {
            std::copy(buff.begin() + position, buff.begin() + toAdd, (char *) &toAddNext);

        } else {
            if(key==false){
                std::copy(buff.begin() + position, buff.begin() + toAdd, (char *) &this->key);
                key=true;
                toAddNext= sizeof(ushort);
            }
            else if (val ==false){
                std::copy(buff.begin() + position, buff.begin() + toAdd, (char *) &this->value);
                val =true;
                toAddNext= sizeof(ushort);
            } else {
                std::copy(buff.begin() + position, buff.begin() + toAdd, (char *) &this->accum);
            }
        }

        position =toAdd;
        toAdd += toAddNext;
    }

}


