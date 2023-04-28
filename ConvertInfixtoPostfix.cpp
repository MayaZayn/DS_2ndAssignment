#include<iostream>
#include "Stack.h"
#include "Stack.cpp"

using namespace std;

string ConvertInfixtoPosfix(string infix) {
    Stack<char> stack;
    string output;
    int cnt = 0;
    for (char ch: infix) {
        if (ch != '\0') {
            if (isalpha(ch) || isdigit(ch)) {
                output += ch;
                cnt++;
            }
            if (ch == '+' || ch == '-') {
                if (stack.isEmpty()) {
                    stack.push(ch);
                    cnt++;
                } else {
//                    if(stack.top()=='('){
//                        stack.push(ch);
//                        cnt++;
//                    }

                    while (stack.stackSize() && stack.top() != '(') {
                        output += stack.top();
                        stack.pop();
                    }

                    stack.push(ch);

                }
            } else if (ch == '*' || ch == '/') {
                if (stack.isEmpty()) {
                    stack.push(ch);
                    cnt++;
                } else if (stack.top() == '+' || stack.top() == '-' || stack.top() == '(') {
                    stack.push(ch);
                } else {
                    while (stack.stackSize()) {
                        output += stack.top();
                        stack.pop();
                    }
                    stack.push(ch);
                }
            } else if (ch == '^') {
                if (stack.isEmpty()) {
                    stack.push(ch);
                    cnt++;
                } else if (stack.top() == '+' || stack.top() == '-' || stack.top() == '*' || stack.top() == '/' ||
                           stack.top() == '(') {
                    stack.push(ch);
                } else {
                    while (stack.stackSize()) {
                        output += stack.top();
                        stack.pop();
                    }
                    stack.push(ch);
                }
            } else if (ch == '(') {
                stack.push(ch);
                cnt++;
            } else if (ch == ')') {
                output += stack.top();
                stack.pop();
                stack.pop();
            }
        }
    }
    output += stack.top();
    cout << output;
    return output;
}

int main() {
    string x="x^y / (5*z) + 2";
    ConvertInfixtoPosfix(x);

}
