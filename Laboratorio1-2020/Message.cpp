//
// Created by Matilde Pulidori on 30/03/2020.
//

#include "Message.h"
#include <utility>
#include <algorithm>


static long id_count = 0;

/**
 * Costruttore di default
 */
Message::Message(): id(-1), size(0){
    data = std::move(mkMessage(this->size)) ;

}

/**
 * Costruttore
 * @param id
 * @param data
 * @param size
 */
Message::Message(int size): id(id_count++), size(size){
        data = std::move(this->mkMessage(size));
        std::cout<<"costruttore param Message "<<&data <<std::endl;
}


/**
 * Distruttore
 */
Message::~Message() {
    std::cout<<"distruttore Message: "<< &data<<std::endl;
    delete[] data;
    data=NULL;

}


/**
 * Costruttore di copia
 * @param source
 */
Message::Message(const Message& source): id(source.id), size(source.size){
    this->data = source.data;
    memcpy(this->data, source.data, size);
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
        this->data = new char[this->size];
        memcpy(this->data, source.data, this->size);
    }
    return *this;
}

/**
 * Costruttore di movimento
 * @param source
 * @return
 */
Message::Message(Message &&source): id(-1), size(0), data(NULL) {
    swap(*this, source);
}


/**
 * Operatore di movimento
 * @param source
 * @return
 */
Message& Message::operator=(Message &&source) {
    swap(*this, source);
    return *this;
}


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

long Message::getId() const{
    return this->id;
}


char* Message::getData() const {
    return this->data;
}

int Message::getSize() const{
    return this->size;
}




