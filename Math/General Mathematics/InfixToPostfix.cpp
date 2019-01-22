/**
 *  Name: Infix To Postfix 
 *  Author Name: Sourav Hossain
 */

#include <bits/stdc++.h>

using namespace std;

int power(int, int);
bool isBalanced(string);
string convertInfixToPostfix(string);
int operatorPrecedence(char);
int evaluatePostfixExpression(string);
int calculate(int, int, char);

int main()
{
	string statement;

	cin >> statement;

	if(isBalanced(statement)) {
		puts("Sorry! Your statement is wrong!");
	} else {
	    cout << evaluatePostfixExpression(convertInfixToPostfix(statement)) << endl;	
	}

	return 0;
}

int power(int n, int p) {
	string binary = "";

	while(p) {
		(p & 1)? binary += "1" : binary += "0";
		p >>= 1;
	}

	int result = 1;

	for(int i = 0; binary[i]; i++) {
		result *= result;

		if(binary[i] == '1') {
			result *= n;
		}
	}

	return result;
} // end power function

bool isBalanced(string equation) {
	stack<char> myStack;

	for(int i = 0; equation[i]; i++) {
		if(equation[i] == '(') {
			myStack.push('(');
		} else if(equation[i] == ')') {
			if(myStack.empty()) {
				return false;
			} else {
				myStack.pop();
			}
		}
	}

	return (myStack.empty())? false : true;
} // end isBalanced function

string convertInfixToPostfix(string infix) {
	string postfix = "";
	stack<char> myStack;
	char ch;

	for(int i = 0; infix[i]; i++) {
		ch = infix[i];

		if(ch == '(') {
			myStack.push(ch);
		} else if(ch == ')') {
			while(!myStack.empty() && myStack.top() != '(') {
				postfix += myStack.top();
				myStack.pop();
			}

			if(!myStack.empty() && myStack.top() == '(') {
				myStack.pop();
			}
		} else {
			int priority = operatorPrecedence(ch);

			if(priority == 0) {
				postfix += ch;
			} else {
				if(myStack.empty()) {
					myStack.push(ch);
				} else {
					while(!myStack.empty() && myStack.top() != '(' && priority <= operatorPrecedence(myStack.top())) {
					    postfix += myStack.top();
					    myStack.pop();	
					}

					myStack.push(ch);
				}
			}
		}
	}

	while(!myStack.empty()) {
		postfix += myStack.top();
		myStack.pop();
	}

	return postfix;
} // end convertInfixToPostfix function

int operatorPrecedence(char ch) {
	switch(ch) {
		case '^':
		    return 3;
		    break;

		case '/':
		case '*':
		    return 2;
		    break;

		case '-':
		case '+':
		    return 1;
		    break;

		default:
		    return 0;
		    break;      
	}
} // end operatorPrecedence function

int evaluatePostfixExpression(string postfix) {
	stack<int> myStack;
	char ch;

	for(int i = 0; postfix[i]; i++) {
		ch = postfix[i];

		if(ch >= '0' && ch <= '9') {
			myStack.push(ch - '0');
		} else {
			int first, second;

			second = myStack.top();
			myStack.pop();

			first = myStack.top();
			myStack.pop();

			myStack.push(calculate(first, second, ch));
		}
	}

	return myStack.top();
} // end evaluatePostfixExpression function

int calculate(int first, int second, char operatorSign) {
	switch(operatorSign) {
		case '+':
		    return first + second;
		    break;

		case '-':
		    return first - second;
            break;

        case '*':
            return first * second;
            break;

        case '/':
            return first / second;
            break;

        case '^':
            return power(first, second);
            break;
	}
} // end calculate function 