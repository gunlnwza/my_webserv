#ifndef WEB_SERVER_CONFIG_HPP
# define WEB_SERVER_CONFIG_HPP

# include "ServerConfig.hpp"

typedef std::vector<ServerConfig> t_server_configs;

typedef std::map<std::string, ServerConfig*> t_default_servers;

class WebServerConfig
{
    private:
        t_server_configs server_configs;
        
        t_default_servers default_servers;

        void add_server_config(const ServerConfig& server_config);

    public:
        WebServerConfig();
        WebServerConfig(const WebServerConfig& other);
        WebServerConfig& operator=(const WebServerConfig& other);
        ~WebServerConfig();

        const t_server_configs& get_server_configs() const;

        void parse_config(const std::string& config_str);
};

std::ostream& operator<<(std::ostream& os, const WebServerConfig& config);

#endif
