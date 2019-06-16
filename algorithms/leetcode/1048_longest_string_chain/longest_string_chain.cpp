#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

using namespace std;

bool contains (const string & s1, const string & s2) {
    assert(s1.size() + 1 == s2.size());
    int i = 0;
    int j = 0;
    while (i < s1.size() && j < s2.size()) {
        if (s1[i] == s2[j]) {
            i++;
            j++;
        } else {
            j++;
        }
    }
    if (i == s1.size() && j <= s2.size())
        return true;
    return false;
}

int solve (int index, vector<string> & words, vector<int> & memo) {
    if (memo[index])
        return memo[index];

    int max = 1;
    for (int i = 0; i < words.size(); i++) {
        if ((words[index].size() + 1) != words[i].size())
            continue;
        if (contains(words[index], words[i])) {
            int res = 1 + solve(i, words, memo);
            if (res > max)
                max = res;
        }
    }

    memo[index] = max;
    return max;
}

int longestStrChain(vector<string>& words) {
    vector<int> memo(words.size(), 0);
    for (int i = 0; i < words.size(); i++)
        solve(i, words, memo);

    return *max_element(memo.begin(), memo.end());
}

int main () {
    vector<string> words1{"a","b","ba","bca","bda","bdca"};
    assert(longestStrChain(words1) == 4);
    vector<string> words2{"ksqvsyq","ks","kss","czvh","zczpzvdhx","zczpzvh","zczpzvhx","zcpzvh","zczvh","gr","grukmj","ksqvsq","gruj","kssq","ksqsq","grukkmj","grukj","zczpzfvdhx","gru"};
    assert(longestStrChain(words2) == 7);
    return 0;
}
