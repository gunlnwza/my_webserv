#ifndef SERVER_CONFIG_HPP
# define SERVER_CONFIG_HPP

# include "RouteConfig.hpp"

typedef std::vector<RouteConfig> t_route_configs;

class ServerConfig
{
    private:
        std::string host, port;
        t_strings server_names;
        std::map<int, std::string> error_pages;  // status_code -> path
        size_t max_client_body_size;
        t_route_configs route_configs;

    public:
        ServerConfig();
        ServerConfig(const ServerConfig& other);
        ServerConfig& operator=(const ServerConfig& other);
        ~ServerConfig();

        void add_server_name(const std::string& server_name);
        void set_host(const std::string& host);
        void set_port(const std::string& port);
        // void add_default_error_page(const std::string& default_error_page);
        void set_max_client_body_size(size_t max_size);

        void add_route_config(const RouteConfig& config);

        const t_route_configs& get_route_configs() const;
};

std::ostream& operator<<(std::ostream& os, const ServerConfig& config);

#endif
