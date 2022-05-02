#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int lengthOfLIS (vector<int> & nums) {
    vector<int> dp(nums.size(), 1);
    int result = 0;
    for (int i = nums.size() - 1; i >= 0; i--) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] < nums[j])
                dp[i] = max(dp[i], 1 + dp[j]);
        }
        result = max(result, dp[i]);
    }
    return result;
}

void test1 () {
    vector<int> nums{10, 9, 2, 5, 3, 7, 101, 18};
    assert(lengthOfLIS(nums) == 4);
}

void test2 () {
    vector<int> nums{0,1,0,3,2,3};
    assert(lengthOfLIS(nums) == 4);
}

void test3 () {
    vector<int> nums{7,7,7,7,7,7,7};
    assert(lengthOfLIS(nums) == 1);
}

void test4 () {
    vector<int> nums{0};
    assert(lengthOfLIS(nums) == 1);
}

int main () {
    test1();
    test2();
    test3();
    test4();

    return 0;
}
