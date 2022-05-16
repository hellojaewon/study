#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int characterReplacement(string s, int k) {
    vector<int> t(26, 0);

    int result = 0;
    int left = 0;
    int maxValue = 0;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        t[c-'A']++;
        maxValue = max(maxValue, t[c-'A']);
        int window = i - left + 1;
        if (window - maxValue <= k)
            result = max(result, window);
        else {
            t[s[left]-'A']--;
            left++;
        }
    }
    return result;
}

int main () {
    assert(characterReplacement("ABAB", 2) == 4);
    assert(characterReplacement("AABABBA", 1) == 4);

    return 0;
}
