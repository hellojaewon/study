#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

void dfs (vector<vector<char>> & grid, int row, int col) {
    if (row < 0 || row >= grid.size()) return;
    if (col < 0 || col >= grid[0].size()) return;
    if (grid[row][col] == '0') return;

    grid[row][col] = '0';
    dfs(grid, row + 1, col);
    dfs(grid, row - 1, col);
    dfs(grid, row, col + 1);
    dfs(grid, row, col - 1);
}

int numIslands(vector<vector<char>>& grid) {
    int result = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == '1') {
                dfs(grid, i, j);
                result++;
            }
        }
    }
    return result;
}

void test1 () {
    vector<vector<char>> grid;
    grid.push_back({'1','1','1','1','0'});
    grid.push_back({'1','1','0','1','0'});
    grid.push_back({'1','1','0','0','0'});
    grid.push_back({'0','0','0','0','0'});
    assert(numIslands(grid) == 1);
}

void test2 () {
    vector<vector<char>> grid;
    grid.push_back({'1','1','0','0','0'});
    grid.push_back({'1','1','0','0','0'});
    grid.push_back({'0','0','1','0','0'});
    grid.push_back({'0','0','0','1','1'});
    assert(numIslands(grid) == 3);
}

int main () {
    test1();
    test2();

    return 0;
}
