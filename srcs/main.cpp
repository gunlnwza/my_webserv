#include "../headers/WebServer.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: ./webserv <config_file>" << std::endl;
        return (EXIT_FAILURE);
    }

    WebServer web_server(argv[1]);

    web_server.init();
    web_server.run();

    return (EXIT_SUCCESS);
}
