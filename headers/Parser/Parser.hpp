#ifndef PARSER_HPP
# define PARSER_HPP

# include "Tokenizer.hpp"
# include "../Config/WebServerConfig.hpp"

typedef t_tokens::const_iterator t_tokens_const_it;

// bool is_grammar_correct(const t_tokens& tokens);

WebServerConfig parse_tokens(const t_tokens& tokens);

// class Parser
// {
//     private:
    
//     public:
//         Parser();
//         Parser(const Parser& other);
//         Parser& operator=(const Parser& other);
//         ~Parser();
// };

#endif
