#ifndef PARSER_HH
#define PARSER_HH

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <ctype.h>
#include <stdlib.h>

using namespace std;

enum TokenType {
	NUMBER,
	OPERATOR,
	VARIABLE,
	L_BRAC,
	R_BRAC,
	NONE
};
struct Token{
	TokenType type;
	int data;
};


class Parser{
	const char *input;
	std::string ops ="+-/*";
	int i=0;

public:
	Parser(const char *i);
	Token next();
	vector<Token> parse();
	bool isPriorityHigher(char a, char b);
	bool isOperator(char ch);
};

#endif
