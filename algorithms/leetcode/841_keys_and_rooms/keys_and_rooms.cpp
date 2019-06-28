#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

void dfs (vector<vector<int>> & rooms, int n, vector<bool> & visited) {
    if (visited[n])
        return;

    visited[n] = true;
    for (int i = 0; i < rooms[n].size(); i++)
        dfs(rooms, rooms[n][i], visited);
}

bool canVisitAllRooms(vector<vector<int>>& rooms) {
    vector<bool> visited(rooms.size(), false);
    dfs(rooms, 0, visited);
    return all_of(visited.begin(), visited.end(), [](bool b) { return b; });
}

int main () {
    vector<vector<int>> rooms1;
    rooms1.push_back(vector<int>{1});
    rooms1.push_back(vector<int>{2});
    rooms1.push_back(vector<int>{3});
    rooms1.push_back(vector<int>{});
    assert(canVisitAllRooms(rooms1));

    vector<vector<int>> rooms2;
    rooms2.push_back(vector<int>{1,3});
    rooms2.push_back(vector<int>{3,0,1});
    rooms2.push_back(vector<int>{2});
    rooms2.push_back(vector<int>{0});
    assert(!canVisitAllRooms(rooms2));
    return 0;
}
