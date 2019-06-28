#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

int dfs (vector<vector<int>> & grid, int row, int col) {
    if (row < 0 || row >= grid.size()) return 0;
    if (col < 0 || col >= grid[0].size()) return 0;
    if (grid[row][col] == 0) return 0;

    grid[row][col] = 0;
    return 1 + dfs(grid, row-1, col) + dfs(grid, row+1, col)
             + dfs(grid, row, col-1) + dfs(grid, row, col+1);
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    int max = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            int cur = 0;
            if (grid[i][j] == 1)
                cur = dfs(grid, i, j);
            if (cur > max)
                max = cur;
        }
    }
    return max;
}

int main () {
    vector<vector<int>> grid;
    assert(maxAreaOfIsland(grid) == 0);
    grid.push_back(vector<int>{0,0,1,0,0,0,0,1,0,0,0,0,0});
    grid.push_back(vector<int>{0,0,0,0,0,0,0,1,1,1,0,0,0});
    grid.push_back(vector<int>{0,1,1,0,1,0,0,0,0,0,0,0,0});
    grid.push_back(vector<int>{0,1,0,0,1,1,0,0,1,0,1,0,0});
    grid.push_back(vector<int>{0,1,0,0,1,1,0,0,1,1,1,0,0});
    grid.push_back(vector<int>{0,0,0,0,0,0,0,0,0,0,1,0,0});
    grid.push_back(vector<int>{0,0,0,0,0,0,0,1,1,1,0,0,0});
    grid.push_back(vector<int>{0,0,0,0,0,0,0,1,1,0,0,0,0});
    assert(maxAreaOfIsland(grid) == 6);
    return 0;
}
