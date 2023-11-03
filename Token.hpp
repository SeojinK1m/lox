#include "TokenType.hpp"
#include <string>

class Token {
public:
    Token(TokenType type, std::string lexeme, std::string literal, int line);
    std::string toString();
private:
    TokenType _type;
    std::string _lexeme;
    std::string _literal;
    int _line;
};