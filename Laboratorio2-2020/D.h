//
// Created by Matilde Pulidori on 20/06/2020.
//

#ifndef LABORATORIO2_2020_D_H
#define LABORATORIO2_2020_D_H


#include <memory>
#include <iostream>

class D {
    std::weak_ptr<D> parent;
public:
    D(std::weak_ptr<D> parent):parent(parent){
        std::cout<<"D @"<<this<<std::endl;
        std::cout<<"D @"<<&parent<<std::endl;
    }
    std::shared_ptr<D> addChild(){
        std::shared_ptr<D> child = std::make_shared<D>(std::shared_ptr<D>(this));
        return child;
    }
    ~D(){
        std::cout<<"~D @"<<this<<std::endl;
    }

};



#endif //LABORATORIO2_2020_D_H
