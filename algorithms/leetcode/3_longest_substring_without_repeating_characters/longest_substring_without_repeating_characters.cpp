#include <iostream>
#include <vector>
#include <unordered_set>
#include <cassert>

using namespace std;

int lengthOfLongestSubstringOld(string s) {
    if (s.size() == 0) return 0;

    vector<int> t(256, -1);

    int result = 0;
    int start = 0;
    for (int i = 0; i < s.size(); i++) {
        int cur = s[i];
        if (t[cur] == -1 || t[cur] < start)
            t[cur] = i;
        else {
            result = max(result, i - start);
            start = t[cur] + 1;
            t[cur] = i;
        }
    }
    result = max(result, t[s[s.size()-1]] - start + 1);
    return result;
}

int lengthOfLongestSubstring(string s) {
    unordered_set<char> t;
    int left = 0;
    int result = 0;
    for (int i = 0; i < s.size(); i++) {
        while (t.find(s[i]) != t.end())
            t.erase(s[left++]);
        t.insert(s[i]);
        result = max(result, i - left + 1);
    }
    return result;
}

int main () {
    assert(lengthOfLongestSubstring("") == 0);
    assert(lengthOfLongestSubstring(" ") == 1);
    assert(lengthOfLongestSubstring("aab") == 2);
    assert(lengthOfLongestSubstring("abcabcbb") == 3);
    assert(lengthOfLongestSubstring("bbbbb") == 1);
    assert(lengthOfLongestSubstring("pwwkew") == 3);

    return 0;
}
