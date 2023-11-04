#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <any>
#include <memory>
#include "Token.hpp"

class Scanner
{
public:
    //  Constructor
    Scanner(std::string sourceCode, void (*error)(int, std::string));

    //  Scan the source code and extract a vector of tokens
    std::vector<std::shared_ptr<IToken>> scanTokens();

private:
    std::string _sourceCode;
    std::vector<std::shared_ptr<IToken>> tokens;
    std::string::iterator iterator;

    std::string::iterator start;
    int current;
    int line;

    std::function<void(int, std::string)> log;

    //  Scan a single token
    void scanToken();

    //  add token to tokens vector
    void addToken(TokenType type);
    void addStringToken(TokenType type, std::string value);

    //  match next character of lexeme
    bool match(char expected);

    //  get next character, but does not consume it. It does not move the iterator forwards.
    char peek();

    //  get the full number
    int number();
};