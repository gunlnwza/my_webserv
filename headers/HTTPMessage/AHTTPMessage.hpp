#ifndef HTTP_MESSAGE_HPP
# define HTTP_MESSAGE_HPP

# include <map>
# include <string>

# include "../utils/ft_utils.hpp"

typedef std::map<std::string, std::string> t_headers;

class AHTTPMessage
{
    private:
        t_headers headers;
        std::string body;

    public:
        AHTTPMessage();
        AHTTPMessage(const AHTTPMessage& other);
        AHTTPMessage& operator=(const AHTTPMessage& other);
        virtual ~AHTTPMessage() = 0;

        const t_headers& get_headers() const;
        const std::string& get_header_value(const std::string& key) const;
        const std::string& get_body() const;

        void set_header(const std::string& key, const std::string& value);
        void set_body(const std::string& body);
        void append_body(const std::string& str);
};

#endif
