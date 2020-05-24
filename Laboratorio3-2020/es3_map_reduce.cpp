#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <map>
#include <regex>

class SimpleMapperInput{
    std::string line;
public:
    SimpleMapperInput(std::string line):line(std::move(line)){}
    std::string getLine() {return line;}
};

template<typename T>
class SimpleResult{
    std::string key;
    T value;
public:
    SimpleResult() = default;
    SimpleResult(std::string key) :key(std::move(key)){}
    SimpleResult(std::string key, T value):
            key(std::move(key)),value(std::move(value)){}
    std::string getKey(){return key;}
    T getValue(){return value;}
};

template<typename V, typename A>
class SimpleReducerInput {
    std::string key;
    V value;
    A accumulator;
public:
    SimpleReducerInput(std::string key, V value, A accumulator):
            key(std::move(key)),value(std::move(value)), accumulator(std::move(accumulator)){}
    std::string getKey(){return key;}
    V getValue(){return value;}
    A getAccumulator(){ return  accumulator;}
};

template<typename MapperInputT, typename ResultT>
std::vector<ResultT>  mymap_ip(MapperInputT input){
    std::smatch ip_match;
    std::string line = input.getLine();
    std::regex_search(line, ip_match, std::regex("^[^ ]+"));
    return std::vector<ResultT> {ResultT(ip_match[0], 1)};
}

template<typename ReducerInput, typename ResultT>
ResultT myreduce_ip(ReducerInput input){
    return ResultT(input.getKey(), input.getValue() + input.getAccumulator());
}

template<typename MapperInputT, typename ResultT, typename ReducerInputT, typename M, typename R>
std::map<std::string, ResultT>  mapreduce(const std::string& inputf, M &mapfun, R &reducefun){
    std::string line;
    std::map<std::string, ResultT> results;

    std::ifstream ifs(inputf);

    if(!ifs.is_open()){
        std::cout<<"unable to open file"<<std::endl;
    }

    while(getline(ifs, line)){
        std::vector<ResultT> m_results = mapfun(MapperInputT(line));
        for(auto r: m_results){
            auto it = results.find(r.getKey());
            ResultT acc = it == results.end() ? ResultT(r.getKey()) : it->second;
            ResultT new_acc = reducefun(ReducerInputT(r.getKey(), r.getValue(), acc.getValue()));
            results[new_acc.getKey()] = new_acc;
        }
    }

    return results;
}


int main() {

    using ResultT = SimpleResult<int>;
    using ReducerInputT = SimpleReducerInput<int, int>;

    auto results = mapreduce<SimpleMapperInput, ResultT , ReducerInputT >(
            "../input.log",
            mymap_ip<SimpleMapperInput, ResultT>,
            myreduce_ip<ReducerInputT, ResultT >);

    for(auto &x: results){
        std::cout<<x.first<<": "<<x.second.getValue()<<std::endl;
    }

}