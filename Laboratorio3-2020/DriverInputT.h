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

    template<typename T> using write_to_pipe = std::vector<T> (*)(int fd, const T& obj);
    template<typename T> using read_from_pipe = T (*)(int fd);

public:
    explicit DriverInputT(std::string input);
    ~DriverInputT();
    std::string getFilename();
    std::map<std::string, ResultT> mapreduce(mapfun<MapperInputT,ResultT> mapfunct, reducefun<ReducerInputT, ResultT> reducefunct);
    std::map<std::string, ResultT> mapreducePipe(mapfun<MapperInputT,ResultT> mapfunct, reducefun<ReducerInputT, ResultT> reducefunct);
};

#endif //LABORATORIO3_2020_DRIVER_H
