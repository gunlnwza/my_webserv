#include "ft_utils.hpp"

std::string ft_strtrim(const std::string& s, char c)
{
    size_t first = s.find_first_not_of(c);
    if (first == std::string::npos)
        return ("");
    size_t last = s.find_last_not_of(c);
    return (s.substr(first, last - first + 1));
}
