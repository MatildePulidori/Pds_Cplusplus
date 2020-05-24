//
// Created by Matilde Pulidori on 24/05/2020.
//

#include "DriverInputT.h"

DriverInputT::DriverInputT(std::string input): filename(input) {}

DriverInputT::~DriverInputT() {}

std::string DriverInputT::getFilename() {
    return this->filename;
}
