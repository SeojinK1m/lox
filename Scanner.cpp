#include "Scanner.hpp"

Scanner::Scanner(std::string sourceCode, void (*error)(int, std::string))
{
    _sourceCode = sourceCode;
    line = 1;
    start = sourceCode.begin();
    log = error;
}

std::vector<std::shared_ptr<IToken>> Scanner::scanTokens()
{
    for (iterator = _sourceCode.begin(); iterator != _sourceCode.end(); scanToken()) { }

    return tokens;
}

bool Scanner::match(char expected)
{
    if (iterator == _sourceCode.end()) 
    {
        return false;
    }

    if (*iterator != expected)
    {
        return false;
    }

    iterator++;
    return true;
}

char Scanner::peek()
{
    if (iterator == _sourceCode.end())
    {
        return '\0';
    }
    return *(iterator);
}

void Scanner::addToken(TokenType type)
{
    std::string::iterator leftIter = start;
    std::string::iterator rightIter = iterator;

    //  strip off the doublequotes
    if (type == TokenType::STRING)
    {
        leftIter++;
        rightIter--;
    }

    auto spToken = std::make_shared<Token<std::string>>(
        Token<std::string>(type, std::string(leftIter, rightIter), "", line)
        );
    tokens.push_back(spToken);
}

int Scanner::number()
{
    int val = 0;
    while (!isdigit(peek()) && iterator != _sourceCode.end())
    {
        val *= 10;
        val += (*iterator - '0');
        iterator++;
    }

    return val;
}

void Scanner::scanToken()
{
    start = iterator;
    //  get current character and then advance iterator
    char c = *(iterator++);

    //  tokenize lexemes
    switch (c)
    {
    case '(':
        addToken(TokenType::LEFT_PAREN);
        break;
    case ')':
        addToken(TokenType::RIGHT_PAREN);
        break;
    case '{':
        addToken(TokenType::LEFT_BRACE);
        break;
    case '}':
        addToken(TokenType::RIGHT_BRACE);
        break;
    case ',':
        addToken(TokenType::COMMA);
        break;
    case '.':
        addToken(TokenType::DOT);
        break;
    case '-':
        addToken(TokenType::MINUS);
        break;
    case '+':
        addToken(TokenType::PLUS);
        break;
    case ';':
        addToken(TokenType::SEMICOLON);
        break;
    case '*':
        addToken(TokenType::STAR);
        break;
    case '!':
        if (match('='))
        {
            addToken(TokenType::BANG_EQUAL);
        }
        else
        {
            addToken(TokenType::BANG);
        }
        break;
    case '<':
        if (match('='))
        {
            addToken(TokenType::LESS_EQUAL);
        }
        else
        {
            addToken(TokenType::LESS);
        }
        break;
    case '>':
        if (match('='))
        {
            addToken(TokenType::GREATER_EQUAL);
        }
        else
        {
            addToken(TokenType::GREATER);
        }
        break;
    case '=':
        if (match('='))
        {
            addToken(TokenType::EQUAL_EQUAL);
        }
        else
        {
            addToken(TokenType::EQUAL);
        }
        break;
    case '/':
        if (match('/'))
        {
            while (peek() != '\n' && iterator != _sourceCode.end())
            {
                iterator++;
            }
        }
        else
        {
            addToken(TokenType::SLASH);
        }
        break;
    case ' ':
        break;
    case '\r':
        break;
    case '\t':
        break;
    case '\n':
        line++;
        break;
    case '"':
        while (peek() != '"' && iterator != _sourceCode.end())
        {
            if (*iterator == '\n')
            {
                line++;
            }
            iterator++;
            std::cout << "'" << std::string(start, iterator) << "'";
        }

        if (iterator == _sourceCode.end())
        {
            log(line, "Unterminated string");
            return;
        }

        // skip over the second " to end the string
        iterator++;

        addToken(TokenType::STRING);
        break;
    default:
        if (isdigit(*iterator))
        {
            int n = number();
        }
        std::cout << "'" << c << "'" << std::endl;
        log(line, "Unexpected character.");
        break;
    }
}