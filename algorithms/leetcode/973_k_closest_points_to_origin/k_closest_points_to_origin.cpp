#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cassert>
#include <map>

using namespace std;

vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    multimap<int, vector<int>> table;
    for (auto & p : points)
        table.insert(make_pair(p[0]*p[0]+p[1]*p[1], p));

    auto iter = table.begin();
    vector<vector<int>> result;
    while (K--) {
        result.push_back(iter->second);
        iter++;
    }
    return result;
}

int main () {
    vector<vector<int>> v1;
    v1.push_back({1,3});
    v1.push_back({-2,2});
    auto result1 = kClosest(v1, 1);
    assert(result1.size() == 1);
    assert(result1[0][0] == -2);
    assert(result1[0][1] == 2);

    vector<vector<int>> v2;
    v2.push_back({3,3});
    v2.push_back({5,-1});
    v2.push_back({-2,4});
    auto result2 = kClosest(v2, 2);
    assert(result2.size() == 2);
    assert(result2[0][0] == 3 || result2[0][0] == -2);
    assert(result2[0][1] == 3 || result2[0][1] == 4);
    assert(result2[1][0] == 3 || result2[1][0] == -2);
    assert(result2[1][1] == 3 || result2[1][1] == 4);

    vector<vector<int>> v3;
    v3.push_back({0,1});
    v3.push_back({1,0});
    auto result3 = kClosest(v3, 2);
    assert(result3.size() == 2);
    assert(result3[0][0] == 0 || result3[0][0] == 1);
    assert(result3[0][1] == 1 || result3[0][1] == 0);
    assert(result3[1][0] == 0 || result3[1][0] == 1);
    assert(result3[1][1] == 1 || result3[1][1] == 0);

    return 0;
}
