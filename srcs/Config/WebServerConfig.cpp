#include "../../headers/Config/WebServerConfig.hpp"


WebServerConfig::WebServerConfig() {}

WebServerConfig::WebServerConfig(const WebServerConfig& other) { *this = other; }

WebServerConfig& WebServerConfig::operator=(const WebServerConfig& other)
{
    this->server_configs = other.server_configs;
    return (*this);
}

WebServerConfig::~WebServerConfig() {}


void WebServerConfig::add_server_config(const ServerConfig& server_config) { this->server_configs.push_back(server_config); }


const t_server_configs& WebServerConfig::get_server_configs() const { return (this->server_configs); }

std::ostream& operator<<(std::ostream& os, const WebServerConfig& config)
{
    t_server_configs server_configs = config.get_server_configs();
    t_server_configs::const_iterator it = server_configs.begin();
    t_server_configs::const_iterator it_end = server_configs.end();

    os << "WebServerConfig(" << std::endl;
    
    for (; it != it_end; ++it)
        os << *it << std::endl;
    os << ")";
    return (os);
}


void WebServerConfig::parse_config(const std::string& config_str)
{
    Tokenizer tokenizer;
    t_tokens tokens = tokenizer.tokenize(config_str);

    ServerConfig s;
    t_tokens::const_iterator it = tokens.begin();
    t_tokens::const_iterator it_end = tokens.end();
    while (it != it_end)
    {
        s.parse_server(it, it_end);
        this->add_server_config(s);
    }
}
