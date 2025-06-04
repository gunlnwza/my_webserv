#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main()
{
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8000);

    bind(server_fd, (struct sockaddr*)&address, sizeof(address));

    listen(server_fd, SOMAXCONN);

    int addrlen = sizeof(address);
    int client_fd = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen);

    char buffer[3000] = {0};
    read(client_fd, buffer, 3000);

    std::string response =
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: text/html\r\n"
        "Content-Length: 38\r\n"
        "\r\n"
        "<html><body>Hello world</body></html>";

    send(client_fd, response.c_str(), response.size(), 0);
    close(client_fd);

    return (EXIT_SUCCESS);
}
