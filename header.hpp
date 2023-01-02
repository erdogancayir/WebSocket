#pragma once

#include "sys/types.h" // for socket
#include "sys/socket.h" // for socket
#include <netdb.h> // for struct sockaddr_in
#include "string.h"
#include "iostream"
#include "unistd.h"
#include "stdlib.h"
#include <fcntl.h>
#include <ostream>
#include <fstream>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/select.h>
#include <stdio.h>
typedef struct kk
{
    struct sockaddr_in client_addr;
	std::string res;
    char 		c;
    std::fstream file;
    struct timeval timeout;
    fd_set read_fds;    // master file descriptor list
    int         new_sockfd;
    socklen_t   len;
    int         read_bytes;
}client;

int createSocket(void);