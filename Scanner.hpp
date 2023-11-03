#include <iostream>
#include <string>
#include <vector>
#include "Token.hpp"

class Scanner
{
public:
    //  Constructor
    Scanner(std::string sourceCode);
    //  Scan the source code and extract a vector of tokens
    std::vector<Token> scanTokens();
private:
    std::string _sourceCode;
};