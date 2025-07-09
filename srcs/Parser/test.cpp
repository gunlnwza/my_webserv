#include <fstream>
#include <sstream>

#include "../../headers/Parser/Tokenizer.hpp"
#include "../../headers/Parser/Parser.hpp"

// TODO: send networking materials to N'Smart

int main()
{
    std::cout << "[ Loading config file ]" << std::endl;
    std::ifstream infile("test.conf");
    std::string s;
    std::stringstream ss;
    while (std::getline(infile, s))
        ss << s << std::endl;

    std::string config_str = ss.str();
    std::cout << "config_str:" << std::endl
              << config_str << std::endl;

    std::cout << "[ Tokenize ]" << std::endl;
    Tokenizer tokenizer;
    t_tokens tokens = tokenizer.tokenize(config_str);

    std::cout << "tokens:" << std::endl
              << tokens << std::endl;

    std::cout << "[ Check Grammar ]" << std::endl;
    if (!is_grammar_correct(tokens))
    {
        std::cout << "Grammar Error: grammar not correct" << std::endl;
        return (EXIT_FAILURE);
    }
    std::cout << std::endl;

    std::cout << "[ Parsing Tokens ]" << std::endl;
    WebServerConfig config;
    try {
        config = parse_tokens(tokens);
    } catch (const std::runtime_error& e) {
        std::cout << "Parsing Error: " << e.what() << std::endl;
        return (EXIT_FAILURE);
    }

    return (EXIT_SUCCESS);
}
