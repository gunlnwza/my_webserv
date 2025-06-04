#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

void log(const std::string& msg)
{
    std::cout << msg << std::endl;
}

int main()
{
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8000);

    int opt = 1;
    log("setsockopt");
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    log("bind");
    bind(server_fd, (struct sockaddr*)&address, sizeof(address));

    log("listen");
    listen(server_fd, SOMAXCONN);

    log("accept");
    int addrlen = sizeof(address);
    int client_fd = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen);

    log("read");
    char buffer[3000] = {0};
    read(client_fd, buffer, 3000);

    std::string response =
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: text/html\r\n"
        "Content-Length: 36\r\n"
        "\r\n"
        "<html><body>Hello world</body></html>";

    log("send");
    send(client_fd, response.c_str(), response.size(), 0);
    
    log("close");
    close(client_fd);

    return (EXIT_SUCCESS);
}
