#ifndef WEB_SERVER_CONFIG_HPP
# define WEB_SERVER_CONFIG_HPP

# include "ServerConfig.hpp"

typedef std::vector<ServerConfig> t_server_configs;

class WebServerConfig
{
    private:
        t_server_configs server_configs;

    public:
        WebServerConfig();
        WebServerConfig(const WebServerConfig& other);
        WebServerConfig& operator=(const WebServerConfig& other);
        ~WebServerConfig();

        void add_server_config(const ServerConfig& server_config);
};

std::ostream& operator<<(std::ostream& os, const WebServerConfig& config);

#endif
