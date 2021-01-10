#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int dp (int i, int j, int m, int n, vector<vector<int>> & memo) {
    if (i == m - 1 && j == n - 1)
        return 1;

    if (i >= m)
        return 0;
    if (j >= n)
        return 0;

    if (!memo[i][j])
        memo[i][j] = dp(i+1, j, m, n, memo) + dp(i, j+1, m, n, memo);
    return memo[i][j];
}

int uniquePaths(int m, int n) {
    vector<vector<int>> memo(m, vector<int>(n,0));
    return dp(0, 0, m, n, memo);
}

int main () {
    assert(uniquePaths(3, 7) == 28);
    assert(uniquePaths(3, 2) == 3);
    return 0;
}
