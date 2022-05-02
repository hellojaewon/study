#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <cassert>

using namespace std;

int longestConsecutive(vector<int>& nums) {
    unordered_set<int> s;
    for (auto n : nums)
        s.insert(n);

    int result = 0;
    for (auto n : nums) {
        if (s.find(n-1) != s.end()) continue;
        int longest = 0;
        while (s.find(n++) != s.end())
            longest++;
        result = max(result, longest);
    }
    return result;
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
