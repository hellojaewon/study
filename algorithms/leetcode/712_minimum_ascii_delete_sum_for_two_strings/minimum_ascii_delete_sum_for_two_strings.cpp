#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

using namespace std;

int dp (const string & s1, int i, const string & s2, int j, vector<vector<int>> & memo) {
    if (i == s1.size() && j == s2.size())
        return 0;

    if (i == s1.size()) {
        int sum = 0;
        while (j < s2.size())
            sum += s2[j++];
        return sum;
    }
    if (j == s2.size()) {
        int sum = 0;
        while (i < s1.size())
            sum += s1[i++];
        return sum;
    }

    if (memo[i][j] != -1)
        return memo[i][j];

    int sum = 0;
    if (s1[i] == s2[j])
        sum = dp(s1, i + 1, s2, j + 1, memo);
    else
        sum = min(s1[i] + dp(s1, i + 1, s2, j, memo), s2[j] + dp(s1, i, s2, j + 1, memo));

    memo[i][j] = sum;
    return sum;
}

int minimumDeleteSum(string s1, string s2) {
    vector<vector<int>> memo;
    for (int i = 0; i < s1.size(); i++)
        memo.push_back(vector<int>(s2.size(), -1));
    return dp(s1, 0, s2, 0, memo);
}

int main () {
    assert(minimumDeleteSum("sea", "eat") == 231);
    assert(minimumDeleteSum("delete", "leet") == 403);

    return 0;
}
