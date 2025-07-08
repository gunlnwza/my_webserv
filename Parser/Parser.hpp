#ifndef PARSER_HPP
# define PARSER_HPP

# include "../Config/WebServerConfig.hpp"
# include "Tokenizer.hpp"

bool is_grammar_correct(t_tokens& tokens);

WebServerConfig parse_tokens(t_tokens& tokens);

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
