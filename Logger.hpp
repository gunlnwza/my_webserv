#ifndef LOGGER_HPP
# define LOGGER_HPP

# include <string>
# include <iostream>

class Logger
{
    public:
        static void log(const std::string& message);
};

#endif
