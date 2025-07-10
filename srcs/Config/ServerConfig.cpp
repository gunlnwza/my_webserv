#include "../../headers/Config/ServerConfig.hpp"


ServerConfig::ServerConfig() {}

ServerConfig::ServerConfig(const ServerConfig& other) { *this = other; }

ServerConfig& ServerConfig::operator=(const ServerConfig& other)
{
    this->server_names = other.server_names;
    this->host = other.host;
    this->port = other.port;
    this->error_pages = other.error_pages;
    this->max_client_body_size = other.max_client_body_size;
    this->location_blocks = other.location_blocks;
    return (*this);
}

ServerConfig::~ServerConfig() {}


void ServerConfig::add_server_name(const std::string& server_name) { this->server_names.push_back(server_name); }

void ServerConfig::set_host(const std::string& host) { this->host = host; }

void ServerConfig::set_port(const std::string& port) { this->port = port; }

// void add_default_error_page(const std::string& default_error_page)

void ServerConfig::set_max_client_body_size(size_t max_size) { this->max_client_body_size = max_size; }

void ServerConfig::add_location_block(const LocationBlock& config) { this->location_blocks.push_back(config); }


const t_location_blocks& ServerConfig::get_location_blocks() const { return (this->location_blocks); }
const t_strings& ServerConfig::get_server_names() const { return (this->server_names); }

std::ostream& operator<<(std::ostream& os, const ServerConfig& s)
{
    t_location_blocks ls = s.get_location_blocks();

    os << INDENT << "ServerConfig(" << std::endl;
    os << INDENT << INDENT << "listen: " << s.host << ":" << s.port << std::endl;
    os << INDENT << INDENT << "server_name: " << s.get_server_names() << std::endl;
    for (t_location_blocks::const_iterator it = ls.begin(); it != ls.end(); ++it)
        os << *it << std::endl;
    os << INDENT << ")";
    return (os);
}


void ServerConfig::parse_server(t_tokens_const_it& it, const t_tokens_const_it& it_end)
{
    LocationBlock l;

    expect(SERVER, it);
    ++it;
    expect(LBRACE, it);
    ++it;
    while (it != it_end && !token_is(RBRACE, it))
    {
        if (token_is(LISTEN, it))
        {
            ++it;
            expect(NUMBER, it);
            this->host = "0.0.0.0";  // TODO: implement spliting listen <host>:<port>
            this->port = it->get_value();
            ++it;
            expect(SEMICOLON, it);
            ++it;
        }
        else if (token_is(SERVER_NAME, it))
        {
            ++it;
            expect(IDENTIFIER, it);
            this->add_server_name(it->get_value());
            ++it;
            expect(SEMICOLON, it);
            ++it;
        }
        else if (token_is(LOCATION, it))
        {
            l.parse_location(it, it_end);
            this->add_location_block(l);
        }
        else
            throw (std::runtime_error("not implemented token: \"" + it->get_value() + "\""));
    }
    expect(RBRACE, it);
    ++it;
}
