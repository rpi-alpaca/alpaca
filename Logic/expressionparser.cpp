#include <cctype>
#include <string>
#include <queue>
#include <stack>

bool isOperator(char token) {
    if (token == '&' 
        || token == '|' 
        || token == '@'
        || token == '(' 
        || token == ')') {
        return true;
    }
    return false;
}
int precedence(char op) {
    if (op == '(' || op == ')') {return 0;}
    if (op == '&') {
        return 3;
    }
    if (op == '|' || op == '@') {
        return 2;
    }
    return -1; //temp
}
std::string read_token(std::string str) {
    std::queue<char> outQ;
    std::stack<char> opS;
    while (str.size()) {
        char token = str[0];
        str = str.substr(1, str.size());
        if (std::isalpha(token)) {
            outQ.push(token);
        }
        if (isOperator(token)) {
            while ((precedence(opS.top()) >= precedence(token)) && (opS.top() != '(')) {
                outQ.push(opS.top());
                opS.pop();
                opS.push(token);
            }
        }
        if (opS.top() == '(') {
            opS.push(token);
        }
        if (opS.top() == ')') {
            while (opS.top() != '(') {
                outQ.push(opS.top());
                opS.pop();
            }
            /* if the stack runs out without finding a left paren, then there are mismatched parentheses. */
            if (opS.top() == '(') {
                opS.pop();
            }
        }
    }
    while (opS.size() != 0) {
        outQ.push(opS.top());
        opS.pop();
    }
    std::string outS;
    while (outQ.size() != 0) {
        outS += outQ.front();
        outQ.pop();
    }
    return outS; //temp
}
bool calculate(std::string input) {
	return false; //temp;
}