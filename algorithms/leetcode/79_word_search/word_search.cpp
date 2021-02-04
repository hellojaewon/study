#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

bool dfs (vector<vector<char>> & board, int row, int col, int x, int y, string & word, int cur, vector<vector<bool>> & visited) {
    if (cur >= word.size()) return true;
    if (x < 0 || x >= row) return false;
    if (y < 0 || y >= col) return false;

    if (visited[x][y]) return false;

    if (board[x][y] != word[cur])
        return false;

    visited[x][y] = true;
    bool found = dfs(board, row, col, x + 1, y, word, cur + 1, visited)
        || dfs(board, row, col, x - 1, y, word, cur + 1, visited)
        || dfs(board, row, col, x, y + 1, word, cur + 1, visited)
        || dfs(board, row, col, x, y - 1, word, cur + 1, visited);
    visited[x][y] = false;
    return found;
}

bool exist(vector<vector<char>>& board, string word) {
    int row = board.size();
    int col = board[0].size();
    vector<vector<bool>> visited;
    for (int i = 0; i < row; i++)
        visited.push_back(vector<bool>(col, false));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (dfs(board, row, col, i, j, word, 0, visited))
                return true;
        }
    }
    return false;
}

int main () {
    vector<vector<char>> b1;
    b1.push_back(vector<char>{'A','B','C','E'});
    b1.push_back(vector<char>{'S','F','C','S'});
    b1.push_back(vector<char>{'A','D','E','E'});
    assert(exist(b1, "ABCCED") == true);
    assert(exist(b1, "BA") == true);
    assert(exist(b1, "CE") == true);
    assert(exist(b1, "SEE") == true);

    return 0;
}
