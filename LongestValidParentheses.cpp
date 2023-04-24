#include <iostream>
using namespace std;
#include "Stack.h"
#include "Stack.cpp"

int longestValidParentheses(string s) {
    Stack<char> stack;
    int ans = 0, cur = 0;
    for (char c: s) {
        if (c == '(') {
            stack.push(c);
        } else if (c == ')' && !stack.isEmpty()) {
            stack.pop();
            cur += 2;
        } else {
            ans = max(ans, cur);
            cur = 0;
        }
    }
    ans = max(ans, cur);
    return ans;
}

int main() {
    string s;
    cin >> s;

    cout << longestValidParentheses(s);

    return 0;
}
