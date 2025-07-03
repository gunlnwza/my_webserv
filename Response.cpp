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
    AHTTPMessage::operator=(other);
    return (*this);
}

Response::~Response() {}

Response::Response(const std::string& protocol_version, const std::string& status_code, const std::string& status_message)
: protocol_version(protocol_version), status_code(status_code), status_message(status_message)
{}


const std::string& Response::get_protocol_version() const { return (this->protocol_version); }
const std::string& Response::get_status_code() const { return (this->status_code); }
const std::string& Response::get_status_message() const { return (this->status_message); }


void Response::build()
{
    this->protocol_version = "HTTP/1.1";
    this->status_code = "200";
    this->status_message = "OK";

    // this->set_header("Content-Type", "text/html; charset=utf-8");

    std::ifstream f("website/index.html");
    std::string s;
    while (std::getline(f, s))
    {
        Logger::log("reading: " + s);
        this->append_body(s);
    }

    this->set_header("Content-Type", "text/html; charset=utf-8");
    this->set_header("Content-Length", ft_to_string(this->get_body().length()));
    this->set_header("Connection", "close");
}

std::string Response::get_string() const
{
    std::stringstream ss;

    ss << this->get_protocol_version() << " " << this->get_status_code() << " " << this->get_status_message() << "\r\n";
    for (std::map<std::string, std::string>::const_iterator it = this->get_headers().begin(); it != this->get_headers().end(); ++it)
        ss << it->first << ": " << it->second << "\r\n";
    ss << "\r\n";
    if (this->get_body().length() > 0)
        ss << this->get_body() << "\r\n";
    return (ss.str());
}


std::ostream& operator<<(std::ostream& os, const Response& res)
{
    // os << res.get_protocol_version() << " " << res.get_status_code() << " " << res.get_status_message() << std::endl;
    // for (std::map<std::string, std::string>::const_iterator it = res.get_headers().begin(); it != res.get_headers().end(); ++it)
    //     os << it->first << ": " << it->second << std::endl;
    // os << std::endl;
    // os << res.get_body() << std::endl;
    os << res.get_string();
    return (os);
}


// int main()
// {
//     // Response res("HTTP/1.1", "200", "OK");

//     // res.set_header("Gun", "Be happy");
//     // res.set_header("Smile", "True");
//     // res.set_body("Today will go well.");

//     Response res();

//     std::cout << res << std::endl;

//     return (0);
// }
