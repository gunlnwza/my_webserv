#include "../headers/SocketManager.hpp"


SocketManager::SocketManager() {}

SocketManager::SocketManager(const SocketManager& other) { *this = other; }

SocketManager& SocketManager::operator=(const SocketManager& other)
{
    (void) other;
    return (*this);
}

SocketManager::~SocketManager() {}


void SocketManager::setup_socket()
{

}
