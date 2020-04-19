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

void MessageStore::add(Message &m) {

    // 1) se l'id passato è minore della dimensione
    if (m.getId()<dim){

        // se esiste, sovrascrivo
        if ( get(m.getId()) || messages[m.getId()].getId() == -1 ){
            messages[m.getId()] = m;
        }
        // se non esiste, devo shiftare tutto
        else {

            // caso esempio: arriva 2, nel buffer abbiamo [1, 3]
            // si dovrà fare: [1, , 3] ed inserire il 2.
            if (messages[m.getId()].getId() > m.getId()){

                Message* newMessages = new Message[dim+1];
                int i;
                for (i = 0; i< dim ; i++) {

                    if (i<m.getId()){
                        newMessages[i] = std::move(this->messages[i]);
                    }
                    if(i==m.getId()){
                        newMessages[i] = m;
                    }
                    if ( i > m.getId()){
                        newMessages[i] = std::move(this->messages[i-1]);
                    }
                }
                this->dim += 1;
                this->messages = std::move(newMessages);

            }
        }
    }

    // 2) se l'id passato è out of bound, allora rialloco un altro vettore appendo in fondo
    else if  (m.getId()>=dim){

        Message* newMessages = new Message[dim+1];
        int i=0;
        for (i = 0; i< dim ; i++) {
            newMessages[i] = std::move(this->messages[i]);
        }
        newMessages[i] = m;
        this->dim += 1;
        this->messages = std::move(newMessages);
    }

}

std::optional<Message> MessageStore::get(long id) {
    for (int i=0; i<dim; i++){
        if (id == messages[i].getId())
            return messages[i];
    }
    return std::nullopt;
}

bool MessageStore::remove(long id) {
    auto o = get(id);
    if(o){
        o= Message();
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
    int vuoti = std::get<1>(stats);
    int validi = std::get<0>(stats);

    Message* newMessages = new Message[dim-vuoti];

    for(int i=0, j=0; i<(dim-vuoti), j<dim; j++){

        // aggiungo solo se non è vuoto
        if ( messages[j].getId() != -1 ){
            newMessages[i] = std::move(this->messages[j]);
            i++;
        }
    }
    this->dim = dim -vuoti;
    this->n = std::get<0>(this->stats());
    this->messages = std::move(newMessages);

}


void MessageStore::printMessages() {
    for(int i=0; i<dim; i++){
        std::cout<< this->messages[i];
    }
}