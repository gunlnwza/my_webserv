#ifndef SOCKET_MANAGER_HPP
# define SOCKET_MANAGER_HPP

# include <set>

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

        fd_set read_fds;
        int max_fd;

        std::set<int> client_fds;

        // void read_request();
        // void send_response();

        void set_read_fds();
        void update_client_fds();
        void serve_clients();

    public:
        SocketManager();
        SocketManager(const SocketManager& other);
        SocketManager& operator=(const SocketManager& other);
        ~SocketManager();

        void setup_socket();
        void run_event_loop();

        // void wait_for_client();
        // void serve_client();

};

#endif
