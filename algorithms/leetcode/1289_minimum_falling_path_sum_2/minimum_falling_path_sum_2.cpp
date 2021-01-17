#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int min (const vector<int> & r, int j) {
    int result = INT_MAX;
    for (int i = 0; i < r.size(); i++) {
        if (i == j)
            continue;
        result = std::min(result, r[i]);
    }
    return result;
}


int minFallingPathSum(vector<vector<int>>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        auto & r = arr[i];
        for (int j = 0; j < r.size(); j++)
            arr[i][j] += min(arr[i-1], j);
    }

    int minimum = arr[arr.size()-1][0];
    for (int i = 1; i < arr[arr.size()-1].size(); i++)
        minimum = std::min(minimum, arr[arr.size()-1][i]);

    return minimum;
}

int main () {
    vector<vector<int>> v;
    v.push_back(vector<int>{1,2,3});
    v.push_back(vector<int>{4,5,6});
    v.push_back(vector<int>{7,8,9});
    assert(minFallingPathSum(v) == 13);

    return 0;
}
