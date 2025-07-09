#include "../../headers/Parser/Parser.hpp"

// static bool is_braces_balanced(const t_tokens& tokens)
// {
//     int depth = 0;
//     for (t_tokens::const_iterator it = tokens.begin(); it != tokens.end(); ++it)
//     {
//         t_token_type type = it->get_type();
//         if (type == LBRACE)
//             depth++;
//         else if (type == RBRACE)
//             depth--;
//         if (depth < 0)
//             return (false);
//     }
//     return (depth == 0);
// }

// bool is_grammar_correct(const t_tokens& tokens)
// {
//     if (!is_braces_balanced(tokens))
//         return (false);
//     return (true);
// }

bool token_is(t_token_type type, const t_tokens_const_it& it)
{
    return (type == it->get_type());
}

bool next_token_is(t_token_type type, const t_tokens_const_it& it)
{
    return (token_is(type, it + 1));
}

void expect(t_token_type type, const t_tokens_const_it& it)
{
    if (!token_is(type, it))
    {
        std::cout << "Unexpected token: " << *it << std::endl;
        throw (std::runtime_error("found unexpected token"));
    }
}



ServerConfig parse_server(t_tokens_const_it& it, const t_tokens_const_it& it_end)
{
    ServerConfig s;

    std::cout << "parse_server" << std::endl;
    expect(SERVER, it);
    ++it;
    expect(LBRACE, it);
    ++it;
    while (it != it_end && !token_is(RBRACE, it))
    {
        if (token_is(LISTEN, it))
        {
            std::cout << "parse_listen" << std::endl;
            ++it;
            expect(NUMBER, it);
            s.listen = it->get_value();
        }
        else if (token_is(SERVER_NAME, it))
        {
            std::cout << "parse_server_name" << std::endl;
            ++it;
            expect(IDENTIFIER, it);
            s.server_name = it->get_value();
        }
        // else if (token_is)
        ++it;
    }
    expect(RBRACE, it);
    ++it;
    return (s);
}

WebServerConfig parse_tokens(const t_tokens& tokens)
{
    WebServerConfig ws;
    ServerConfig s;

    t_tokens::const_iterator it = tokens.begin();
    t_tokens::const_iterator it_end = tokens.end();
    while (it != it_end)
    {
        s = parse_server(it, it_end);
        ws.add_server_config(s);
        ++it;
    }
    return (ws);
}
