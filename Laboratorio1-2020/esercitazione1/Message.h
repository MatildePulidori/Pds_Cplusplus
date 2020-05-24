//
// Created by ff on 4/28/20.
//

#pragma once

#include <string>
#include <iostream>

class Message {
    static int id_counter;
    long id;
    char *data;
    int size;

    static char* mkMessage(int n);

public:
    Message();
    Message(int n);
    Message(const Message &other);
    Message(Message &&other);

    Message& operator=(const Message &other);
    Message& operator=(Message &&other);

    long getId() const;
    int getSize() const;
    char* getData() const;

    ~Message();

};

std::ostream& operator<<(std::ostream &out, const Message &m);
