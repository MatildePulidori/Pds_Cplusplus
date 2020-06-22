//
// Created by Matilde Pulidori on 20/06/2020.
//

#ifndef LABORATORIO2_2020_BASE2_H
#define LABORATORIO2_2020_BASE2_H


#include <string>

class Base2 {
    std::string name;
    int type ;
public:

    Base2(std::string name);
    ~Base2();
    Base2(const Base2& other);
    Base2& operator=(const Base2& other);

    virtual std::string getName() const;
    virtual int mType() const =0;
    virtual void ls(int indent, int level=0) const=0;



};


#endif //LABORATORIO2_2020_BASE2_H
