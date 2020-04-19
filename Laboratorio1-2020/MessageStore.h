//
// Created by Matilde Pulidori on 30/03/2020.
//

#ifndef LABORATORIO1_2020_MESSAGESTORE_H
#define LABORATORIO1_2020_MESSAGESTORE_H


#include <optional>
#include "Message.h"

class MessageStore {

    Message *messages;
    int dim = 0;
    int n;

public:
    MessageStore(int n);
    ~MessageStore();

    void printMessages();

    void add(Message &m);
    std::optional<Message> get(long id);
    bool remove(long id);
    std::tuple<int, int> stats();
    void compact();


};


#endif //LABORATORIO1_2020_MESSAGESTORE_H
