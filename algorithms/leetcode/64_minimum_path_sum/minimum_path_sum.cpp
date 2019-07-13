#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

using namespace std;

int solve (vector<vector<int>> & grid, int x, int y, vector<vector<int>> & memo) {
    if (x >= grid.size()) return INT_MAX;
    if (y >= grid[0].size()) return INT_MAX;

    if (x == grid.size() - 1 && y == grid[0].size() - 1)
        return grid[x][y];

    if (memo[x][y] != INT_MAX)
        return memo[x][y];

    memo[x][y] = grid[x][y] + min(solve(grid, x+1, y, memo), solve(grid, x, y+1, memo));
    return memo[x][y];
}

int minPathSum(vector<vector<int>>& grid) {
    vector<vector<int>> memo;
    for (int i = 0; i < grid.size(); i++)
        memo.push_back(vector<int>(grid[0].size(), INT_MAX));

    return solve(grid, 0, 0, memo);
}

int main () {
    vector<vector<int>> grid;
    grid.push_back(vector<int>{1,3,1});
    grid.push_back(vector<int>{1,5,1});
    grid.push_back(vector<int>{4,2,1});
    cout<<minPathSum(grid)<<endl;
    assert(minPathSum(grid) == 7);
    return 0;
}
