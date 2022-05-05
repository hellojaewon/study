#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

bool alphanumeric (char c) {
    return (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
}

bool isPalindrome(string s) {
    int left = 0;
    int right = s.size() - 1;
    int result = true;
    for (int i = 0 ; i < s.size(); i++)
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] = 'a' + (s[i] - 'A');
    while (left < right && result) {
        while (left < s.size()) {
            if (alphanumeric(s[left])) break;
            left++;
        }
        while (right >= 0) {
            if (alphanumeric(s[right])) break;
            right--;
        }
        if (left < right && s[left] != s[right])
            result = false;
        left++;
        right--;
    }
    return result;
}

int main () {
    assert(isPalindrome("A man, a plan, a canal: Panama") == true);
    assert(isPalindrome("race a car") == false);
    assert(isPalindrome(" ") == true);
    assert(isPalindrome(".,") == true);

    return 0;
}
