#include "../headers/WebServer.hpp"


WebServer::WebServer() {}

WebServer::WebServer(const WebServer& other) { *this = other; }

WebServer& WebServer::operator=(const WebServer& other)
{
    (void) other;
    return (*this);
}

WebServer::~WebServer() {}

WebServer::WebServer(const std::string& config_str) { this->config.parse_config(config_str); }

WebServer::WebServer(const WebServerConfig& config) { this->config = config; }


void WebServer::init()
{
    this->socket_manager.setup_socket();
}

void WebServer::run()
{
    this->socket_manager.wait_for_client();
    this->socket_manager.serve_client();
}
