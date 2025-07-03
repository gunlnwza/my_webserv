#ifndef RESPONSE_HPP
# define RESPONSE_HPP

# include <string>
# include <map>
# include <iostream>
# include <sstream>
# include <fstream>

# include "Logger.hpp"

# include "HTTPMessage.hpp"

class Response: public HTTPMessage
{
    private:
        std::string protocol_version, status_code, status_message;
        std::map<std::string, std::string> headers;
        std::string body;

    public:
        Response();
        Response(const Response& other);
        Response& operator=(const Response& other);
        ~Response();

        Response(const std::string& protocol_version, const std::string& status_code, const std::string& status_message);

        const std::string& get_protocol_version() const;
        const std::string& get_status_code() const;
        const std::string& get_status_message() const;

        const std::map<std::string, std::string>& get_headers() const;
        const std::string& get_header_value(const std::string& key) const;
        const std::string& get_body() const;

        void set_header(const std::string& key, const std::string& value);
        void set_body(const std::string& body);

        void build();
        std::string get_string() const;
};

std::ostream& operator<<(std::ostream& os, const Response& res);

#endif
