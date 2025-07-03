#include "WebServerConfig.hpp"


WebServerConfig::WebServerConfig()
{}

WebServerConfig::WebServerConfig(const WebServerConfig& other)
{
    *this = other;
}

WebServerConfig& WebServerConfig::operator=(const WebServerConfig& other)
{
    this->server_configs = other.server_configs;
    return (*this);
}

WebServerConfig::~WebServerConfig()
{}


void WebServerConfig::add_server_config(const ServerConfig& server_config)
{
    this->server_configs.push_back(server_config);
}
