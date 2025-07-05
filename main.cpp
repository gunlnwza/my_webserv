#include "WebServer.hpp"

int main()
{
    // RouteConfig route_config;
    // ServerConfig server_config;
    // WebServerConfig config;

    // server_config.set_port("8080");

    // route_config.set_location("/");
    // route_config.set_root("/var/www/html");
    // route_config.add_allowed_method("GET");
    // route_config.add_allowed_method("POST");

    // server_config.add_route_config(route_config);
    // config.add_server_config(server_config);

    // std::cout << "route_config: " << std::endl;
    // std::cout << route_config;

    // WebServer web_server(config);

    // web_server.setup_socket();
    // web_server.wait_for_client();
    // web_server.serve_client();

    const std::string raw = "a/b/c//";

    std::cout << raw << ", " << ft_strtrim(raw, '/') << std::endl;

    Path path(raw);

    std::cout << path.get_string() << std::endl;

    return (EXIT_SUCCESS);
}
