

#include <iostream>
#include <stack>
#include "parser.hh"

using namespace std;

int main(){
	string symbol = "a+b*(c+g)+d";
	stack<Token> s;
	stack<Token> expr;

	Parser p(symbol.c_str());
	auto res = p.parse ();

	for(auto t : res){
		cout << t.type << " : " << t.data << endl;
	}

}
