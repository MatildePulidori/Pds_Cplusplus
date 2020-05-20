//
// Created by Matilde Pulidori on 18/05/2020.
//

#include "ResultT.h"

ResultT::ResultT():key(""), value(0) {}
ResultT::ResultT(std::string key, int value) : key(key), value(value) {}

const std::string &ResultT::getKey() const {
    return key;
}

int ResultT::getValue() const {
    return value;
}

