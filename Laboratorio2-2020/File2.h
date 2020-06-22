//
// Created by Matilde Pulidori on 22/06/2020.
//

#ifndef LABORATORIO2_2020_FILE2_H
#define LABORATORIO2_2020_FILE2_H


#include "Base2.h"

class File2: public Base2{
    int type = 1;
    uintmax_t size;

public:
    File2(std::string name, uintmax_t size);

    uintmax_t getSize() const;
    int mType() const override;
    void ls(int indent, int level=1) const override;

};


#endif //LABORATORIO2_2020_FILE2_H
