#include "ServerConfig.hpp"


ServerConfig::ServerConfig()
{}

ServerConfig::ServerConfig(const ServerConfig& other)
{
    *this = other;
}

ServerConfig& ServerConfig::operator=(const ServerConfig& other)
{
    this->server_names = other.server_names;
    this->host = other.host;
    this->port = other.port;
    this->default_error_pages = other.default_error_pages;
    this->max_client_body_size = other.max_client_body_size;
    this->route_configs = other.route_configs;
    return (*this);
}

ServerConfig::~ServerConfig()
{}


void ServerConfig::add_server_name(const std::string& server_name)
{
    this->server_names.push_back(server_name);
}

void ServerConfig::set_host(int host)
{
    this->host = host;
}

void ServerConfig::set_port(int port)
{
    this->port = port;
}

// void add_default_error_page(const std::string& default_error_page)


void ServerConfig::set_max_client_body_size(size_t max_size)
{
    this->max_client_body_size = max_size;
}


void ServerConfig::add_route_config(const RouteConfig& config)
{
    this->route_configs.push_back(config);
}
