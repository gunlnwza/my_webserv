#ifndef WEB_SERVER_HPP
# define WEB_SERVER_HPP

# include "../Config/WebServerConfig.hpp"
# include "SocketManager.hpp"

class WebServer
{
    private:
        WebServerConfig config;
        SocketManager socket_manager;

        WebServer();
        WebServer(const WebServer& other);
        WebServer& operator=(const WebServer& other);
        
    public:
        ~WebServer();

        WebServer(const WebServerConfig& config);
        WebServer(const std::string& config_str);

        void init();
        void run();
};

#endif
