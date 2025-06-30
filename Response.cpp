#include "Response.hpp"


Response::Response() {}

Response::Response(const Response& other)
{
    *this = other;
}

Response& Response::operator=(const Response& other)
{
    this->protocol_version = other.protocol_version;
    this->status_code = other.status_code;
    this->status_message = other.status_message;
    this->headers = other.headers;
    this->body = other.body;
    return (*this);
}

Response::~Response() {}

Response::Response(const std::string& protocol_version, const std::string& status_code, const std::string& status_message)
: protocol_version(protocol_version), status_code(status_code), status_message(status_message)
{}


const std::string& Response::get_protocol_version() const { return (this->protocol_version); }
const std::string& Response::get_status_code() const { return (this->status_code); }
const std::string& Response::get_status_message() const { return (this->status_message); }
const std::map<std::string, std::string>& Response::get_headers() const { return (this->headers); }

const std::string& Response::get_header_value(const std::string& key) const
{
    std::map<std::string, std::string>::const_iterator it = this->headers.find(key);
    if (it == this->headers.end())
        throw (std::runtime_error("header not found"));
    return (it->second);
}

const std::string& Response::get_body() const { return (this->body); }

void Response::set_header(const std::string& key, const std::string& value)
{
    this->headers[key] = value;
}

void Response::set_body(const std::string& body)
{
    this->body = body;
}


std::ostream& operator<<(std::ostream& os, const Response& res)
{
    os << res.get_protocol_version() << " " << res.get_status_code() << " " << res.get_status_message() << std::endl;
    for (std::map<std::string, std::string>::const_iterator it = res.get_headers().begin(); it != res.get_headers().end(); ++it)
        os << it->first << ": " << it->second << std::endl;
    os << std::endl;
    os << res.get_body() << std::endl;
    return (os);
}


int main()
{
    Response res("HTTP/1.1", "200", "OK");

    res.set_header("Gun", "Be happy");
    res.set_header("Smile", "True");

    res.set_body("Today will go well.");

    std::cout << res << std::endl;

    return (0);
}