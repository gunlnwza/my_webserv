#include "../../headers/Parser/Tokenizer.hpp"


Tokenizer::Tokenizer() {}

Tokenizer::Tokenizer(const Tokenizer& other) { *this = other; }

Tokenizer& Tokenizer::operator=(const Tokenizer& other)
{
    this->tokens = other.tokens;
    return (*this);
}

Tokenizer::~Tokenizer() {}


static t_token_type get_token_type(const std::string& s)
{
    if (ft_is_number(s))
        return (NUMBER);

    const std::string values[] = {
        "server",
        "listen", "server_name", "location",
        "root", "index",
        "{", "}", ";"
    };
    const t_token_type types[] = {
        SERVER,
        LISTEN, SERVER_NAME, LOCATION,
        ROOT, INDEX,
        LBRACE, RBRACE, SEMICOLON,
    };
    size_t n = sizeof(values) / sizeof(values[0]);
    for (size_t i = 0; i < n; ++i)
    {
        if (s == values[i])
            return (types[i]);
    }

    return (IDENTIFIER);
}

void Tokenizer::flush_current_token()
{
    if (this->current_token.length() == 0)
        return ;

    this->tokens.push_back(Token(get_token_type(this->current_token), this->current_token));
    this->current_token = "";
}

t_tokens Tokenizer::tokenize(const std::string& config_str)
{
    for (size_t i = 0; i < config_str.length(); ++i)
    {
        char c = config_str[i];

        if (std::isspace(c))
        {
            this->flush_current_token();
        }
        else if (c == ';' || c == '{' || c == '}')
        {
            this->flush_current_token();
            this->current_token = c;
            this->flush_current_token();
        }
        else 
            this->current_token += c;
    }
    return (this->tokens);
}
