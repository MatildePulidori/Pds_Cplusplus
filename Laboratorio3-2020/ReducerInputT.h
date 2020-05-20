//
// Created by Matilde Pulidori on 18/05/2020.
//

#ifndef LABORATORIO3_2020_REDUCERINPUTT_H
#define LABORATORIO3_2020_REDUCERINPUTT_H


#include <string>

class ReducerInputT {
private:
    std::string key;
    int value;
    int accum;

public:
    ReducerInputT(const std::string key, int value, int accum);

    const std::string getKey() const;

    int getValue() const;

    int getAccum() const;

    std::vector<char> serialize() const;

    void deserialize(std::vector<char*> vector);

};


#endif //LABORATORIO3_2020_REDUCERINPUTT_H
