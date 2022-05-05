#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int dp (vector<int> & cost, int cur, vector<int> & memo) {
    if (cur >= cost.size()) return 0;

    if (!memo[cur + 1])
        memo[cur + 1] = dp(cost, cur + 1, memo);
    if (!memo[cur + 2])
        memo[cur + 2] = dp(cost, cur + 2, memo);
    return cost[cur] + min(memo[cur+1], memo[cur+2]);
}

int minCostClimbingStairs(vector<int>& cost) {
    vector<int> memo(cost.size() + 2, 0);
    return min(dp(cost, 0, memo), dp(cost, 1, memo));
}

void test1 () {
    vector<int> cost{10,15,20};
    assert(minCostClimbingStairs(cost) == 15);
}

void test2 () {
    vector<int> cost{1,100,1,1,1,100,1,1,100,1};
    assert(minCostClimbingStairs(cost) == 6);
}

int main () {
    test1();
    test2();

    return 0;
}
