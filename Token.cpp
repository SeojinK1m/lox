#include "Token.hpp"

template<typename T>
Token<T>::Token(TokenType type, std::string lexeme, T literal, int line)
{
    _type = type;
    _lexeme = lexeme;
    _literal = literal;
    _line = line;
}

template<typename T>
std::string Token<T>::toString()
{
    return std::to_string((int)_type);
}