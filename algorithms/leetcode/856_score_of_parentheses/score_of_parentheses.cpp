#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <cassert>

using namespace std;

int scoreOfParentheses(string S) {
    stack<int> n;
    stack<char> c;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == '(')
            c.push(S[i]);
        else {
            char top = c.top();
            c.pop();
            if (top == '(') {
                c.push('*');
                n.push(1);
            } else {
                assert(top == '*');
                int sum = 0;
                while (top == '*') {
                    sum += n.top();
                    n.pop();
                    top = c.top();
                    c.pop();
                }
                sum *= 2;
                c.push('*');
                n.push(sum);
            }
        }
    }

    int score = 0;
    while (!n.empty()) {
        score += n.top();
        n.pop();
    }

    return score;
}

int main () {
    assert(scoreOfParentheses("()") == 1);
    assert(scoreOfParentheses("(())") == 2);
    assert(scoreOfParentheses("()()") == 2);
    assert(scoreOfParentheses("(()(()))") == 6);
    return 0;
}

