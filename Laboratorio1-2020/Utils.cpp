//
// Created by Matilde Pulidori on 30/03/2020.
//

#include "Utils.h"

std::ostream& operator<<(std::ostream &out, const Message &m) {
    // accedere alle parti contenute nell'oggetto Messagge
    out << "[ id: "<<m.getId()<<" ], [ size: "<< m.getSize()<< " ], [ data: "<< m.getData()<<" ]"<<std::endl;
    return out;

}