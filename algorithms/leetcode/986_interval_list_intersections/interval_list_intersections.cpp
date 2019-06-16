#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

bool overlap (vector<int> & intervalA, vector<int> & intervalB) {
    if (   intervalA[1] < intervalB[0]
        || intervalA[0] > intervalB[1]
    )
        return false;

    return true;
}

vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
    vector<vector<int>> result;

    int sizeA = A.size();
    int sizeB = B.size();
    int i = 0, j = 0;
    while (i < sizeA && j < sizeB) {
        if (overlap(A[i], B[j])) {
            vector<int> r;
            r.push_back(max(A[i][0], B[j][0]));
            r.push_back(min(A[i][1], B[j][1]));
            result.push_back(r);
        }
        if (A[i][1] < B[j][1])
            i++;
        else
            j++;
    }

    return result;
}

int main () {
    vector<vector<int>> A, B;
    A.push_back(vector<int>{0,2});
    A.push_back(vector<int>{5,10});
    A.push_back(vector<int>{13,23});
    A.push_back(vector<int>{24,25});
    B.push_back(vector<int>{1,5});
    B.push_back(vector<int>{8,12});
    B.push_back(vector<int>{15,24});
    B.push_back(vector<int>{25,26});

    vector<vector<int>> expected;
    expected.push_back(vector<int>{1,2});
    expected.push_back(vector<int>{5,5});
    expected.push_back(vector<int>{8,10});
    expected.push_back(vector<int>{15,23});
    expected.push_back(vector<int>{24,24});
    expected.push_back(vector<int>{25,25});

    auto res = intervalIntersection(A, B);
    assert(res.size() == expected.size());
    for (int i = 0; i < res.size(); i++) {
        assert(res[0][0] == expected[0][0]);
        assert(res[0][1] == expected[0][1]);
    }

    return 0;
}
