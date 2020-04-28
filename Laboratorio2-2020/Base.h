//
// Created by Matilde Pulidori on 27/04/2020.
//

#ifndef LABORATORIO2_2020_BASE_H
#define LABORATORIO2_2020_BASE_H

#include <string>
#include <iostream>

class Base {

protected:
    std::string name;
    Base(std::string name );

public:

    ~Base();
    std::string getName() const;
    virtual int getType() const= 0;
    virtual void ls(int indent=0) const = 0;

};


#endif //LABORATORIO2_2020_BASE_H
