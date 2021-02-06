#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int dp (int n, vector<int> & memo) {
    if (n <= 0)
        return 0;

    if (n <= 2)
        return n;

    if (memo[n])
        return memo[n];

    memo[n] = dp(n-1, memo) + dp(n-2, memo);
    return memo[n];
}

int climbStairs(int n) {
    vector<int> memo(n + 1, 0);
    return dp(n, memo);
}

int main () {
    assert(climbStairs(2) == 2);
    assert(climbStairs(3) == 3);

    return 0;
}
