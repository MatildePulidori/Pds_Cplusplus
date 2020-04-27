//
// Created by Matilde Pulidori on 27/04/2020.
//

#include "Directory.h"


Directory::Directory(std::string nome): Base(nome) {
}

Directory::~Directory(){}

int Directory::getType() const {
    return this->type;
}

void Directory::ls(int indent) const{

    if (indent == 0){
        std::cout<<"[+] ";
        std::cout<<this->name;
        std::cout<<std::endl;
        indent +=1;
    }

    std::for_each(this->files.begin(), this->files.end(), [indent](std::shared_ptr<Base> f){

        for(int i=0;i<indent;i++){
            std::cout<<"\t";
        }

        // caso directory
        if (f->getType() == 0){
            std::cout<<"[+] ";
            std::cout<<f->getName()<<"/ ";
        }

        int newIndent = indent + 4;
        f->ls(newIndent);

    });

}


std::shared_ptr<Directory> Directory::root;

std::shared_ptr<Directory> Directory::getRoot() {
    if (root.get() == nullptr){
        root = std::shared_ptr<Directory>(new Directory("/"));
        root->mySelf = root;
        root->root = root;
    }
    return root;
}

std::shared_ptr<Base> Directory::get(std::string nome) {
    if (nome.compare("..") == 0){
        std::weak_ptr<Directory> parent = this->parent;
        auto p = parent.lock();
        return p;
    }
    if (nome.compare(".")==0){
        std::weak_ptr<Directory> mySelf = this->mySelf;
        auto self = mySelf.lock();
        return self ;
    }

    std::shared_ptr<Base> get = std::shared_ptr<Base>(nullptr);
    std::for_each(this->files.begin(), this->files.end(), [nome, &get](std::shared_ptr<Base> f){
        if (f->getName().compare(nome) == 0) {
            get = f;
        }
    });
    return get;

}


std::shared_ptr<Directory> Directory::addDirectory(std::string nome) {
    std::for_each(this->files.begin(), this->files.end(), [nome](std::shared_ptr<Base> f){
        if (f->getName().compare(nome)==0 &&   f->getType()==0){
            return nullptr;
        }
    });


    std::shared_ptr<Directory> newDir(this->makeDir(nome, this->mySelf));
    this->files.insert(this->files.end(),newDir);
    return newDir;

}


std::shared_ptr<Directory> Directory::makeDir(std::string nome, std::weak_ptr<Directory> parent) {

    Directory *dir = new Directory(nome);
    std::shared_ptr<Directory> newDir (dir);
    dir->mySelf = std::weak_ptr<Directory>(newDir);
    dir->parent = parent;

    return newDir;

}