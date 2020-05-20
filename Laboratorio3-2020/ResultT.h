//
// Created by Matilde Pulidori on 18/05/2020.
//

#ifndef LABORATORIO3_2020_RESULTT_H
#define LABORATORIO3_2020_RESULTT_H


#include <string>


class ResultT {
private:
    std::string key;
    int value=0;

public:
    ResultT();
    ResultT(std::string key, int value );

    const std::string &getKey() const;

    int getValue() const;



};


#endif //LABORATORIO3_2020_RESULTT_H
