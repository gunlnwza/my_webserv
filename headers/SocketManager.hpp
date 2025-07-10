#ifndef SOCKET_MANAGER_HPP
# define SOCKET_MANAGER_HPP

class SocketManager
{
    private:

    public:
        SocketManager();
        SocketManager(const SocketManager& other);
        SocketManager& operator=(const SocketManager& other);
        ~SocketManager();

        void setup_socket();
};

#endif
