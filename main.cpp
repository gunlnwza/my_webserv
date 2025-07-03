#include "WebServer.hpp"
#include "Logger.hpp"

int main()
{
    WebServer web_server;

    web_server.setup_socket();
    web_server.wait_for_client();
    web_server.serve_client();

    return (EXIT_SUCCESS);
}
