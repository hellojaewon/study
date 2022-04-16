#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

bool palindrome(const string & s, int left, int right, bool deleted = false) {
    if (left == right)
        return true;

    while (left < right) {
        if (s[left] != s[right])
            break;
        left++;
        right--;
    }
    if (left < right) {
        if (deleted)
            return false;
        return palindrome(s, left, right - 1,  true) || palindrome(s, left + 1, right, true);
    }
    return true;
}

bool validPalindrome(string s) {
    return palindrome(s, 0, s.size()-1);
}

int main () {
    assert(validPalindrome("aba") == true);
    assert(validPalindrome("abca") == true);
    assert(validPalindrome("abc") == false);
    return 0;
}
