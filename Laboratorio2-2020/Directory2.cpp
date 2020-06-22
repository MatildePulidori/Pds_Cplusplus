//
// Created by Matilde Pulidori on 20/06/2020.
//

#include <iostream>
#include <optional>
#include "Directory2.h"

std::shared_ptr<Directory2> Directory2::root;
bool Directory2::exists;

std::shared_ptr<Directory2> Directory2::getRoot() {
    if(!exists) {
        exists = true;
        root = std::shared_ptr<Directory2>(new Directory2("/"));
        root->parent = root;
        root->mySelf = root;
    }
    return root;
}

Directory2::Directory2(std::string name) :Base2(name){
}

int Directory2::mType() const {
    return this->type;
}

std::weak_ptr<Directory2> Directory2::getParent() {
    return this->parent;
}

std::vector<std::shared_ptr<Base2>> Directory2::getFiles() {
    return this->files;
}


void Directory2::ls( int indent, int level) const{

    if (indent == 0){
        std::cout<<"[+] ";
        std::cout<<this->getName();
        std::cout<<std::endl;
        indent +=1;
    }

    std::for_each(this->files.begin(), this->files.end(), [indent, level](std::shared_ptr<Base2> f){

        // caso directory
        if (f->mType() == 0 && level>=indent){
            for(int i=0;i<level;i++){
                std::cout<<"\t";
            }
            std::cout<<"[+] ";
            std::cout<<f->getName()<<"/ "<<std::endl;
        }

        f->ls(indent, level+1);

    });

}

std::shared_ptr<Base2> Directory2::get(std::string name) {
    if(name.compare(".")==0)
        return this->mySelf.lock();
    if(name.compare("..")==0)
        return this->parent.lock();

    std::shared_ptr<Base2> res= std::shared_ptr<Base2>(nullptr);
    std::for_each(this->files.begin(), this->files.end(), [name, &res](std::shared_ptr<Base2> entry){
        if(entry->getName().compare(name)==0)
            res = entry;
    });
    return res;
}


std::shared_ptr<Directory2> Directory2::addDirectory(std::string name) {
    std::shared_ptr<Directory2> newDir( makeDirectory(name, this->mySelf));
    this->files.insert(this->files.end(), newDir);
    return newDir;
}

std::shared_ptr<File2> Directory2::addFile(std::string name, uintmax_t size) {
    std::shared_ptr<File2> newFile( new File2(name, size));
    this->files.insert(this->files.end(), newFile);
    return newFile;
}

std::shared_ptr<Directory2> Directory2::makeDirectory(std::string name, std::weak_ptr<Directory2> parent) {

    std::shared_ptr<Directory2> dir(new Directory2(name));
    dir->mySelf = std::weak_ptr<Directory2>(dir);
    dir->parent = parent;

    return dir;
}

std::shared_ptr<Directory2> Directory2::getDir(std::string name) {
    std::shared_ptr<Base2> toFind = this->get(name);
    return (toFind == nullptr || toFind->mType()!=0 ) ? nullptr : std::dynamic_pointer_cast<Directory2>(toFind);
}

std::shared_ptr<File2> Directory2::getFile(std::string name) {
    std::shared_ptr<Base2> toFind = this->get(name);
    return (toFind == nullptr || toFind->mType()!=1 ) ? nullptr: std::dynamic_pointer_cast<File2>(toFind);
}
