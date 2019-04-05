#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

int solve (vector<int> & nums, int left, int right) {
    if (left > right)
        return -1;

    int mid = (left + right) / 2;
    if (mid > 0 && mid < nums.size() - 1) {
        if (nums[mid-1] < nums[mid] && nums[mid] > nums[mid + 1])
            return mid;
    } else if (mid == 0) {
        if (nums[mid] > nums[mid + 1])
            return mid;
    } else {
        if (nums[mid-1] < nums[mid])
            return mid;
    }

    int result = solve(nums, left, mid - 1);
    if (result < 0)
        result = solve(nums, mid + 1, right);
    return result;
}

int findPeakElement (vector<int> & nums) {
    int size = nums.size();
    if (size == 1)
        return 0;
    return solve(nums, 0, nums.size() - 1);
}

int main () {
    vector<int> v1{1,2,3,1};
    assert(findPeakElement(v1) == 2);
    vector<int> v2{1,2,1,3,5,6,4};
    assert(findPeakElement(v2) == 1 || findPeakElement(v2) == 5);
    vector<int> v3{1};
    assert(findPeakElement(v3) == 0);
    vector<int> v4{-2147483648};
    assert(findPeakElement(v4) == 0);
    vector<int> v5{1,2};
    assert(findPeakElement(v5) == 1);
    vector<int> v6{1,2,3,4,5};
    assert(findPeakElement(v6) == 4);
    return 0;
}
