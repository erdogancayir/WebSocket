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

int createSocket(void);