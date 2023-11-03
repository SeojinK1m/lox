#include "Token.hpp"

Token::Token(TokenType type, std::string lexeme, std::string literal, int line)
{
    _type = type;
    _lexeme = lexeme;
    _literal = literal;
    _line = line;
}

std::string Token::toString()
{
    return _lexeme;
}