#include "TokenType.hpp"
#include <string>

class IToken {
public:
    virtual ~IToken() {}
    virtual std::string toString() = 0;
};

template<typename T>
class Token : public IToken {
public:
    Token(TokenType type, std::string lexeme, T literal, int line);
    std::string toString() override;
private:
    TokenType _type;
    std::string _lexeme;
    T _literal;
    int _line;
};