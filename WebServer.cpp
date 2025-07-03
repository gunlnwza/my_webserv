#include "WebServer.hpp"


WebServer::WebServer()
{

}

WebServer::WebServer(const WebServer& other)
{
    *this = other;
}

WebServer& WebServer::operator=(const WebServer& other)
{
    (void) other;
    return (*this);
}

WebServer::~WebServer()
{

}


void WebServer::setup_socket()
{
    this->server_fd = socket(AF_INET, SOCK_STREAM, 0);

    this->address.sin_family = AF_INET;
    this->address.sin_addr.s_addr = INADDR_ANY;
    this->address.sin_port = htons(8000);

    int opt = 1;
    setsockopt(this->server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    int addrlen = sizeof(this->address);
    bind(this->server_fd, (struct sockaddr*)&this->address, addrlen);

    listen(this->server_fd, SOMAXCONN);
}

void WebServer::wait_for_client()
{
    int addrlen = sizeof(address);
    this->client_fd = accept(this->server_fd, (struct sockaddr*)&this->address, (socklen_t*)&addrlen);
}

void WebServer::read_request()
{
    read(this->client_fd, this->buffer, 3000);
}

void WebServer::send_response()
{
    Response response;

    response.build();

    std::string s = response.get_string();
    Logger::log("sent:");
    Logger::log(s);
    
    send(this->client_fd, s.c_str(), s.size(), 0);
}

void WebServer::serve_client()
{
    this->read_request();
    this->send_response();
    close(this->client_fd);
}
