#include <algorithm>
#include <iostream>
#include <cassert>
#include <string>
#include <vector>

using namespace std;

std::string lcp (vector<string> & strs, int index) {
    for (auto & s : strs)
        if (s.size() < index)
            return "";

    char ch = strs[0][index];
    for (auto & s : strs)
        if (ch != s[index])
            return "";

    return ch + lcp(strs, index + 1);
}

string longestCommonPrefix(vector<string>& strs) {
    if (strs.size() == 0)
        return "";
    if (strs.size() == 1)
        return strs[0];
    return lcp(strs, 0);
}

int main () {
    std::vector<std::string> v1{"flower","flow","flight"};
    std::vector<std::string> v2{"dog","racecar","car"};
    std::vector<std::string> v3{};
    std::vector<std::string> v4{"test"};
    assert(longestCommonPrefix(v1) == "fl");
    assert(longestCommonPrefix(v2) == "");
    assert(longestCommonPrefix(v3) == "");
    assert(longestCommonPrefix(v4) == "test");
    return 0;
}
