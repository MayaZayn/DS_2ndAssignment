#include<iostream>
#include "Stack.h"
#include "Stack.cpp"

using namespace std;

string InfixToPostfix(const string& infix) {
    Stack<char> stack;
    string output;
    for (char ch: infix) {
        if (!isspace(ch)) {
            if (isalpha(ch) || isdigit(ch)) {
                output += ch;
            } else if (ch == '(') {
                stack.push(ch);
            } else if (ch == ')') {
                while (stack.top() != '(') {
                    output += stack.top();
                    stack.pop();
                }
                stack.pop();
            } else {
                if (ch == '+' || ch == '-') {
                    while (!stack.isEmpty() && stack.top() != '(') {
                        output += stack.top();
                        stack.pop();
                    }
                    stack.push(ch);
                } else if (ch == '*' || ch == '/') {
                    while (!stack.isEmpty() && stack.top() != '+'
                           && stack.top() != '-' && stack.top() != '(') {
                        output += stack.top();
                        stack.pop();
                    }
                    stack.push(ch);
                } else if (ch == '^') {
                    while (!stack.isEmpty() && stack.top() == '^') {
                        output += stack.top();
                        stack.pop();
                    }
                    stack.push(ch);
                }
            }
        }
    }
    while (!stack.isEmpty()) {
        output += stack.top();
        stack.pop();
    }
    return output;
}

int main() {
    string s = "2+4/5*(5-3)^5^4";
    cout << InfixToPostfix(s);
}
