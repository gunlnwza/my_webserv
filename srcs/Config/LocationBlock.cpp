#include "../../headers/Config/LocationBlock.hpp"


LocationBlock::LocationBlock() {}

LocationBlock::LocationBlock(const LocationBlock& other) { *this = other; }

LocationBlock& LocationBlock::operator=(const LocationBlock& other)
{
    this->allowed_methods = other.allowed_methods;
    this->redirections = other.redirections;
    this->root = other.root;
    this->directory_listing = other.directory_listing;
    this->default_file_if_request_is_directory = other.default_file_if_request_is_directory;

    this->index = other.index;
    return (*this);
}

LocationBlock::~LocationBlock() {}


void LocationBlock::set_location(const std::string& location) { this->location = location; }

void LocationBlock::add_allowed_method(const std::string& method) { this->allowed_methods.push_back(method); }

// void add_redirection()

void LocationBlock::set_root(const std::string& root) { this->root = root; }

void LocationBlock::set_index(const std::string& index) { this->index = index; }

void LocationBlock::set_directory_listing(bool do_list) { this->directory_listing = do_list; }

// void set_default_file_if_request_is_directory();

const std::string& LocationBlock::get_location() const { return (this->location); }

const std::string& LocationBlock::get_root() const { return (this->root); }

const t_strings& LocationBlock::get_allowed_methods() const { return (this->allowed_methods); }
const std::string& LocationBlock::get_index() const { return (this->index); }

std::ostream& operator<<(std::ostream& os, const LocationBlock& l)
{
    os << INDENT << INDENT << "LocationBlock(" << std::endl;
    // os << INDENT << INDENT << INDENT << "location: " << l.get_location() << std::endl;
    os << INDENT << INDENT << INDENT << "root: " << l.get_root() << std::endl;
    os << INDENT << INDENT << INDENT << "index: " << l.get_index() << std::endl;
    // os << INDENT << INDENT << INDENT << "allowed methods: "; put_strings(os, l.get_allowed_methods(), ", "); os << std::endl;
    os << INDENT << INDENT << ")";
    (void)l;
    return (os);
}


bool token_is(t_token_type type, const t_tokens_const_it& it)
{
    return (type == it->get_type());
}

bool next_token_is(t_token_type type, const t_tokens_const_it& it)
{
    return (token_is(type, it + 1));
}

void expect(t_token_type type, const t_tokens_const_it& it)
{
    if (!token_is(type, it))
        throw (std::runtime_error("found unexpected token: \"" + it->get_value() + "\""));
}

void LocationBlock::parse_location(t_tokens_const_it& it, const t_tokens_const_it& it_end)
{
    expect(LOCATION, it);
    ++it;
    expect(IDENTIFIER, it);
    ++it;
    expect(LBRACE, it);
    ++it;
    while (it != it_end && !token_is(RBRACE, it))
    {
        if (token_is(ROOT, it))
        {
            ++it;
            expect(IDENTIFIER, it);
            this->set_root(it->get_value());
            ++it;
            expect(SEMICOLON, it);
            ++it;
        }
        else if (token_is(INDEX, it))
        {
            ++it;
            expect(IDENTIFIER, it);
            this->set_index(it->get_value());
            ++it;
            expect(SEMICOLON, it);
            ++it;
        }
        else
            throw (std::runtime_error("not implemented token: \"" + it->get_value() + "\""));
    }
    expect(RBRACE, it);
    ++it;
}
