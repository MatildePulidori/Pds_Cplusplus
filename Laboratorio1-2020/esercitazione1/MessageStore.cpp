//
// Created by ff on 4/28/20.
//

#include "MessageStore.h"

MessageStore::MessageStore(int n):n(n),dim(n){
    this->messages = new Message[n];
}

MessageStore::~MessageStore() {
    delete[] messages;
}

void MessageStore::reallocate(int size){
    Message *new_messages = new Message[size];
    int src = 0, dst = 0;
    while(src<dim){
        if(messages[src].getId()>=0){
            new_messages[dst++] = messages[src];
        } ;
        src++;
    }
    delete [] messages;
    dim = size;
    messages = new_messages;
}


int MessageStore::find_pos(long id) {
    for(int i = 0; i < dim; ++i) {
        if(messages[i].getId() == id)
            return i;
    }
    return -1;
}

void MessageStore::add(Message m){
    int pos = find_pos(-1);

    if(pos<0){
        reallocate(dim+n);
        pos = find_pos(-1);
    }
    messages[pos] = m;
}

std::optional<Message> MessageStore::get(long id) {
    int pos = find_pos(id);
    if(pos > 0)
        return messages[pos];
    else
        return std::nullopt;
}

bool MessageStore::remove(long id) {
    int pos = find_pos(id);
    if(pos > 0) {
        messages[pos] = Message();
        return true;
    }  else {
        return false;
    }
}

void MessageStore::compact() {
    int count = 0;
    for(int i=0; i<dim; i++){
        count += messages[i].getId()>=0?1:0;
    }
    int new_dim = count%n==0? count : (1 + count/n) * n;
    reallocate(new_dim);
}

int MessageStore::getDim() {
    return dim;
}

