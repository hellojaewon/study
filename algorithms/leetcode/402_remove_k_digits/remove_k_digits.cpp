#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

string removeKdigits(string num, int k) {
    string s;
    for (int i = 0; i < num.size(); i++) {
       while (s.size() && s[s.size() - 1] > num[i] && k) {
           s.pop_back();
           k--;
       }
       s.push_back(num[i]);
    }
    while (k--) s.pop_back();

    int i = 0;
    while (s[i] == '0') i++;
    string result = s.substr(i);
    return result.size() ? result : "0";
}

int main () {
    assert(removeKdigits("1432219", 3) == "1219");
    assert(removeKdigits("10200", 1) == "200");
    assert(removeKdigits("10", 2) == "0");
    return 0;
}
