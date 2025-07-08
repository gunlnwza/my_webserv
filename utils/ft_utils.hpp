#ifndef FT_UTILS_HPP
# define FT_UTILS_HPP

# include <string>

# include <iostream>
# include <sstream>
# include <fstream>

# include "Logger.hpp"

typedef std::vector<std::string> t_strings;

template <typename T>
std::string ft_to_string(const T& item)
{
    std::stringstream ss;

    ss << item;
    return (ss.str());
}

std::string ft_strtrim(const std::string& s, char c);

void put_strings(std::ostream& os, const t_strings& strings, const std::string& sep);
void put_strings(std::ostream& os, const t_strings& strings);

#endif
