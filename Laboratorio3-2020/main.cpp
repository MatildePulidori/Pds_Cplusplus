#include <iostream>
#include <map>
#include <boost/property_tree/xml_parser.hpp>
#include "MapperInputT.h"
#include "ReducerInputT.h"
#include "DriverInputT.h"


template <class MapperInputT, class ResultT>
auto mapIp(const MapperInputT& input){
    std::vector<ResultT> results;
    results.push_back( ResultT(input.getIp(), 1) );
    return results;
};

template <class MapperInputT, class ResultT>
auto mapTime (MapperInputT &input) {
    std::vector<ResultT> results;
    results.push_back(ResultT(input.getTime(), 1));
    return results;
};

template <class MapperInputT, class ResultT>
auto mapMethod (MapperInputT& input) {
    std::vector<ResultT> results;
    results.push_back(ResultT(input.getMethod(), 1));
    return results;
};

template <class MapperInputT, class ResultT>
auto  mapCode (MapperInputT& input) {
    std::vector<ResultT> results;
    results.push_back( ResultT(input.getCode(), 1) );
    return results;
};

template<class ReducerInputT, class ResultT>
auto reduce (const ReducerInputT &input){
    int new_value = input.getValue() + input.getAccum();
    return ResultT(input.getKey(), new_value);
};





int main(int argc, char * argv[]) {

    /*std::string test = "209.17.96.34 - - [01/Jan/2020:00:19:59 +0100] \"GET / HTTP/1.1\" 200 \n"
                       "120.29.52.229 - - [01/Jan/2020:00:29:55 +0100] \"GET / HTTP/1.1\" 200 20744\n"
                       "120.29.52.229 - - [01/Jan/2020:00:29:55 +0100] \"GET / HTTP/1.1\" 200 20744\n"
                       "188.27.146.10 - - [01/Jan/2020:00:37:02 +0100] \"GET / HTTP/1.1\" 200 20744\n"
                       "194.55.187.131 - - [01/Jan/2020:00:44:56 +0100] \"GET /manager/html HTTP/1.1\" 404 1999\n"
                       "191.5.161.140 - - [01/Jan/2020:01:12:43 +0100] \"GET / HTTP/1.1\" 200 20744\n"
                       "122.228.19.80 - - [01/Jan/2020:02:33:02 +0100] \"GET /weborg/ HTTP/1.1\" 404 1999\n"
                       "201.159.251.208 - - [01/Jan/2020:04:04:56 +0100] \"GET / HTTP/1.1\" 200 20744\n"
                       "103.39.9.160 - - [01/Jan/2020:05:37:19 +0100] \"GET / HTTP/1.1\" 200 20744\n"
                       "187.94.115.94 - - [01/Jan/2020:06:05:49 +0100] \"GET / HTTP/1.1\" 200 20744\n"
                       "61.219.11.153 - - [01/Jan/2020:06:12:19 +0100] \"GET / HTTP/1.1\" 400 -\n"
                       "37.77.69.165 - - [01/Jan/2020:07:10:23 +0100] \"GET / HTTP/1.1\" 200 20744";


    std::istringstream stream(test);
    std::vector<std::string> input;
    std::string line = "";
    while( std::getline(stream, line) ) {
        input.push_back(line);
    }
    std::map<std::string, ResultT>  res = mapreduce(input, *mapIp<MapperInputT, ResultT>, *reduce<ReducerInputT, ResultT>);
    */

    std::string path("/Users/matildepulidori/CLionProjects/Laboratori2020/Laboratorio3-2020/localhost_access_log.2020.txt");
    DriverInputT driver(path);

    std::map<std::string, ResultT>  res = driver.mapreduce( mapIp<MapperInputT,ResultT>, reduce<ReducerInputT, ResultT>);

    std::for_each(res.begin(), res.end(), [](std::pair<std::string, ResultT> pair ) ->  void {
        std::cout<< pair.second.getKey()<< " - " << pair.second.getValue()<< std::endl;
    });

    return 0;
}


