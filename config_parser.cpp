#include "WebServerConfig.hpp"

/*
server {
    listen 80;
    server_name localhost;

    location / {
        root /var/www/html;
        index index.html;
    }
}
*/

/*
IDENT("server") LBRACE
IDENT("listen") NUMBER("80") SEMICOLON
IDENT("server_name") IDENT("localhost") SEMICOLON
...
*/

void parse_config_string(WebServerConfig& config, const std::string& config_str)
{
    // must use recursive descent parsing, for educational purpose
}

int main()
{
    WebServerConfig config;
    const std::string config_str = \
        "server {}";

    parse_config_string(config, config_str);
}
