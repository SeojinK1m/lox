lox: lox.o Scanner.o Token.o
	g++ lox.o Scanner.o Token.o -o lox

lox.o: lox.cpp

Scanner.o: Scanner.cpp Scanner.hpp Token.o

Token.o: Token.cpp Token.hpp TokenType.hpp

clean:
	rm *.o lox
