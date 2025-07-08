#include <fstream>
#include <sstream>

#include "Tokenizer.hpp"

// TODO: send networking materials to N'Smart

int main()
{
    std::ifstream infile("test.conf");
    std::string s;
    std::stringstream ss;
    while (std::getline(infile, s))
        ss << s << std::endl;

    std::string config_str = ss.str();
    std::cout << "config_str:" << std::endl
              << config_str << std::endl;

    Tokenizer tokenizer;
    t_tokens tokens = tokenizer.tokenize(config_str);

    std::cout << "tokens:" << std::endl
              << tokens << std::endl;
   
    return (EXIT_SUCCESS);
}
