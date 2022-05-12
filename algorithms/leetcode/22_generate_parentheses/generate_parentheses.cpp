#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

void solve (vector<string> & result, string & str, string & s, int open, int close) {
    if (open == 0 && close == 0) {
        result.push_back(s);
        return;
    }

    if (open) {
        s.push_back('(');
        solve(result, str, s, open - 1, close);
        s.pop_back();
    }
    if (close > open) {
        s.push_back(')');
        solve(result, str, s, open, close - 1);
        s.pop_back();
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> result;
    string str;
    string s;
    solve(result, str, s, n, n);
    return result;
}

int main () {
    auto result = generateParenthesis(3);
    assert(result.size() == 5);
    result = generateParenthesis(1);
    assert(result.size() == 1);

    return 0;
}
