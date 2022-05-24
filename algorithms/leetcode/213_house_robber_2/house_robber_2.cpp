#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int dp (vector<int> & nums, int cur, int end) {
    if (cur >= end) return 0;

    int first = 0;
    int second = 0;
    for (int i = cur; i < end; i++) {
        int newValue = max(first + nums[i], second);
        first = second;
        second = newValue;
    }
    return second;
}

int rob(vector<int>& nums) {
    if (nums.size() == 1)
        return nums[0];
    return max(dp(nums, 0, nums.size() - 1), dp(nums, 1, nums.size()));
}

int main () {
    vector<int> n1{2,3,2};
    assert(rob(n1) == 3);

    vector<int> n2{1,2,3,1};
    assert(rob(n2) == 4);

    vector<int> n3{2,1,1,2};
    assert(rob(n3) == 3);

    vector<int> n4{200,3,140,20,10};
    assert(rob(n4) == 340);

    vector<int> n5{1};
    assert(rob(n5) == 1);
    return 0;
}
