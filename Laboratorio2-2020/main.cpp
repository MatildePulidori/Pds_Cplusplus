#include <iostream>
#include "Directory.h"

int main() {

    std::shared_ptr<Directory> root = Directory::getRoot();
    auto d1 = root->addDirectory("alfa");

    std::cout<<"ls di "<<root.get()->getName()<<": "<<std::endl;
    root->ls(0);

    std::cout<<std::endl;
    std::cout<<"Get '.' di alfa: "<<d1->get(".")->getName()<<std::endl;
    std::cout<<"Get '..' di alfa: "<<d1->get("..")->getName()<<std::endl;

    return 0;
}