//
// Created by Matilde Pulidori on 30/03/2020.
//

#include "DurationLogger.h"
#include <ctime>
#include <iostream>
#include <thread>

DurationLogger::DurationLogger(const std::string name): name(name), tmp(time(NULL)){
    std::cout << ">>>>>>>>>>>>>> starting [ "<<name<<" ]"<<std::endl;
    //std::this_thread::sleep_for (std::chrono::seconds(1));
}

DurationLogger::~DurationLogger() {
    time_t end;
    time(&end);
    time_t duration = end - tmp;
    std::cout << "<<<<<<<<<<<<<<<< ending[ "<<name<<" ]: "<<duration<<" seconds."<< std::endl;
}