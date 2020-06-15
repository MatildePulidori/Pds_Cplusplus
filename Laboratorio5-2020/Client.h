//
// Created by Matilde Pulidori on 13/06/2020.
//

#ifndef LABORATORIO5_2020_CLIENT_H
#define LABORATORIO5_2020_CLIENT_H


#include <netinet/in.h>
#include <system_error>
#include <string>

class Client {
    int sock_fd, port;
    struct sockaddr_in serv_adrr;
    struct hostent host;

public:
    Client(int port, std::string server_address);
    ~Client();


};


#endif //LABORATORIO5_2020_CLIENT_H
