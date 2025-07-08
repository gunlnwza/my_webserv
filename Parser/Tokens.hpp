#ifndef TOKENS_HPP
# define TOKENS_HPP

# include <iostream>

enum e_token_type {
    UNKNOWN,
    IDENTIFIER, NUMBER,
    SERVER,
    LISTEN, SERVER_NAME, LOCATION,  // server level
    ROOT, INDEX,  // route level
    LBRACE, RBRACE, SEMICOLON,  // meta-chars
};

typedef enum e_token_type t_token_type;

class Token
{
    private:
        t_token_type type;
        std::string value;

    public:
        Token();
        Token(const Token& other);
        Token& operator=(const Token& other);
        ~Token();

        Token(t_token_type type, const std::string& value);

        t_token_type get_type() const;
        const std::string& get_value() const;

        void set_type(t_token_type type);
        void set_value(const std::string& value);
};

std::ostream& operator<<(std::ostream& os, const Token& token);

#endif
