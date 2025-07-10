#ifndef SOCKET_MANAGER_HPP
# define SOCKET_MANAGER_HPP

# include <sys/socket.h>
# include <arpa/inet.h>
# include <unistd.h>

# include "HTTPMessage/Request.hpp"
# include "HTTPMessage/Response.hpp"

class SocketManager
{
    private:
        int server_fd;
        struct sockaddr_in address;

        int client_fd;
        char buffer[3000];

        void read_request();
        void send_response();

    public:
        SocketManager();
        SocketManager(const SocketManager& other);
        SocketManager& operator=(const SocketManager& other);
        ~SocketManager();

        void setup_socket();
        void wait_for_client();
        void serve_client();
};

#endif
