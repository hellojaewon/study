#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

int longestConsecutive(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<int> t(nums.size(), 1);
    int max = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (i == 0)
            max = t[i];
        else {
            if (nums[i-1] == nums[i])
                t[i] = t[i-1];
            else if (nums[i-1] + 1 == nums[i]) {
                t[i] = t[i-1] + 1;
                if (t[i] > max)
                    max = t[i];
            }
        }
    }
    return max;
}

int main () {
    vector<int> nums1{100, 4, 200, 1, 3, 2};
    assert(longestConsecutive(nums1) == 4);
    vector<int> nums2{};
    assert(longestConsecutive(nums2) == 0);
    vector<int> nums3{0};
    assert(longestConsecutive(nums3) == 1);
    vector<int> nums4{2,1,0,1};
    assert(longestConsecutive(nums4) == 3);
    return 0;
}
