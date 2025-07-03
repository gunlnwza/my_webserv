#include "Request.hpp"


Request::Request() {}

Request::Request(const Request& other)
{
    *this = other;
}

Request& Request::operator=(const Request& other)
{
    this->method = other.method;
    this->path = other.path;
    this->protocol_version = other.protocol_version;
    this->headers = other.headers;
    this->body = other.body;
    return (*this);
}

Request::~Request() {}


// TODO: make it more robust, right now it is not really correct
// NOTE: can use get_next_line idea to process line by line (with reading from client), maybe?
void Request::parse_request_string(const std::string& req_str)
{
    std::istringstream iss(req_str);
    std::string line;

    iss >> this->method >> this->path >> this->protocol_version;
    while (iss)
    {
        std::getline(iss, line);
        // std::string key, value;  // split
    
        // iss >> key >> value;
        // key = key.substr(0, key.length() - 1);  // trim right :
        // this->headers[key] = value;
    }
}

Request::Request(const std::string& req_str)
{
    this->parse_request_string(req_str);
}


const std::string& Request::get_method() const { return (this->method); }
const std::string& Request::get_path() const { return (this->path); }
const std::string& Request::get_protocol_version() const { return (this->protocol_version); }
const std::map<std::string, std::string>& Request::get_headers() const { return (this->headers); }

const std::string& Request::get_header_value(const std::string& key) const
{
    std::map<std::string, std::string>::const_iterator it = this->headers.find(key);
    if (it == this->headers.end())
        throw (std::runtime_error("header not found"));
    return (it->second);
}

const std::string& Request::get_body() const { return (this->body); }


std::ostream& operator<<(std::ostream& os, const Request& req)
{
    os << req.get_method() << " " << req.get_path() << " " << req.get_protocol_version() << std::endl;
    for (std::map<std::string, std::string>::const_iterator it = req.get_headers().begin(); it != req.get_headers().end(); ++it)
        os << it->first << ": " << it->second << std::endl;
    os << std::endl;
    os << req.get_body() << std::endl;
    return (os);
}


// int main()
// {
//     const std::string s = \
//         "GET / HTTP/1.1\r\n"
//         "Host: developer.mozilla.org\r\n"
//         "Accept-Language: fr\r\n"
//         "\r\n";

//     Request req(s);
//     std::cout << "parsed request: " << std::endl 
//         << req << std::endl;
// }
