#include "header.hpp"

int main(int ac, char **av, char **env)
{
    int client_sockfd;
    struct sockaddr_in client_addr;
    char 		c;
	std::string res;
    char buff[4096];
    std::fstream file;
    socklen_t client_addr_len;
    file.open("a.html");
    int sockfd = createSocket();
	while (!file.eof())
    {
        file >> std::noskipws >> c;
        res += c;
    }
    file.close();
    while (1)
    {
        client_addr_len = sizeof(client_addr);
        client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
        client_addr_len = sizeof(client_addr);
        read(client_sockfd, buff, 4096);
        std::cout << buff << std::endl;
        if (client_sockfd < 0) {
            std::cout << "accept error";
            exit(1);
        }
        write(client_sockfd, res.c_str(), res.length());
    }
}