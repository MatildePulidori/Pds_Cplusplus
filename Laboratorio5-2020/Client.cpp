//
// Created by Matilde Pulidori on 13/06/2020.
//

#include <netdb.h>
#include "Client.h"


Client::Client(int port, std::string server_address): port(port) {
    this->sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (this->sock_fd <0){
        throw std::runtime_error(strerror(errno));
    }
    this->serv_adrr.sin_family = AF_INET;
    this->serv_adrr.sin_port = htons(port);
    uint32_t server = ntohl();
    this->serv_adrr.sin_addr =;
}