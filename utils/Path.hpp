#ifndef PATH_HPP
# define PATH_HPP

# include <vector>

# include "ft_utils.hpp"

typedef std::vector<std::string> t_strings;

class Path
{
    private:
        t_strings components;

    public:
        Path();
        Path(const Path& other);
        Path& operator=(const Path& other);
        ~Path();

        Path(const std::string& path);
        Path(const t_strings& components);

        Path operator+(const Path& other);

        void set_path(const std::string& path);

        std::string get_string() const;
};

#endif
