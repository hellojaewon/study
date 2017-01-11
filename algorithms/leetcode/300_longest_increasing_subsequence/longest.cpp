#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int lengthOfLIS (vector<int> & nums) {
    vector<int> dp(nums.size(), 1);
    for (unsigned i = 1; i < nums.size(); i++) {
        for (unsigned j = 0; j < i; j++) {
            if (nums[i] > nums[j])
                dp[i] = max(dp[i], dp[j]+1);
        }
    }
    int longest = 0;
    for (int x : dp)
        longest = max(longest, x);
    return longest;
}

int main () {
    vector<int> nums{10, 9, 2, 5, 3, 7, 101, 18};
    cout<<lengthOfLIS(nums)<<endl;
    return 0;
}
