#include "Scanner.hpp"

Scanner::Scanner(std::string sourceCode)
{
    _sourceCode = sourceCode;
}

std::vector<Token> Scanner::scanTokens()
{
    auto t1 = Token(TokenType::LEFT_PAREN, "(", "", 1);
    auto t2 = Token(TokenType::RIGHT_PAREN, ")", "", 1);

    std::vector<Token> tokens;
    tokens.push_back(t1);
    tokens.push_back(t2);

    std::string curToken;
    for (std::string::iterator it = _sourceCode.begin(); it != _sourceCode.end(); ++it) {
        char c = *it;

        //  Check if c is a single character token
        switch (c)
        {
        case '(':
            tokens.push_back(Token(TokenType::LEFT_PAREN, "(", "", 1));
            break;
        case ')':
            tokens.push_back(Token(TokenType::RIGHT_PAREN, ")", "", 1));
            break;
        case '{':
            tokens.push_back(Token(TokenType::LEFT_BRACE, "{", "", 1));
            break;
        case '}':
            tokens.push_back(Token(TokenType::RIGHT_BRACE, "}", "", 1));
            break;
        case ',':
            tokens.push_back(Token(TokenType::COMMA, ",", "", 1));
            break;
        case '.':
            tokens.push_back(Token(TokenType::DOT, ".", "", 1));
            break;
        case '-':
            tokens.push_back(Token(TokenType::MINUS, "-", "", 1));
            break;
        case '+':
            tokens.push_back(Token(TokenType::PLUS, "+", "", 1));
            break;
        case ';':
            tokens.push_back(Token(TokenType::SEMICOLON, ";", "", 1));
            break;
        case '*':
            tokens.push_back(Token(TokenType::STAR, "*", "", 1));
            break;
        default:
            break;
        }

    }

    return tokens;
}