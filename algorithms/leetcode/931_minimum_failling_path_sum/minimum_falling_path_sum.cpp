#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int minFallingPathSum(vector<vector<int>>& A) {
    for (int i = 1; i < A.size(); i++) {
        auto & r = A[i];
        A[i][0] += min(A[i-1][0], A[i-1][1]);
        for (int j = 1; j < r.size() - 1; j++) {
            A[i][j] += min(min(A[i-1][j-1], A[i-1][j]), A[i-1][j+1]);
        }
        A[i][r.size()-1] += min(A[i-1][r.size()-2], A[i-1][r.size()-1]);
    }

    int minimum = A[A.size()-1][0];
    for (int i = 1; i < A[A.size()-1].size(); i++)
        minimum = min(minimum, A[A.size()-1][i]);

    return minimum;
}

int main () {
    vector<vector<int>> v;
    v.push_back(vector<int>{1,2,3});
    v.push_back(vector<int>{4,5,6});
    v.push_back(vector<int>{7,8,9});
    assert(minFallingPathSum(v) == 12);

    return 0;
}
