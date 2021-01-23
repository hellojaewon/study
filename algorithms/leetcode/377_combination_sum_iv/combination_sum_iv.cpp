#include <iostream>
#include <vector>
#include <cassert>
#include <unordered_map>

using namespace std;

int dp (vector<int> & nums, int target, unordered_map<int,int> & memo) {
    if (target == 0)
        return 1;
    if (target < 0)
        return 0;
    auto found = memo.find(target);
    if (found != memo.end())
        return found->second;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
        sum += dp(nums, target - nums[i], memo);

    memo.insert(make_pair(target, sum));
    return sum;
}

int combinationSum4(vector<int>& nums, int target) {
    unordered_map<int, int> memo;
    return dp(nums, target, memo);
}

int main () {
    vector<int> v1{1,2,3};
    assert(combinationSum4(v1, 4) == 7);

    vector<int> v2{1,2,3};
    assert(combinationSum4(v2, 32) == 181997601);

    return 0;
}
