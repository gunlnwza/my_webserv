#include "RouteConfig.hpp"


RouteConfig::RouteConfig()
{}

RouteConfig::RouteConfig(const RouteConfig& other)
{
    *this = other;
}

RouteConfig& RouteConfig::operator=(const RouteConfig& other)
{
    this->allowed_methods = other.allowed_methods;
    this->redirection = other.redirection;
    this->root = other.root;
    this->directory_listing = other.directory_listing;
    this->default_file_if_request_is_directory = other.default_file_if_request_is_directory;
    return (*this);
}

RouteConfig::~RouteConfig()
{}


void RouteConfig::add_allowed_method(const std::string& method)
{
    this->allowed_methods.push_back(method);
}

// void add_redirection()

// void add_root()

void RouteConfig::set_directory_listing(bool do_list)
{
    this->directory_listing = do_list;
}

// void set_default_file_if_request_is_directory();
