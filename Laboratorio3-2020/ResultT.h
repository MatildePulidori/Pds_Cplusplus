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
    explicit ResultT(std::string key, int value );
    std::string getKey() const;
    int getValue() const;

    std::vector<char> serialize();
    void deserialize(std::vector<char> buff);
};


#endif //LABORATORIO3_2020_RESULTT_H
