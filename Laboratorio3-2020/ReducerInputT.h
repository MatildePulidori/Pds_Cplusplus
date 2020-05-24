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
    ReducerInputT(std::string key, int value, int accum);
    ~ReducerInputT();

    std::string getKey() const ;

    int getValue() const ;

    int getAccum() const;

    std::vector<char> serialize();
    void deserialize(std::vector<char> buff);


};

#endif //LABORATORIO3_2020_REDUCERINPUTT_H
