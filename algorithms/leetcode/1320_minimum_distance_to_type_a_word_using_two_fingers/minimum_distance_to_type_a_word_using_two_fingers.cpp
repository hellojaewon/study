#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

int abs (int x) {
    return x >= 0  ? x : -x;
}

int distance (char a, char b) {
    int x = 'A'-a;
    int y = 'A'-b;
    return abs((x / 6) - (y / 6)) + abs((x % 6) - (y % 6));
}

int dp (const string & word, int current, int left, int right, vector<vector<int>> & memo) {
    if (current >= word.size())
        return 0;

    if (memo[left][right] != -1)
        return memo[left][right];

    if (left == word.size())
        memo[left][right] = dp(word, current + 1, current, right, memo);
    else if (right == word.size())
        memo[left][right] = min(distance(word[left], word[current]) + dp(word, current + 1, current, right, memo),
            dp(word, current + 1, left, current, memo));
    else {
        memo[left][right] = min(distance(word[left], word[current]) + dp(word, current + 1, current, right, memo),
               distance(word[right], word[current]) + dp(word, current + 1, left, current, memo));
    }

    return memo[left][right];
}

int minimumDistance(string word) {
    vector<vector<int>> memo;
    for (int i = 0; i < word.size() + 1; i++)
        memo.push_back(vector<int>(word.size() + 1, -1));
    return dp(word, 0, word.size(), word.size(), memo);
}

int main () {
    assert(minimumDistance("CAKE") == 3);
    assert(minimumDistance("HAPPY") == 6);
    assert(minimumDistance("NEW") == 3);
    assert(minimumDistance("YEAR") == 7);

    return 0;
}
