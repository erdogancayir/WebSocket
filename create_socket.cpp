#include "header.hpp"

int createSocket(void)
{
    int sockfd;
    struct sockaddr_in adress;
    int on = 1;

    memset(&adress, 0x00, sizeof(adress));
    adress.sin_family = AF_INET;
    adress.sin_addr.s_addr = htonl(INADDR_ANY);
	adress.sin_port = htons((unsigned short) 8080);
    sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sockfd < 0)
    {
        std::cout << "Socket Cannot Create " << std::endl;
        exit(1);
    }
   /*  if (fcntl(sockfd, F_SETFL, O_NONBLOCK) < 0)
    {
        std::cout << "fcntl could not be applied " << std::endl;
        close(sockfd);
        exit(1);
    } */
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) < 0)
    {
        std::cout << "setsocketopt could not be applied " << std::endl;
        close(sockfd);
        exit(1);
    }
    if (bind(sockfd, (const struct sockaddr *)(&adress), sizeof(adress)) < 0)
    {
        std::cout << "failed to create bind" << std::endl;
        close(sockfd);
        exit(1);
    }
    if (listen(sockfd, 10) < 0)
    {
        std::cout << "failed to listen " << std::endl;
        close(sockfd);
        exit(1);
    }
    std::cout << "create socket func bitti " << std::endl;
    return (sockfd);
}