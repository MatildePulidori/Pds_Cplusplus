//
// Created by ff on 4/28/20.
//

#pragma once

#include "Message.h"
#include <optional>

class MessageStore {
    Message *messages;
    int dim;
    int n;

    void reallocate(int size);
    int find_pos(long id);

public:
    MessageStore(int n);
    ~MessageStore();

    // nota: rispetto al testo abbiamo modificato l'interfaccia, perché  usare un reference avrebbe
    // comportato tenere anche un riferimento esterno a Message (altrimenti cosa sarebbe successo?)
    // Un passaggio per valore in questo caso ha più senso, se Messagge è costruito al volo dal chiamante
    // e poi non più usato è dove l'operatore di move fa la differenza
    void add(const Message m);

    std::optional<Message> get(long id);
    bool remove(long id);
    std::tuple<int, int> stats();

    void compact();

    int getDim();
};


