#ifndef RESPONSE_HPP
# define RESPONSE_HPP

# include "AHTTPMessage.hpp"

class Response: public AHTTPMessage
{
    private:
        std::string protocol_version, status_code, status_message;

        Response();
        Response(const Response& other);
        Response& operator=(const Response& other);

    public:
        Response(const std::string& protocol_version, const std::string& status_code, const std::string& status_message);
        ~Response();

        const std::string& get_protocol_version() const;
        const std::string& get_status_code() const;
        const std::string& get_status_message() const;

        void build();
        std::string get_string() const;
};

std::ostream& operator<<(std::ostream& os, const Response& res);

#endif
