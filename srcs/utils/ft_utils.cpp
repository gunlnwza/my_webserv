#include "../../headers/utils/ft_utils.hpp"

std::string ft_strtrim(const std::string& s, char c)
{
    size_t first = s.find_first_not_of(c);
    if (first == std::string::npos)
        return ("");
    size_t last = s.find_last_not_of(c);
    return (s.substr(first, last - first + 1));
}

bool ft_is_number(const std::string& s)
{
    if (s.empty())
        return (false);

    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it))
        ++it;
    return (it == s.end());
}

void put_strings(std::ostream& os, const t_strings& strings, const std::string& sep)
{
    for (t_strings::const_iterator it = strings.begin(); it != strings.end(); ++it)
    {
        if ((it + 1) != strings.end())
            os << *it << sep;
        else
            os << *it;
    }
}

void put_strings(std::ostream& os, const t_strings& strings)
{
    put_strings(os, strings, " ");
}
