#include <iostream>
#include "Directory.h"

int main() {

    std::shared_ptr<Directory> root = Directory::getRoot();
    auto alfa = root->addDirectory("alfa");
    auto beta = alfa->addDirectory("beta");
    auto delta = alfa ->addDirectory("delta");
    auto gamma = root->addDirectory("gamma");

    beta->addFile("file1", 20);
    beta->addFile("file2", 20);


    std::cout<<"ls di "<<root.get()->getName()<<": "<<std::endl;
    root->ls(0);


    std::cout<<std::endl;
    std::cout<<"Get '.' di gamma: "<<gamma->get(".")->getName()<<std::endl;
    std::cout<<"Get '..' di beta: "<<beta->get("..")->getName()<<std::endl;
    std::cout<<"Get 'gamma' di beta: "<<root->get("gamma")->getName()<<std::endl;
    std::cout<<"Get 'file1' di beta: "<<beta->getFile("file1")->getName()<<std::endl;

    return 0;
}