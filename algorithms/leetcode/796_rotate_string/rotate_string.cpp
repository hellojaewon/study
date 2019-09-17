#include <iostream>
#include <string>
#include <cassert>

using namespace std;

bool rotateString(string A, string B) {
    if (A.size() != B.size()) return false;

    string tmp = A + A;
    return tmp.find(B) != string::npos;
}

int main () {
    assert(rotateString("abcde", "cdeab"));
    assert(!rotateString("abcde", "abced"));
    assert(!rotateString("aa", "a"));
    return 0;
}
