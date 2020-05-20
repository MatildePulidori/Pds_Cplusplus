//
// Created by Matilde Pulidori on 19/05/2020.
//

#ifndef LABORATORIO3_2020_SERIALIZER_H
#define LABORATORIO3_2020_SERIALIZER_H

#include <vector>
#include <string>

template <typename T>
class Serializer {

    Serializer();
    friend T;

public:

    std::vector<char> serialize() const {
        return static_cast<const T& >(*this).serialize();
    }

    void deserialize(std::shared_ptr<char*> ptr){
        static_cast<const T&>(*this).deserialize();
    }

    // Il to_string lo implemento facendo uno static_cast
    std::string to_string() const{
        return static_cast<const T& >(*this).to_string();
    }



};


#endif //LABORATORIO3_2020_SERIALIZER_H
