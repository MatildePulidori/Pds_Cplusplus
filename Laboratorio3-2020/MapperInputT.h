//
// Created by Matilde Pulidori on 18/05/2020.
//

#ifndef LABORATORIO3_2020_MAPPER_H
#define LABORATORIO3_2020_MAPPER_H


#include <vector>
#include "ResultT.h"


class MapperInputT{ // public Serializer<MapperInputT> {
private:
    std::string line;

    std::string ip;
    std::string time;
    std::string method;
    std::string code;

    void parser(std::string line);


public:
    MapperInputT(std::string line);
    ~MapperInputT();

    std::string getLine() const ;

    std::string getIp() const ;

    std::string getTime() const;

    std::string getMethod() const ;

    std::string getCode() const;

    std::vector<char> serialize();

    void deserialize(std::vector<char> buff);

};


#endif //LABORATORIO3_2020_MAPPER_H
