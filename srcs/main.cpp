#include "../headers/WebServer.hpp"

int main()
{
    WebServer web_server("configs/test.conf");

    web_server.init();
    web_server.run();

    return (EXIT_SUCCESS);
}
