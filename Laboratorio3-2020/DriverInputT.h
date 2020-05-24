//
// Created by Matilde Pulidori on 24/05/2020.
//

#ifndef LABORATORIO3_2020_DRIVER_H
#define LABORATORIO3_2020_DRIVER_H

#include <map>
#include <fstream>
#include <iostream>
#import "MapperInputT.h"
#import "ReducerInputT.h"
#import "ResultT.h"

class DriverInputT {
private:
    std::string filename;
    template<typename MapperInputT, typename ResultT> using mapfun = std::vector<ResultT> (*)(const MapperInputT &input);
    template<typename ReducerInputT, typename ResultT> using reducefun = ResultT (*)(const ReducerInputT &input);

public:
    explicit DriverInputT(std::string input);
    ~DriverInputT();
    std::string getFilename();

    std::map<std::string, ResultT> mapreduce(mapfun<MapperInputT,ResultT> mapfunct, reducefun<ReducerInputT, ResultT> reducefunct){

        std::string line;
        std::map<std::string, ResultT> accumulators;
        std::ifstream ifs(this->getFilename());

        if (!ifs.is_open()) {
            std::cout << "unable to open file" << std::endl;
        }

        while (getline(ifs, line)) {
            std::vector<ResultT> results = mapfunct(MapperInputT(line));

            for (ResultT t : results) {
                ReducerInputT r(t.getKey(), t.getValue(), accumulators[t.getKey()].getValue());
                ResultT newResult = reducefunct(
                        ReducerInputT(t.getKey(), t.getValue(), accumulators[t.getKey()].getValue()));
                accumulators[newResult.getKey()] = newResult;
            }
        }
        return accumulators;

    };
};

#endif //LABORATORIO3_2020_DRIVER_H
