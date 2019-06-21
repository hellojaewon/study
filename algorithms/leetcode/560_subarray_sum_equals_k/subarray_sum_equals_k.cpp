#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>

using namespace std;

int subarraySum(vector<int>& nums, int k) {
    int sum = 0;
    vector<int> t(nums.size(), 0);
    unordered_map<int,int> table;
    for (int i = 0; i < nums.size(); i++) {
        if (i == 0)
            t[i] = nums[i];
        else
            t[i] = t[i-1] + nums[i];

        int v = t[i] - k;
        if (v == 0)
            sum++;
        sum += table[v];
        table[t[i]]++;
    }
    return sum;
}

int main () {
    vector<int> nums1{1,1,1};
    assert(subarraySum(nums1, 2) == 2);
    vector<int> nums2{1};
    assert(subarraySum(nums2, 0) == 0);
    vector<int> nums3{-1,-1,1};
    assert(subarraySum(nums3, 1) == 1);
    vector<int> nums4{2,1,6,-1,-1,5};
    assert(subarraySum(nums4, 5) == 3);
    return 0;
}
