#ifndef FT_UTILS_HPP
# define FT_UTILS_HPP

# include <string>

# include <iostream>
# include <sstream>
# include <fstream>

# include "Logger.hpp"

template <typename T>
std::string ft_to_string(const T& item)
{
    std::stringstream ss;

    ss << item;
    return (ss.str());
}

std::string ft_strtrim(const std::string& s, char c);

bool ft_is_number(const std::string& s);

#endif
