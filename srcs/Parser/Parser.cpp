#include "../../headers/Parser/Parser.hpp"

static bool is_braces_balanced(const t_tokens& tokens)
{
    int depth = 0;
    for (t_tokens::const_iterator it = tokens.begin(); it != tokens.end(); ++it)
    {
        t_token_type type = it->get_type();
        if (type == LBRACE)
            depth++;
        else if (type == RBRACE)
            depth--;
        if (depth < 0)
            return (false);
    }
    return (depth == 0);
}

bool is_grammar_correct(const t_tokens& tokens)
{
    if (!is_braces_balanced(tokens))
        return (false);
    return (true);
}

// assume everything is correct
WebServerConfig parse_tokens(const t_tokens& tokens)
{
    WebServerConfig web_server_config;
    ServerConfig server_config;
    RouteConfig route_config;

    // int depth = 0;

    for (t_tokens::const_iterator it = tokens.begin(); it != tokens.end(); ++it)
    {

    }

    return (web_server_config);
}
