//
// Created by Matilde Pulidori on 20/06/2020.
//

#ifndef LABORATORIO2_2020_DIRECTORY2_H
#define LABORATORIO2_2020_DIRECTORY2_H


#include <string>
#include <vector>
#include "Base2.h"
#include "File2.h"

class Directory2 : public Base2{
    int type = 0;
    std::vector<std::shared_ptr<Base2>> files;
    std::weak_ptr<Directory2> parent;
    std::weak_ptr<Directory2> mySelf;

    static std::shared_ptr<Directory2> root;
    static bool exists;
    static std::shared_ptr<Directory2> makeDirectory(std::string name, std::weak_ptr<Directory2> parent);
    Directory2(std::string name);

public:
    int mType() const override;
    void ls(int indent, int level=1) const override;

    static std::shared_ptr<Directory2> getRoot();
    std::vector<std::shared_ptr<Base2>> getFiles();
    std::weak_ptr<Directory2> getParent();
    std::shared_ptr<Directory2> getDir(std::string name);
    std::shared_ptr<File2> getFile(std::string name);

    std::shared_ptr<Base2> get(std::string name);

    std::shared_ptr<Directory2> addDirectory(std::string name);
    std::shared_ptr<File2> addFile(std::string name, uintmax_t size);
};


#endif //LABORATORIO2_2020_DIRECTORY2_H
