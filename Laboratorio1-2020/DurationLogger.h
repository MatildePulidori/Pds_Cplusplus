//
// Created by Matilde Pulidori on 30/03/2020.
//

#ifndef LABORATORIO1_2020_DURATIONLOGGER_H
#define LABORATORIO1_2020_DURATIONLOGGER_H


#include <string>

class DurationLogger {

    std::string name;
    time_t tmp;

public:
    DurationLogger(const std::string name);
    ~DurationLogger();

};


#endif //LABORATORIO1_2020_DURATIONLOGGER_H
