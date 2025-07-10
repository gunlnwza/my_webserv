#include "../headers/WebServer.hpp"

int main()
{
    WebServer web_server("configs/test.conf");

    web_server.setup_socket();
    web_server.wait_for_client();
    web_server.serve_client();

    return (EXIT_SUCCESS);
}
