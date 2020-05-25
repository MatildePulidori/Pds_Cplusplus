//
// Created by Matilde Pulidori on 18/05/2020.
//

#include <fstream>
#include <sstream>
#include <regex>
#include "MapperInputT.h"

MapperInputT::MapperInputT(std::string line): line(std::move(line)) {
    this->parser(this->line);
    std::vector<char> ser = this->serialize();
    this->deserialize(ser);
}

MapperInputT::~MapperInputT() = default;

void MapperInputT::parser(std::string line){

    std::stringstream stringstream(line);
    std::string word;
    std::getline(stringstream, word, ' '); // ip_
    std::smatch w;
    std::regex_search(word, w, std::regex("^(?:[0-9]{1,3}\\.){3}[0-9]{1,3}"));
    this->ip=w[0];

    /*std::getline(stringstream, w, ' '); // -_
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
    this->code = w;*/
}

std::string MapperInputT::getLine() const {
    return line;
}

std::string MapperInputT::getIp() const {
    return ip;
}

std::string MapperInputT::getTime() const {
    return time;
}

std::string MapperInputT::getMethod() const {
    return method;
}

std::string MapperInputT::getCode() const {
    return code;
}

std::vector<char> MapperInputT::serialize() {


    ushort sizeString = sizeof(std::string);
    ushort sizeTot = sizeString + sizeof(ushort);
    std::vector<char> buff(sizeTot);
    std::copy((char*)&sizeString, (char*)&sizeString + sizeof(ushort), buff.begin()); // { <lunghezza attributo ip>
    std::copy((char*)&ip, (char*)&ip + sizeString, buff.begin()+ sizeof(ushort));// <valore attributo ip>}

    return buff;
}

void MapperInputT::deserialize(std::vector<char> buff) {
    ushort sizeTot = buff.size();

    ushort position = 0;
    ushort toAdd = sizeof(ushort);
    ushort toAddNext = 0;


    while (position <= sizeTot) {

        if(toAdd == sizeof(ushort)) {
            std::copy(buff.begin() + position, buff.begin() + position + toAdd, (char *) &toAddNext);
        } else {
            std::copy(buff.begin() + position, buff.begin() + position + toAdd, (char *) &this->ip);
        }
        position +=toAdd;
        toAdd += toAddNext;
    }


}


