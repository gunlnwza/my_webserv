#ifndef WEB_SERVER_HPP
# define WEB_SERVER_HPP

# include "Config/WebServerConfig.hpp"
# include "SocketManager.hpp"

class WebServer
{
    private:
        WebServerConfig config;
        SocketManager socket_manager;

    public:
        WebServer();
        WebServer(const WebServer& other);
        WebServer& operator=(const WebServer& other);
        ~WebServer();

        WebServer(const std::string& config_str);
        WebServer(const WebServerConfig& config);

        void init();
        void run();
};

#endif
