#ifndef REQUEST_HPP
# define REQUEST_HPP

# include "AHTTPMessage.hpp"

class Request: public AHTTPMessage
{
    private:
        std::string method, path, protocol_version;

        void parse_request_string(const std::string& req_str);

    public:
        Request();
        Request(const Request& other);
        Request& operator=(const Request& other);
        ~Request();

        Request(const std::string& req_str);

        const std::string& get_method() const;
        const std::string& get_path() const;
        const std::string& get_protocol_version() const;
};

std::ostream& operator<<(std::ostream& os, const Request& req);


// // just an idea, but feels very promising to implement
// #include <vector>
// class HeaderValue
// {
//     private:
//         std::vector<std::string> values;
// };

// class CookieValue : public HeaderValue {};
// class AuthHeader : public HeaderValue {};


#endif
