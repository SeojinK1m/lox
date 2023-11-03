#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "Scanner.hpp"

enum Errors {
    NoError,
    FileNotFound,
};

//  run sourcecode
int run(std::string sourceCode) {
    Scanner scanner(sourceCode);
    std::vector<Token> tokens = scanner.scanTokens();
    for (Token token : tokens) {
        std::cout << token.toString() << std::endl;
    }
}

//  report error
void report(int line, std::string where, std::string message) {
    std::cout << "[line " << line << "] Error" << where << ": " << message << std::endl;
}

//  Error handling
void error(int line, std::string message) {
    report(line, "", message);
}

//  Global variable to keep track of whether there was an error while interpreting
bool hadError = false;

//  run sourcecode from path to file
int runFile(std::string path) {
    std::cout << "Running file: " << path << std::endl;
    std::ifstream sourceCode(path);
    if (!sourceCode) {
        std::cout << "Could not open file: " << path << std::endl;
        return Errors::FileNotFound;
    }

    //  Read file into string
    std::stringstream buffer;
    buffer << sourceCode.rdbuf();
    std::string sourceCodeString = buffer.str();

    //  Run code
    hadError = ( run(sourceCodeString) == Errors::NoError );
    if (hadError) {
        return 65;
    }
}

void runPrompt() {
    std::cout << "Running prompt" << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc > 2) {
        std::cout << "Usage: jlox [script]" << std::endl;
        return 64;
    } else if (argc == 2) {
        runFile(argv[1]);
    } else {
        runPrompt();
    }
    std::cout << "Hello, World!" << std::endl;
}