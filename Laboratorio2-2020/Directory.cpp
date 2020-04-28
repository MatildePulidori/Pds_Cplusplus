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
            std::cout<<f->getName()<<"/ "<<std::endl;
        }

        int newIndent = indent + 2;
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

std::shared_ptr<Base> Directory::get(std::string name) {
    if (name.compare("..") == 0){
        std::weak_ptr<Directory> parent = this->parent;
        auto p = parent.lock();
        return p;
    }
    if (name.compare(".") == 0){
        std::weak_ptr<Directory> mySelf = this->mySelf;
        auto self = mySelf.lock();
        return self ;
    }

    std::shared_ptr<Base> get = std::shared_ptr<Base>(nullptr);
    std::for_each(this->files.begin(), this->files.end(), [name, &get](std::shared_ptr<Base> f){
        if (f->getName().compare(name) == 0) {
            get = f;
        }
    });
    return get;

}


std::shared_ptr<Directory> Directory::getDir(std::string name) {

    if (name.compare("..") == 0){
        std::weak_ptr<Directory> parent = this->parent;
        auto p = parent.lock();
        return p;
    }
    if (name.compare(".") == 0){
        std::weak_ptr<Directory> mySelf = this->mySelf;
        auto self = mySelf.lock();
        return self ;
    }

    std::shared_ptr<Base> dir = std::shared_ptr<Base>(nullptr);
    std::for_each(this->files.begin(), this->files.end(), [name, &dir ](std::shared_ptr<Base> d){
        if (d->getName().compare(name)==0 &&   d->getType()==0){
            dir = d;
        }
    });
    return std::dynamic_pointer_cast<Directory>(dir);
}


std::shared_ptr<File> Directory::getFile(std::string name) {
    std::shared_ptr<Base> file = std::shared_ptr<Base>(nullptr);
    std::for_each(this->files.begin(), this->files.end(), [name, &file ](std::shared_ptr<Base> f){
        if (f->getName().compare(name)==0 &&   f->getType()==1){
            file = f;
        }
    });
    return std::dynamic_pointer_cast<File>(file);

}

std::shared_ptr<Directory> Directory::addDirectory(std::string nome) {
     std::shared_ptr<Directory> dir  = std::shared_ptr<Directory>(nullptr);
     dir = this->getDir(nome);

     if (dir == nullptr) {
        std::shared_ptr<Directory> newDir(this->makeDir(nome, this->mySelf));
        this->files.insert(this->files.end(), newDir);
        return newDir;
    }
     return dir;

}


std::shared_ptr<Directory> Directory::makeDir(std::string nome, std::weak_ptr<Directory> parent) {

    Directory *dir = new Directory(nome);
    std::shared_ptr<Directory> newDir (dir);
    dir->mySelf = std::weak_ptr<Directory>(newDir);
    dir->parent = parent;

    return newDir;

}

std::shared_ptr<File> Directory::addFile(std::string name, uintmax_t size) {

    std::shared_ptr<File> file = std::shared_ptr<File>(nullptr);
    file = this->getFile(name);

    if(file == nullptr) {
        std::shared_ptr<File> newFile(new File(name, size));
        newFile->mySelf = std::weak_ptr<File>(newFile);
        this->files.insert(this->files.end(), newFile);
        return newFile;
    }

    return file;


}


bool Directory::remove(std::string name) {
    if (name.compare("..") == 0 || name.compare(".") == 0){
        return false;
    }

    for(auto it = std::begin(files); it!= std::end(files); it++){
        if ((*it)->getName().compare(name)==0) {
            this->files.erase(it);
            return true;
        }
    }
    return false;

}
