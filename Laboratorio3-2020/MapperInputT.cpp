//
// Created by Matilde Pulidori on 18/05/2020.
//

#include <fstream>
#include <sstream>
#include "MapperInputT.h"

MapperInputT::MapperInputT(std::string line): line(line) {
    this->parser(line);
}

void MapperInputT::parser(std::string line){

    std::stringstream stringstream(line);
    std::string w;

    std::getline(stringstream, w, ' '); // ip_
    this->ip = w;

    std::getline(stringstream, w, ' '); // -_
    std::getline(stringstream, w, ' '); // -_

    std::getline(stringstream, w, ' '); // [data:ora_
    std::stringstream dataora(w);
    std::string timestamp;
    std::getline(dataora, w, ':'); // [data:
    std::getline(dataora, timestamp, ' '); // ora
    this->time = timestamp;

    std::getline(stringstream, w, ' '); // fuso]_
    std::getline(stringstream, w, ' '); // "METHOD_
    size_t toRemove = w.find('"');
    w.erase(toRemove,1 );
    this->method = w;

    std::getline(stringstream, w, '"'); // HTTP/1.1"
    std::getline(stringstream, w, ' '); // _
    std::getline(stringstream, w, ' '); // <CODE>_
    this->code = w;
}

const std::string MapperInputT::getLine() const {
    return line;
}

const std::string MapperInputT::getIp() const {
    return ip;
}

const std::string MapperInputT::getTime() const {
    return time;
}

const std::string MapperInputT::getMethod() const {
    return method;
}

const std::string MapperInputT::getCode() const {
    return code;
}


/*std::vector<char> MapperInputT::serialize() const {
    std::vector<char> serialized;

    return serialized;
}

void MapperInputT::deserialize(std::vector<char *> vector) {

}*/