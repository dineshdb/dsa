#include "parser.hh"

using namespace std;

Parser::Parser(const char *i){
	input = i;
}

Token Parser::next(){
		Token t;
		// Skip whitespace
		while(*(input+i) ==' '  && input[i] != 0) i++;

		char ch = *(input + i);

		if(ch == 0){
			t.type = NONE;
		} else if(isOperator(ch)){
			t.type = OPERATOR;
			t.data = ch;
			i++;
		} else if( ch == '('){
			t.type = L_BRAC;
			i++;
		} else if( ch== ')'){
			t.type = R_BRAC;
			i++;
		} else if(isalpha(ch)){
			t.type = VARIABLE;
			t.data = ch;
			i++;
		} else if(isdigit(ch)){
			char num[80];
			for(int j=0; isdigit(input[i]); j++)
				num[j] = input[i++];
			t.type = NUMBER;
			t.data = atof(num);
		}

		return t;
}

vector<Token> Parser::parse(){
	vector<Token> res;
	stack<Token> s;

	for(;;){
		Token t = next();
		if(t.type == NONE){
			while(!s.empty()){
				Token o = s.top();
				s.pop();
				res.push_back(o);
			}

			// TODO add remaining data from stack to expr.
			break;
		}

		if(t.type == NUMBER)
			res.push_back(t);
		else if(t.type == VARIABLE)
			res.push_back(t);
		else if(t.type == OPERATOR){
			if(!s.empty() && isPriorityHigher(t.data, s.top().data)) {
				Token o = s.top();
				s.pop();
				res.push_back(o);
			}
			s.push(t);
		} else if(t.type == L_BRAC){
			s.push(t);
		} else if(t.type == R_BRAC){
			while(s.top().type != L_BRAC){
				Token o = s.top();
				s.pop();
				res.push_back(o);
			}
			s.pop();
		}
	}
	return res;
}

bool Parser::isPriorityHigher(char a, char b){
	switch(a){
		case '*':
		case '/':
			if(b == '/' || b =='*')
				break;
			return true;
	}
	return false;
}

bool Parser::isOperator(char ch){
	switch(ch){
		case '/':
		case '*':
		case '+':
		case '-':
			return true;
		default:
			return false;
	}
}
