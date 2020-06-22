//
// Created by Matilde Pulidori on 30/03/2020.
//

#ifndef LABORATORIO1_2020_MESSAGE_H
#define LABORATORIO1_2020_MESSAGE_H

#include <cstring>
#include <string>
#include <iostream>
#include <utility>



class Message {

private:
    long id;
    char *data;
    int size;

    static int id_count;
    static char* mkMessage(int n);



public:

    Message();
    Message(int size);
    ~Message();
    Message(const Message& source);
    Message(Message&& source);



    Message& operator=(const Message& source);
    Message& operator=(Message&& source);

    friend void swap(Message& a, Message& b){
        std::swap(a.id, b.id);
        std::swap(a.size, b.size);
        std::swap(a.data, b.data);

    }

    long getId() const;
    char* getData() const;
    int getSize() const;

};


#endif //LABORATORIO1_2020_MESSAGE_H
