#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

void log(const std::string& msg)
{
    std::cout << msg << std::endl;
}

void setup_socket(int& server_fd, struct sockaddr_in& address)
{
    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8000);

    int opt = 1;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    bind(server_fd, (struct sockaddr*)&address, sizeof(address));

    listen(server_fd, SOMAXCONN);
}

void wait_for_client(int& server_fd, struct sockaddr_in& address, int& client_fd)
{
    int addrlen = sizeof(address);

    client_fd = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&addrlen);
}

void read_request(int& client_fd, char* buffer)
{
    read(client_fd, buffer, 3000);
}

void send_response(int& client_fd)
{
    const std::string response =
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: text/html\r\n"
        "Content-Length: 36\r\n"
        "\r\n"
        "<html><body>Hello world</body></html>";

    send(client_fd, response.c_str(), response.size(), 0);
}

void serve_client(int& client_fd)
{
    char buffer[3000] = {0};

    read_request(client_fd, buffer);
    send_response(client_fd);
    close(client_fd);
}

int main()
{
    int server_fd;
    struct sockaddr_in address;
    int client_fd;

    setup_socket(server_fd, address);
    wait_for_client(server_fd, address, client_fd);
    serve_client(client_fd);
    return (EXIT_SUCCESS);
}
