#include "../../headers/WebServer/SocketManager.hpp"


SocketManager::SocketManager() {}

SocketManager::SocketManager(const SocketManager& other) { *this = other; }

SocketManager& SocketManager::operator=(const SocketManager& other)
{
    (void) other;
    return (*this);
}

SocketManager::~SocketManager() {}


void SocketManager::setup_socket(const WebServerConfig& config)
{
    (void) config;
    // std::cout << "setup_socket" << std::endl;
    this->server_fd = socket(AF_INET, SOCK_STREAM, 0);

    this->address.sin_family = AF_INET;
    this->address.sin_addr.s_addr = INADDR_ANY;
    this->address.sin_port = htons(8000);

    int opt = 1;
    setsockopt(this->server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    int addrlen = sizeof(this->address);
    bind(this->server_fd, (struct sockaddr*)&this->address, addrlen);

    listen(this->server_fd, SOMAXCONN);
    // std::cout << "setup_socket finish" << std::endl;

    this->max_fd = this->server_fd;
}

void SocketManager::set_read_fds()
{
    FD_ZERO(&read_fds);
    FD_SET(this->server_fd, &read_fds);
    for (std::set<int>::iterator it = this->client_fds.begin(); it != this->client_fds.end(); ++it)
    {
        int fd = *it;
        FD_SET(fd, &read_fds);
        if (fd > max_fd)
            max_fd = fd;
    }
}

void SocketManager::update_client_fds()
{
    this->set_read_fds();

    int activity = select(this->max_fd + 1, &read_fds, NULL, NULL, NULL);
    (void) activity;

    if (FD_ISSET(this->server_fd, & read_fds))
    {
        int addrlen = sizeof(address);
        int new_client_fd = accept(this->server_fd, (struct sockaddr*)&this->address, (socklen_t*)&addrlen);
        client_fds.insert(new_client_fd);
        std::cout << "🎉 New client connected" << std::endl;
    }
}

void print_client_fds(const std::set<int>& client_fds)
{
    std::cout << "client_fds: [ ";
    for (std::set<int>::const_iterator it = client_fds.begin(); it != client_fds.end(); ++it) {
        std::cout << *it << ", ";
    }  
    std::cout << "]" << std::endl;
}

void SocketManager::serve_clients()
{
    for (std::set<int>::iterator it = client_fds.begin(); it != client_fds.end();)
    {
        int fd = *it;
        if (FD_ISSET(fd, &read_fds))
        {
            char buffer[4096];
            ssize_t bytes_read = recv(fd, buffer, sizeof(buffer) - 1, 0);
            if (bytes_read <= 0) {
                std::cout << "❌ Disconnected: " << fd << std::endl;
                close(fd);
                it = client_fds.erase(it);
                continue; // Important: avoid using invalidated iterator
            }
            buffer[bytes_read] = '\0';
            std::cout << "📥 Received: " << buffer << std::endl;

            Response response("HTTP/1.1", "200", "OK");
            response.build();

            std::string s = response.get_string();
            ssize_t bytes_sent = send(fd, s.c_str(), s.size(), 0);
            (void) bytes_sent;
            std::cout << "sent: " << std::endl;
            std::cout << s << std::endl;
        }
        ++it;
    }
}

void SocketManager::run_event_loop()
{
    int limit = 20;
    while (true)
    {
        if (limit-- == 0) { std::cout << "Infinite Loop?" << std::endl; break ; }
        this->update_client_fds();
        this->serve_clients();
        print_client_fds(this->client_fds);
    }
}


// void SocketManager::wait_for_client()
// {
//     std::cout << "wait_for_client" << std::endl;
//     int addrlen = sizeof(address);
//     this->client_fd = accept(this->server_fd, (struct sockaddr*)&this->address, (socklen_t*)&addrlen);
//     std::cout << "wait_for_client finish" << std::endl;
// }

// void SocketManager::read_request()
// {
//     read(this->client_fd, this->buffer, 3000);
// }

// void SocketManager::send_response()
// {
//     Response response;

//     response.build();

//     std::string s = response.get_string();
//     Logger::log("sent:");
//     Logger::log(s);
    
//     send(this->client_fd, s.c_str(), s.size(), 0);
// }

// void SocketManager::serve_client()
// {
//     std::cout << "serve_client" << std::endl;
//     this->read_request();
//     this->send_response();
//     close(this->client_fd);
//     std::cout << "serve_client finish" << std::endl;
// }
