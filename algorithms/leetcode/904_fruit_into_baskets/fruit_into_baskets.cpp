#include <cstdio>
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

int solve (vector<int> & tree, int start) {
    int first = tree[start];
    int second = -1;
    int result = 1;
    for (int i = start + 1; i < tree.size(); i++, result++) {
        if (tree[i] == first)
            continue;
        if (second == -1) {
            second = tree[i];
            continue;
        }
        if (tree[i] == second)
            continue;
        break;
    }
    return result;
}

int totalFruit (vector<int> & tree) {
    vector<int> starts;
    int prev = -1;
    for (int i = 0; i < tree.size(); i++) {
        if (prev == tree[i])
            continue;
        prev = tree[i];
        starts.push_back(i);
    }

    int result = -1;
    for (int i = 0; i < starts.size(); i++) {
        int cur = solve(tree, starts[i]);
        if (cur > result) result = cur;
    }
    return result;
}

int main () {
    vector<int> v1{1,2,1};
    assert(totalFruit(v1) == 3);
    vector<int> v2{0,1,2,2};
    assert(totalFruit(v2) == 3);
    vector<int> v3{1,2,3,2,2};
    assert(totalFruit(v3) == 4);
    vector<int> v4{3,3,3,1,2,1,1,2,3,3,4};
    assert(totalFruit(v4) == 5);
    vector<int> v5{1,0,1,4,1,4,1,2,3};
    assert(totalFruit(v5) == 5);
    vector<int> v6{0,1,6,6,4,4,6};
    assert(totalFruit(v6) == 5);
    return 0;
}
