#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int solve (vector<vector<char>> & matrix, int r, int c, vector<vector<int>> & cache) {
    if (r >= matrix.size() || c >= matrix[0].size()) return 0;
    if (cache[r][c] != -1) return cache[r][c];

    int right = solve(matrix, r + 1, c, cache);
    int down = solve(matrix, r, c + 1, cache);
    int diag = solve(matrix, r + 1, c + 1, cache);
    cache[r][c] = 0;
    if (matrix[r][c] == '1')
        cache[r][c] = min(min(right,down),diag) + 1;
    return cache[r][c];
}

int maximalSquareWithRecursion(vector<vector<char>>& matrix) {
    vector<vector<int>> cache;
    for (int i = 0; i < matrix.size(); i++)
        cache.push_back(vector<int>(matrix[0].size(), -1));
    solve(matrix, 0, 0, cache);

    int maxSide = 0;
    for (auto & m : cache)
        for (auto n : m)
            maxSide = max(maxSide, n);
    return maxSide * maxSide;
}


int maximalSquare(vector<vector<char>>& matrix) {
    int row = matrix.size();
    int col = matrix[0].size();

    int maxSide = 0;
    vector<vector<int>> dp;
    for (int i = 0; i < row; i++)
        dp.push_back(vector<int>(col, 0));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            dp[i][j] = matrix[i][j] == '1' ? 1 : 0;
            maxSide = max(maxSide, dp[i][j]);
        }
    }

    for (int i = row - 2; i >= 0; i--) {
        for (int j = col - 2; j >= 0; j--) {
            if (matrix[i][j] == '1')
                dp[i][j] = min(min(dp[i+1][j],dp[i][j+1]),dp[i+1][j+1]) + 1;
            maxSide = max(maxSide,dp[i][j]);
        }
    }
    return maxSide * maxSide;
}

void test1 () {
    vector<vector<char>> matrix;
    matrix.push_back(vector<char>{'1','0','1','0','0'});
    matrix.push_back(vector<char>{'1','0','1','1','1'});
    matrix.push_back(vector<char>{'1','1','1','1','1'});
    matrix.push_back(vector<char>{'1','0','0','1','0'});
    assert(maximalSquare(matrix) == 4);
}

void test2 () {
    vector<vector<char>> matrix;
    matrix.push_back(vector<char>{'0','1'});
    matrix.push_back(vector<char>{'1','0'});
    assert(maximalSquare(matrix) == 1);
}

void test3 () {
    vector<vector<char>> matrix;
    matrix.push_back(vector<char>{'0'});
    assert(maximalSquare(matrix) == 0);
}

int main () {
    test1();
    test2();
    test3();

    return 0;
}
