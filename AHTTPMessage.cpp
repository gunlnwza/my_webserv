#include "AHTTPMessage.hpp"


AHTTPMessage::AHTTPMessage() {}

AHTTPMessage::AHTTPMessage(const AHTTPMessage& other)
: headers(other.headers), body(other.body)
{}

AHTTPMessage& AHTTPMessage::operator=(const AHTTPMessage& other)
{
    this->headers = other.headers;
    this->body = other.body;
    return (*this);
}


const t_headers& AHTTPMessage::get_headers() const
{
    return (this->headers);
}

const std::string& AHTTPMessage::get_header_value(const std::string& key) const
{
    t_headers::const_iterator it = this->headers.find(key);
    if (it == this->headers.end())
        throw (std::runtime_error("header not found"));
    return (it->second);
}

const std::string& AHTTPMessage::get_body() const
{
    return (this->body);
}


void AHTTPMessage::set_header(const std::string& key, const std::string& value)
{
    this->headers[key] = value;
}

void AHTTPMessage::set_body(const std::string& body)
{
    this->body = body;
}
