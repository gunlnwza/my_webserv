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
    this->redirections = other.redirections;
    this->root = other.root;
    this->directory_listing = other.directory_listing;
    this->default_file_if_request_is_directory = other.default_file_if_request_is_directory;
    return (*this);
}

RouteConfig::~RouteConfig()
{}


void RouteConfig::set_location(const std::string& location)
{
    this->location = location;
}

void RouteConfig::add_allowed_method(const std::string& method)
{
    this->allowed_methods.push_back(method);
}

// void add_redirection()

void RouteConfig::set_root(const std::string& root)
{
    this->root = root;
}

void RouteConfig::set_directory_listing(bool do_list)
{
    this->directory_listing = do_list;
}

// void set_default_file_if_request_is_directory();

const std::string& RouteConfig::get_location() const
{
    return (this->location);
}

const std::string& RouteConfig::get_root() const
{
    return (this->root);
}

const t_strings& RouteConfig::get_allowed_methods() const
{
    return (this->allowed_methods);
}


void put_strings(std::ostream& os, const t_strings& strings, const std::string sep)
{
    t_strings::const_iterator it = strings.begin();
    t_strings::const_iterator it_end = strings.end();

    for (; it != it_end; ++it)
    {
        if ((it + 1) != it_end)
            os << *it << sep;
        else
            os << *it;
    }
}

void put_strings(std::ostream& os, const t_strings& strings)
{
    put_strings(os, strings, " ");
}

std::ostream& operator<<(std::ostream& os, const RouteConfig& config)
{
    os << "location: " << config.get_location() << std::endl;

    os << "root: " << config.get_root() << std::endl;

    os << "allowed methods: ";
    put_strings(os, config.get_allowed_methods(), ", ");
    os << std::endl;

    return (os);
}
