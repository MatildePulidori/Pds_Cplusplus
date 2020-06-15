//
// Created by Matilde Pulidori on 13/06/2020.
//

#include <netinet/in.h>
#include "Server.h"
#include <unistd.h>
#include <sys/socket.h>

Server::Server(std::string address, uint16_t port): server_address(std::move(address)), server_port(port){

    this->sock_server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (this->sock_server_fd < 0){
        throw std::runtime_error(strerror(ENOTSOCK));
    }

    this->addr.sin_family = AF_INET;
    this->addr.sin_port = htons(port);
    this->addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if( bind(this->sock_server_fd, (struct sockaddr *) &this->addr, sizeof(this->addr)) < 0) {
        throw std::runtime_error(strerror(ENOTSOCK));
    }

    if (listen(this->sock_server_fd, 8) <0) {
        throw std::runtime_error(strerror(ENOTCONN));
    }
}


Server::~Server() {
    close(this->sock_server_fd);
}

Socket Server::accept(struct sockadd *addr, socklen_t len) {
    return Socket( ::accept(this->sock_server_fd, (struct sockaddr*) &addr, &len) );
}