#ifndef REQUEST_HPP
# define REQUEST_HPP

# include <string>
# include <map>
# include <iostream>
# include <sstream>

class Request
{
    private:
        std::string method, path, protocol_version;
        std::map<std::string, std::string> headers;
        std::string body;

        void parse_request_string(const std::string& req_str);

    public:
        Request();
        Request(const Request& other);
        Request& operator=(const Request& other);
        ~Request();

        const std::string& get_method() const;
        const std::string& get_path() const;
        const std::string& get_protocol_version() const;
        const std::map<std::string, std::string>& get_headers() const;
        const std::string& get_header_value(const std::string& key) const;
        const std::string& get_body() const;

        Request(const std::string& req_str);
};

std::ostream& operator<<(const std::ostream& os, const Request& req);


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
