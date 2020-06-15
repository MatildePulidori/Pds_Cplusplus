//
// Created by Matilde Pulidori on 13/06/2020.
//

#ifndef LABORATORIO5_2020_SOCKET_H
#define LABORATORIO5_2020_SOCKET_H

#include <sys/socket.h>
#include <system_error>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

class Socket {

    int fd;
    Socket(const Socket& )=delete;
    Socket& operator=(const Socket&)=delete;
    

public:
    Socket();
    Socket(int sock_fd);
    ~Socket();


    friend class Server;
};


#endif //LABORATORIO5_2020_SOCKET_H
