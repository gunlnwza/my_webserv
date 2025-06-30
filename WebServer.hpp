#ifndef WEB_SERVER_HPP
# define WEB_SERVER_HPP

# include <iostream>
# include <sys/socket.h>
# include <arpa/inet.h>
# include <unistd.h>

class WebServer
{
    private:
        int server_fd;
        struct sockaddr_in address;

        int client_fd;
        char buffer[3000];

        void read_request();
        void send_response();

    public:
        WebServer();
        WebServer(const WebServer& other);
        WebServer& operator=(const WebServer& other);
        ~WebServer();

        void setup_socket();
        void wait_for_client();
        void serve_client();
};

#endif
