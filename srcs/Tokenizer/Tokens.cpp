#include "../../headers/Tokenizer/Tokens.hpp"


Token::Token() : type(UNKNOWN) {}

Token::Token(const Token& other) { *this = other; }

Token& Token::operator=(const Token& other)
{
    this->type = other.type;
    this->value = other.value;
    return (*this);
}

Token::~Token() {}


Token::Token(t_token_type type, const std::string& value) : type(type), value(value) {}


t_token_type Token::get_type() const { return (this->type); }

const std::string& Token::get_value() const { return (this->value); }


void Token::set_type(t_token_type type) {this->type = type; }

void Token::set_value(const std::string& value) { this->value = value; }


// Token takes care of its own printing mechanics
static std::string get_type_string(t_token_type type)
{
    switch (type)
    {
        case UNKNOWN: return ("UNKNOWN");
        
        case IDENTIFIER: return ("IDENTIFIER");
        case NUMBER: return ("NUMBER");

        case SERVER: return ("SERVER");

        case LISTEN: return ("LISTEN");
        case SERVER_NAME: return ("SERVER_NAME");
        case LOCATION: return ("LOCATION");

        case ROOT: return ("ROOT");
        case INDEX: return ("INDEX");

        case LBRACE: return ("LBRACE");
        case RBRACE: return ("RBRACE");
        case SEMICOLON: return ("SEMICOLON");
    }
    return ("");
}

std::ostream& operator<<(std::ostream& os, const Token& token)
{
    t_token_type type = token.get_type();
    std::string type_str = get_type_string(type);
    
    os << type_str;
    if (type == IDENTIFIER)
        os << "(\"" << token.get_value() << "\")";
    else if (type == NUMBER)
        os << "(" << token.get_value() << ")";
    return (os);
}


// static void indent(std::ostream& os, int depth)
// {
//     for (int i = 0; i < depth; i++)
//         os << "    ";
// }

std::ostream& operator<<(std::ostream& os, const t_tokens& tokens)
{
    // bool put_indent = true;
    // int depth = 0;

    for (t_tokens::const_iterator it = tokens.begin(); it != tokens.end(); ++it)
    {
        t_token_type type = it->get_type();

        os << *it << " ";
        if (type == SEMICOLON)
            os << std::endl;


        // if (type == LBRACE)
        //     depth++;
        // else if (type == RBRACE)
        //     depth--;

        // if (put_indent) {
        //     indent(os, depth);
        //     put_indent = false;
        // }

        // if (type == LBRACE) {
        //     os << std::endl;
        //     indent(os, depth - 1);
        // }

        // os << *it << " ";

        // if (type == SEMICOLON || type == LBRACE || type == RBRACE) {
        //     put_indent = true;
        //     os << std::endl;
        // }
    }

    return (os);
}
