#ifndef TOKENIZER_HPP
# define TOKENIZER_HPP

# include "Tokens.hpp"
# include "../utils/ft_utils.hpp"

class Tokenizer
{
    private:
        t_tokens tokens;
        std::string current_token;

        void flush_current_token();

    public:
        Tokenizer();
        Tokenizer(const Tokenizer& other);
        Tokenizer& operator=(const Tokenizer& other);
        ~Tokenizer();

        t_tokens tokenize(const std::string& config_str);
};

#endif
