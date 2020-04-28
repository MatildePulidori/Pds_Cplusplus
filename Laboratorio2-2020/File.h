//
// Created by Matilde Pulidori on 28/04/2020.
//

#ifndef LABORATORIO2_2020_FILE_H
#define LABORATORIO2_2020_FILE_H


#include "Base.h"

class File: public Base{
    friend class Directory;

protected:
    uintmax_t size;
    int type = 1;
    std::weak_ptr<File> mySelf;

public:
    File(std::string name, uintmax_t size);
    ~File();
    uintmax_t getSize() const;
    int getType() const override;

    void ls(int indent) const override;

};


#endif //LABORATORIO2_2020_FILE_H
