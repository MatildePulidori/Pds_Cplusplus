#include <iostream>
#include "Directory.h"
#include "D.h"
#include "Directory2.h"

void test0(){
    D root(std::shared_ptr<D>(nullptr));
    std::shared_ptr<D> child = root.addChild();
}

void test1(){
    std::shared_ptr<Directory> root = Directory::getRoot();
    auto alfa = root->addDirectory("alfa");
    auto beta = alfa->addDirectory("beta");
    auto delta = alfa ->addDirectory("delta");
    auto gamma = root->addDirectory("gamma");

    beta->addFile("file1", 20);
    beta->addFile("file2", 50);
    gamma->addDirectory("epsilon");
    gamma->addFile("file3", 12);


    std::cout<<"ls di "<<root.get()->getName()<<": "<<std::endl;
    root->ls(0);


    std::cout<<std::endl;
    std::cout<<"Get '.' di gamma: "<<gamma->get(".")->getName()<<std::endl;
    std::cout<<"Get '..' di beta: "<<beta->get("..")->getName()<<std::endl;
    std::cout<<"Get 'gamma' di beta: "<<root->get("gamma")->getName()<<std::endl;
    std::cout<<"Get 'file1' di beta: "<<beta->getFile("file1")->getName()<<std::endl;

    root->remove("gamma");
    std::cout<<"ls di "<<root.get()->getName()<<": "<<std::endl;
    root->ls(0);
}


void test2() {
    std::shared_ptr<Directory2> root = Directory2::getRoot();
    std::shared_ptr<Directory2> mati = root->addDirectory("matildepulidori");
    std::shared_ptr<Directory2> downloads = mati->addDirectory("downloads");
    downloads->addFile("exams.pdf", 20);
    std::shared_ptr<Directory2> desktop = mati->addDirectory("deskotp");
    desktop->addDirectory("school");
    desktop->addDirectory("photos");

    std::shared_ptr<Directory2> ire = root->addDirectory("irenepulidori");
    root->ls(0);

    std::string name = "exams.pdffff";
    std::shared_ptr<File2> file = downloads->getFile(name);
    std::cout <<"File trovato: ";
    if (file == nullptr) std::cout<< "non esiste in questa directory "<< name;
    else std::cout<<file->getName();
    std::cout<<std::endl;


    std::string dirName = "downloadsss";
    std::shared_ptr<Directory2> dirToFind = mati->getDir(dirName);
    std::cout <<"Directory trovata: ";
    if (dirToFind == nullptr) std::cout<< "non esiste questa directory "<< dirName;
    else std::cout<<dirToFind->getName();
    std::cout<<std::endl;
}


int main() {

    test2();
    return 0;
}
