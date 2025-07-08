#ifndef ROUTE_CONFIG_HPP
# define ROUTE_CONFIG_HPP

# include <map>
# include <vector>

# include "../utils/Path.hpp"
# include "../utils/ft_utils.hpp"

# define INDENT "    "

class RouteConfig
{
    private:
        t_strings allowed_methods;
        std::string location;
        std::map<int, std::string> redirections;  // status_code -> path; (return directive)
        std::string root;  // define a dir or file where the file should be searched
        bool directory_listing;
        std::string default_file_if_request_is_directory;  // ??? pretty long name ???

    public:
        RouteConfig();
        RouteConfig(const RouteConfig& other);
        RouteConfig& operator=(const RouteConfig& other);
        ~RouteConfig();

        void set_location(const std::string& location);
        void add_allowed_method(const std::string& method);
        // void add_redirection();
        void set_root(const std::string& root);
        void set_directory_listing(bool do_list);
        // void set_default_file_if_request_is_directory();

        const std::string& get_location() const;
        const std::string& get_root() const;
        const t_strings& get_allowed_methods() const;
};

std::ostream& operator<<(std::ostream& os, const RouteConfig& config);

#endif
