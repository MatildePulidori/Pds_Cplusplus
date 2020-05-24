//
// Created by ff on 4/28/20.
//

#include "Message.h"
#include <string>
#include <cstring>

int Message::id_counter = 0;

char* Message::mkMessage(int n){
    std::string vowels = "aeiou";
    std::string consonants = "bcdfghlmnpqrstvz";
    char* m = new char[n+1];
    for(int i=0; i<n; i++){
        m[i]= i%2 ? vowels[rand()%vowels.size()] :
              consonants[rand()%consonants.size()];
    }
    m[n] = 0 ;
    return m;
}

Message::Message():
    id(-1),data(nullptr),size(0){}

Message::Message(int n):
    id(id_counter++),size(n){
    this->data = mkMessage(n);
}

Message::Message(const Message& other){
    this->id = other.id;
    this->size = other.size;
    this->data = new char[size+1];
    std::copy(other.data, other.data+other.size+1, this->data);
}

Message::Message(Message &&other){
    this->id = other.id;
    this->size = other.size;
    this->data = other.data;
    other.data = nullptr;
}

Message& Message::operator=(const Message &other){
    if(this != &other){
        delete[] this->data;
        this->data = nullptr;
        this->id = other.id;
        this->size = other.size;
        this->data = new char[size+1];
        std::copy(other.data, other.data+other.size+1, this->data);
    }
    return *this;
}

Message& Message::operator=(Message &&other) {
    if(this != &other){
        delete[] this->data;
        this->id = other.id;
        this->size = other.size;
        this->data = other.data;
        other.data = nullptr;
    }
    return *this;
}

long Message::getId() const {
    return id;
}

int Message::getSize() const {
    return size;
}

char* Message::getData() const {
    return data;
}

Message::~Message() {
    if(data!= nullptr)
        delete [] data;
}

std::ostream& operator<<(std::ostream &out, const Message &m){
    std::string s(m.getData());
    out<<"[id:"<<m.getId()<<"]"<<"[size:"<<m.getSize()<<"]" <<"[data:"<<s.substr(0, 20)<<"]";
    return out;
}
