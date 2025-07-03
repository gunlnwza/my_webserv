#ifndef ROUTE_CONFIG_HPP
# define ROUTE_CONFIG_HPP

/*
server {
    listen
    server_name
}
*/

# include <vector>
# include <string>

typedef std::vector<std::string> t_strings;

class RouteConfig
{
    private:
        t_strings allowed_methods;
        std::string redirection;  // http redirection?
        std::string root;  // define a dir or file where the file should be searched
        bool directory_listing;
        std::string default_file_if_request_is_directory;  // ??? pretty long name ???

    public:
        RouteConfig();
        RouteConfig(const RouteConfig& other);
        RouteConfig& operator=(const RouteConfig& other);
        ~RouteConfig();

        void add_allowed_method(const std::string& method);
        // void add_redirection();
        // void add_root();
        void set_directory_listing(bool do_list);
        // void set_default_file_if_request_is_directory();
};

#endif
