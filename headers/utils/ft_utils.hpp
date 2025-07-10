#ifndef FT_UTILS_HPP
# define FT_UTILS_HPP

# include <string>

# include <iostream>
# include <sstream>
# include <fstream>

# include "../Logger/Logger.hpp"

typedef std::vector<std::string> t_strings;

template <typename T>
std::string ft_to_string(const T& item)
{
    std::stringstream ss;

    ss << item;
    return (ss.str());
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
{
    os << "Vector(";
    for (t_strings::const_iterator it = v.begin(); it != v.end(); ++it)
    {
        os << *it;
        if (it + 1 != v.end())
            os << ", ";
    }
    os << ")";
    return (os);
}

std::string ft_strtrim(const std::string& s, char c);

bool ft_is_number(const std::string& s);
std::string get_file_content(const std::string& filename);

#endif
