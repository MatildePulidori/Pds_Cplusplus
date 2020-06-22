//
// Created by Matilde Pulidori on 30/03/2020.
//

#include "Message.h"
#include <utility>
#include <algorithm>


int Message::id_count = 0;

char* Message::mkMessage(int n) {
    std::string vowels = "aeiou";
    std::string consonants = "bcdfghlmnpqrstvz";

    char* m = new char[n+1];
    for (int i =0; i<n; i++){
        m[i] = i%2 ? vowels[rand()%vowels.size()] :
               consonants[rand()%consonants.size()];
    }
    m[n] = 0;

    return m;
}

/**
 * Costruttore di default
 */
Message::Message(): id(-1), data(nullptr), size(0){}

/**
 * Costruttore
 * @param id
 * @param data
 * @param size
 */
Message::Message(int size): id(id_count++), size(size){
    data = std::move(this->mkMessage(size));
    std::cout<<"costruttore Message "<< this->id<<": "<<&data <<std::endl;
}


/**
 * Distruttore
 */
Message::~Message() {
    std::cout<<"distruttore Message "<< this->id<<": "<< &data<<std::endl;
    if(data != nullptr)
        delete[] data;

}


/**
 * Costruttore di copia
 * @param source
 */
Message::Message(const Message& source){
    this->id = source.id;
    this->size = source.size;
    this->data = source.data;
    std::copy( source.data, source.data+source.size, this->data);
}

/**
 * Costruttore di movimento
 * @param source
 * @return
 */
Message::Message(Message &&source){
    this->id = source.id;
    this->size = source.size;
    this->data = source.data;
    source.data = nullptr;
}

/**
 * Operatore di assegnazione
 * @param source
 * @return
 */
Message& Message::operator=(const Message &source) {
    if (this != &source) {
        delete[] this->data;
        this->data = nullptr;
        this->id = source.id;
        this->size = source.size;
        this->data = new char[this->size+1];
        std::copy(source.data, source.data+source.size, this->data);
    }
    return *this;
}


/**
 * Operatore di movimento
 * @param source
 * @return
 */
Message& Message::operator=(Message &&source) {
    if (this != &source) {
        delete[] this->data;
        this->data = nullptr;
        this->id = source.id;
        this->size = source.size;
        this->data = source.data;
        source.data = nullptr;
    }
    return *this;
}

long Message::getId() const{
    return this->id;
}


char* Message::getData() const {
    return this->data;
}

int Message::getSize() const{
    return this->size;
}




