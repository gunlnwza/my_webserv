#ifndef SERVER_CONFIG_HPP
# define SERVER_CONFIG_HPP

# include "LocationBlock.hpp"

typedef std::vector<LocationBlock> t_location_blocks;

class ServerConfig
{
    private:

    public:
        std::string host, port;
        t_strings server_names;
        std::map<int, std::string> error_pages;  // status_code -> path
        size_t max_client_body_size;
        t_location_blocks location_blocks;

        std::string listen, server_name;

        void add_server_name(const std::string& server_name);
        void set_host(const std::string& host);
        void set_port(const std::string& port);
        // void add_default_error_page(const std::string& default_error_page);
        void set_max_client_body_size(size_t max_size);

        void add_location_block(const LocationBlock& config);

        ServerConfig();
        ServerConfig(const ServerConfig& other);
        ServerConfig& operator=(const ServerConfig& other);
        ~ServerConfig();

        const t_location_blocks& get_location_blocks() const;
        const t_strings& get_server_names() const;

        void parse_server(t_tokens_const_it& it, const t_tokens_const_it& it_end);
};

std::ostream& operator<<(std::ostream& os, const ServerConfig& s);

#endif
