#include <iostream>
#include <vector>
#include <queue>
#include <cassert>

using namespace std;

void dfs (int i, int j, int n, vector<vector<int>> & grid, queue<pair<int,int>> & q, vector<vector<bool>> & visited) {
    if (i < 0 || i >= n) return;
    if (j < 0 || j >= n) return;
    if (grid[i][j] == 0) return;
    if (visited[i][j]) return;

    visited[i][j] = true;
    q.push(make_pair(i,j));
    dfs(i + 1, j, n, grid, q, visited);
    dfs(i - 1, j, n, grid, q, visited);
    dfs(i, j + 1, n, grid, q, visited);
    dfs(i, j - 1, n, grid, q, visited);
}

bool search (int i, int j, int n, vector<vector<int>> & grid, queue<pair<int,int>> & q, vector<vector<bool>> & visited) {
    if (i < 0 || i >= n) return false;
    if (j < 0 || j >= n) return false;
    if (visited[i][j]) return false;
    visited[i][j] = true;
    if (grid[i][j]) return true;
    q.push(make_pair(i,j));
    return false;
}

int shortestBridge(vector<vector<int>>& grid) {
    vector<vector<bool>> visited;
    int n = grid.size();
    for (int i = 0; i < n; i++)
        visited.push_back(vector<bool>(n, false));

    queue<pair<int,int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 0) continue;
            dfs(i, j, n, grid, q, visited);
            break;
        }
        if (!q.empty()) break;
    }

    int smallest = 0;
    bool found = false;
    while (!q.empty()) {
        int s = q.size();
        for (int i = 0; i < s; i++) {
            auto next = q.front(); q.pop();
            if (   search(next.first + 1, next.second, n, grid, q, visited)
                || search(next.first - 1, next.second, n, grid, q, visited)
                || search(next.first, next.second + 1, n, grid, q, visited)
                || search(next.first, next.second - 1, n, grid, q, visited)
            ) {
                found = true;
                break;
            }
        }
        if (found) break;
        smallest++;
    }
    return smallest;
}

void test1 () {
    vector<vector<int>> grid;
    grid.push_back(vector<int>{0,1,0});
    grid.push_back(vector<int>{0,0,0});
    grid.push_back(vector<int>{0,0,1});
    assert(shortestBridge(grid) == 2);
}

void test2 () {
    vector<vector<int>> grid;
    grid.push_back(vector<int>{1,1,1,1,1});
    grid.push_back(vector<int>{1,0,0,0,1});
    grid.push_back(vector<int>{1,0,1,0,1});
    grid.push_back(vector<int>{1,0,0,0,1});
    grid.push_back(vector<int>{1,1,1,1,1});
    assert(shortestBridge(grid) == 1);
}

int main () {
    test1();
    test2();
    return 0;
}
