#include "header.hpp"

int main(int ac, char **av, char **env)
{
    client a;
    char buff[4096];
    a.file.open("a.html");
    int sockfd = createSocket();
	while (!a.file.eof())
    {
        a.file >> std::noskipws >> a.c;
        a.res += a.c;
    }
    a.file.close();
    a.new_sockfd = -1;
    while (1)
    {
        FD_ZERO(&a.read_fds);
        FD_SET(sockfd, &a.read_fds);

        a.timeout.tv_sec = 5;
        a.timeout.tv_usec = 0;

        int active = select(sockfd + 1, &a.read_fds, NULL, NULL, &a.timeout);
        read(sockfd, buff, 1000);
        if (active < 0)
        {
            perror("select \n");
            exit(1);
        }

        if (FD_ISSET(sockfd, &a.read_fds))
        {
            a.len = sizeof(a.client_addr);
            a.new_sockfd = accept(sockfd, (struct sockaddr *)&a.client_addr, &a.len);
            if (a.new_sockfd < 0)
            {
                perror("accpt error: \n");
                exit(2);
            }
        }
        if (a.new_sockfd != -1){
        a.read_bytes = read(a.new_sockfd, buff, sizeof(buff));
        send(a.new_sockfd, a.res.c_str(), a.res.length(), 0);
        close(a.new_sockfd);}
    }
    return (0);
}