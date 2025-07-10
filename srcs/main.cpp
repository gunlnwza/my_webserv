#include "../headers/WebServer/WebServer.hpp"

int main(int argc, char **argv)
{
    if (argc > 2)
    {
        std::cout << "Usage: ./webserv [config file]" << std::endl;
        return (EXIT_FAILURE);
    }

    std::string config_filename;
    if (argc == 2)
        config_filename = argv[1];
    else
        config_filename = "configs/default.conf";

    WebServer web_server(config_filename);

    web_server.init();
    web_server.run();

    return (EXIT_SUCCESS);
}
