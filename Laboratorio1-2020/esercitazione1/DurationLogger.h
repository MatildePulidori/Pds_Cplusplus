//
// Created by ff on 4/28/20.
//

#pragma once

#include <string>
#include <iostream>

class DurationLogger {

    clock_t t0;
    std::string name;
public:
    DurationLogger(const std::string &name):name(name){
        t0 = clock();
    }

    ~DurationLogger(){
        std::cout<<"["<<name<<"][duration:"<<clock()-t0<<"]"<<std::endl;
    }
};


