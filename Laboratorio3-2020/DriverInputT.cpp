//
// Created by Matilde Pulidori on 24/05/2020.
//

#include "DriverInputT.h"

DriverInputT::DriverInputT(std::string input): filename(input) {}

DriverInputT::~DriverInputT() {}

std::string DriverInputT::getFilename() {
    return this->filename;
}

std::map<std::string, ResultT> DriverInputT::mapreduce(DriverInputT::mapfun<MapperInputT, ResultT> mapfunct,
                                                       DriverInputT::reducefun<ReducerInputT, ResultT> reducefunct) {
    std::string line;
    std::map<std::string, ResultT> accumulators;
    std::ifstream ifs(this->getFilename());

    if (!ifs.is_open()) {
        std::cout << "unable to open file" << std::endl;
    }

    while (getline(ifs, line)) {
        std::vector<ResultT> results = mapfunct(MapperInputT(line));

        for (ResultT t : results) {
            ResultT newResult = reducefunct(
                    ReducerInputT(t.getKey(), t.getValue(), accumulators[t.getKey()].getValue()));
            accumulators[newResult.getKey()] = newResult;
        }
    }
    return accumulators;
}


std::map<std::string, ResultT> DriverInputT::mapreducePipe(DriverInputT::mapfun<MapperInputT, ResultT> mapfunct,
                                                       DriverInputT::reducefun<ReducerInputT, ResultT> reducefunct) {
    std::string line;
    std::map<std::string, ResultT> accumulators;
    std::ifstream ifs(this->getFilename());

    if (!ifs.is_open()) {
        std::cout << "unable to open file" << std::endl;
    }

    while (getline(ifs, line)) {
        write_pipe(mapper_pipe, MapperInputT(line));
        std::vector<ResultT> results = read_from_pipe(mapper_pipe);

        for (ResultT t : results) {
            write_pipe(reducer_pipe, ReducerInputT(t.getKey(), t.getValue(), accumulators[t.getKey()].getValue()) );
            ResultT newResult = read_from_pipe(reducer_pipe);
            accumulators[newResult.getKey()] = newResult;
        }
    }
    return accumulators;

}