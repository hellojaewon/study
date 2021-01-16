#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int dp (const vector<int> & nums, int i, vector<int> & memo) {
    if (i >= nums.size())
        return 0;

    if (memo[i] == -1)
        memo[i] = max(nums[i] + dp(nums, i + 2, memo), dp(nums, i + 1, memo));

    return memo[i];
}

int rob(vector<int>& nums) {
    vector<int> memo(nums.size(), -1);
    return dp(nums, 0, memo);
}

int main () {
    vector<int> n1{1,2,3,1};
    assert(rob(n1) == 4);

    vector<int> n2{2,7,9,3,1};
    assert(rob(n2) == 12);

    return 0;
}
