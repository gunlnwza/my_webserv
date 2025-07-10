#include "../headers/WebServer.hpp"


WebServer::WebServer() {}

WebServer::WebServer(const WebServer& other) { *this = other; }

WebServer& WebServer::operator=(const WebServer& other)
{
    (void) other;
    return (*this);
}

WebServer::~WebServer() {}


WebServer::WebServer(const WebServerConfig& config) { this->config = config; }

WebServer::WebServer(const std::string& filename)
{
    std::string config_str = get_file_content(filename);
    this->config.parse_config(config_str);
}


void WebServer::init()
{
    this->socket_manager.setup_socket();
}

void WebServer::run()
{
    this->socket_manager.run_event_loop();
}
