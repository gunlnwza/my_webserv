#include <fstream>
#include <sstream>

#include "../../headers/Config/WebServerConfig.hpp"

// TODO: send networking materials to N'Smart

int main()
{
    
    std::string config_str = ss.str();
    std::cout << "config_str:" << std::endl
              << config_str << std::endl;

    std::cout << "[ Tokenize ]" << std::endl;
    Tokenizer tokenizer;
    t_tokens tokens = tokenizer.tokenize(config_str);
    std::cout << "tokens:" << std::endl
              << tokens << std::endl;

    std::cout << "[ Parsing Tokens ]" << std::endl;
    WebServerConfig config;
    try {
        config.parse_config(config_str);
    } catch (const std::runtime_error& e) {
        std::cout << "Error: " << e.what() << std::endl;
        return (EXIT_FAILURE);
    }
    std::cout << "config: " << std::endl
              << config << std::endl;

    return (EXIT_SUCCESS);
}
