#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int solve (vector<vector<int>> & pairs, int head, vector<int> & memo) {
    int longest = 0;
    for (int i = 0; i < pairs.size(); i++) {
        if (head < pairs[i][0]) {
            if (!memo[i])
                memo[i] = solve(pairs, pairs[i][1], memo);

            int length = 1 + memo[i];
            if (longest < length)
                longest = length;
        }
    }
    return longest;
}

int findLongestChain (vector<vector<int>> & pairs) {
    vector<int> memo(pairs.size(), 0);
    return solve(pairs, INT_MIN, memo);
}

int main () {
    vector<vector<int>> pairs1{{1,2},{2,3},{3,4}};
    assert(findLongestChain(pairs1) == 2);
    vector<vector<int>> pairs2{{-10,-8},{8,9},{-5,0},{6,10},{-6,-4},{1,7},{9,10},{-4,7}};
    assert(findLongestChain(pairs2));
    return 0;
}
