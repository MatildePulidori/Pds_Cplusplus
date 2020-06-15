//
// Created by Matilde Pulidori on 13/06/2020.
//

#ifndef LABORATORIO5_2020_SERVER_H
#define LABORATORIO5_2020_SERVER_H


#include <list>
#include <queue>
#include <sys/socket.h>
#include <string>
#include <system_error>
#include "Socket.h"

class Server {

    std::string server_address;
    uint16_t server_port = 80;
    struct sockaddr_in addr;

    std::list<std::string> usernames;
    std::queue<std::string> messages;
    int sock_server_fd;

public:
    Server(std::string address, uint16_t port);
    ~Server();
    Socket accept(struct sockadd* addr, socklen_t len);

};


#endif //LABORATORIO5_2020_SERVER_H
