#include <iostream>
#include <vector>
#include <string>

// Common base class
class IToken {
public:
    virtual ~IToken() {}
    virtual void print() const = 0;
};

// Derived classes for specific literal types
template <typename T>
class Token : public IToken {
public:
    Token(const T& value) : value(value) {}

    void print() const override {
        std::cout << "Value: " << value << std::endl;
    }

private:
    T value;
};

int main() {
    std::vector<IToken*> tokens;

    tokens.push_back(new Token<int>(42));
    tokens.push_back(new Token<std::string>("Hello, world"));

    for (const auto token : tokens) {
        token->print();
        delete token; // Don't forget to free memory
    }

    return 0;
}