#include "../headers/WebServer.hpp"

static WebServerConfig read_config()
{
    WebServerConfig config;
    ServerConfig server_config;
    RouteConfig route_config;

    route_config.set_location("/");
    route_config.set_root("/var/www/html");
    route_config.add_allowed_method("GET");
    route_config.add_allowed_method("POST");

    server_config.set_port("8080");
    server_config.add_route_config(route_config);

    config.add_server_config(server_config);

    return (config);
}

int main()
{
    WebServerConfig config = read_config();

    std::cout << config << std::endl;

    WebServer web_server(config);

    web_server.setup_socket();
    web_server.wait_for_client();
    web_server.serve_client();

    return (EXIT_SUCCESS);
}
