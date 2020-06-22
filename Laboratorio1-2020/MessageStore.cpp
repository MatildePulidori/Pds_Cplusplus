//
// Created by Matilde Pulidori on 30/03/2020.
//

#include "MessageStore.h"
#include "Message.h"
#include "Utils.h"
#include <iostream>

MessageStore::MessageStore(int n): dim(+n), n(n) {
    messages = new Message[n];
}

MessageStore::~MessageStore() {
    delete[] messages;
}


void MessageStore::reallocate(int size) {
    Message *new_messages = new Message[n];
    int src = 0, dst = 0;
    while(src < this->dim){
        if(messages[src].getId() >= 0 ){
            new_messages[dst++] = messages[src];
        }
        src++;
    }
    delete[] messages;
    this->dim = size;
    this->messages = new_messages;
}


int MessageStore::find_pos(long id) {
    for(int i= 0; i<dim; i++){
        if(messages[i].getId() == 0)
            return i;
    }
}

void MessageStore::add(Message &m) {
    int pos = find_pos(-1);

    if(pos<0){
        reallocate(this->dim+this->n);
    }
    this->messages[pos]=m;
}

std::optional<Message> MessageStore::get(long id) {
    int pos = find_pos(id);
    if (pos>0)
        return messages[pos];
    else
        return std::nullopt;
}

bool MessageStore::remove(long id) {
    int pos = find_pos(id);
    if(pos>0){
        messages[pos]= Message();
        return true;
    } else return false;

}

std::tuple<int, int> MessageStore::stats() {
    int vuoti = 0, validi = 0;
    for (int i=0; i<dim; i++){
        if (this->get(i)){
            validi++;
        } else if ( !this->get(i)){
            vuoti++;
        }
    }
    return std::make_tuple(validi, vuoti);
}

void MessageStore::compact() {
    std::tuple<int, int> stats(this->stats());

    int count = 0;
    for (int i=0; i<this->dim; i++){
        count += messages[i].getId()>=0? 1:0;
    }
    int new_dim = count%n == 0 ? count:((1+count/n)*n);
    reallocate(new_dim);
}


void MessageStore::printMessages() {
    for(int i=0; i<dim; i++){
        std::cout<< this->messages[i];
    }
}

int MessageStore::getDim() const {
    return this->dim;
}