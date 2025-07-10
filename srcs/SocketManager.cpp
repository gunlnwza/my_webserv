#include "../headers/SocketManager.hpp"


SocketManager::SocketManager() {}

SocketManager::SocketManager(const SocketManager& other) { *this = other; }

SocketManager& SocketManager::operator=(const SocketManager& other)
{
    (void) other;
    return (*this);
}

SocketManager::~SocketManager() {}


void SocketManager::setup_socket()
{
    std::cout << "setup_socket" << std::endl;
    this->server_fd = socket(AF_INET, SOCK_STREAM, 0);

    this->address.sin_family = AF_INET;
    this->address.sin_addr.s_addr = INADDR_ANY;
    this->address.sin_port = htons(8000);

    int opt = 1;
    setsockopt(this->server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    int addrlen = sizeof(this->address);
    bind(this->server_fd, (struct sockaddr*)&this->address, addrlen);

    listen(this->server_fd, SOMAXCONN);
    std::cout << "setup_socket finish" << std::endl;
}

void SocketManager::wait_for_client()
{
    std::cout << "wait_for_client" << std::endl;
    int addrlen = sizeof(address);
    this->client_fd = accept(this->server_fd, (struct sockaddr*)&this->address, (socklen_t*)&addrlen);
    std::cout << "wait_for_client finish" << std::endl;
}

void SocketManager::read_request()
{
    read(this->client_fd, this->buffer, 3000);
}

void SocketManager::send_response()
{
    Response response;

    response.build();

    std::string s = response.get_string();
    Logger::log("sent:");
    Logger::log(s);
    
    send(this->client_fd, s.c_str(), s.size(), 0);
}

void SocketManager::serve_client()
{
    std::cout << "serve_client" << std::endl;
    this->read_request();
    this->send_response();
    close(this->client_fd);
    std::cout << "serve_client finish" << std::endl;
}
