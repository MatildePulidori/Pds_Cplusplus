//
// Created by Matilde Pulidori on 27/04/2020.
//

#ifndef LABORATORIO2_2020_DIRECTORY_H
#define LABORATORIO2_2020_DIRECTORY_H


#include <string>
#include <vector>
#include "Base.h"

class Directory: public Base{

protected:
    int type=0;
    static std::shared_ptr<Directory> root;
    std::vector<std::shared_ptr<Base>> files;
    std::weak_ptr<Directory> parent;
    std::weak_ptr<Directory> mySelf;
    Directory(std::string nome);

public:

    ~Directory();

    int getType() const override;
    static std::shared_ptr<Directory> getRoot();
    static std::shared_ptr<Directory> makeDir(std::string nome, std::weak_ptr<Directory> parent);

    void ls(int indent) const override;
    std::shared_ptr<Base> get(std::string nome);

    std::shared_ptr<Directory> addDirectory(std::string nome);

};


#endif //LABORATORIO2_2020_DIRECTORY_H
