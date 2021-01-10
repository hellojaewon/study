#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

int dp (const string & word1, const string & word2, int i, int j, vector<vector<int>> & memo) {
    if (i >= word1.size() && j >= word2.size())
        return 0;

    if (i >= word1.size())
        return word2.size() - j;

    if (j >= word2.size())
        return word1.size() - i;

    if (memo[i][j] != -1)
        return memo[i][j];

    if (word1[i] == word2[j])
        memo[i][j] = dp(word1, word2, i + 1, j + 1, memo);
    else {
        int inserted = dp(word1, word2, i, j + 1, memo);
        int deleted = dp(word1, word2, i + 1, j, memo);
        int replaced = dp(word1, word2, i + 1, j + 1, memo);
        int m = min(inserted, deleted);
        memo[i][j] = 1 + min(m, replaced);
    }
    return memo[i][j];
}

int minDistance(string word1, string word2) {
    vector<vector<int>> memo(word1.size(), vector<int>(word2.size(), -1));
    return dp(word1, word2, 0, 0, memo);
}

int main () {
    assert(minDistance("horse", "ros") == 3);
    assert(minDistance("intention", "execution") == 5);
    return 0;
}
