#ifndef WEB_SERVER_HPP
# define WEB_SERVER_HPP

# include <iostream>
# include <sys/socket.h>
# include <arpa/inet.h>
# include <unistd.h>

# include "HTTPMessage/Request.hpp"
# include "HTTPMessage/Response.hpp"

# include "Config/WebServerConfig.hpp"

# include "SocketManager.hpp"

class WebServer
{
    private:
        WebServerConfig config;

        // SocketManager socket_manager;

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

        WebServer(const std::string& config_str);
        WebServer(const WebServerConfig& config);

        void setup_socket();
        void wait_for_client();
        void serve_client();
};

#endif
