//
// Created by Matilde Pulidori on 13/06/2020.
//

#include "Socket.h"

Socket::Socket() {
    if( (fd = socket(AF_INET, SOCK_STREAM, 0)) == -1){
        throw std::runtime_error(strerror(errno));
    }
}

Socket::Socket(int sock_fd): fd(sock_fd){}

Socket::~Socket() {
    close(fd);
}