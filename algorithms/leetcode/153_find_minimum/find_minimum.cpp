#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int findRotationIndex (vector<int> & nums) {
    if (nums[0] <= nums[nums.size() -1])
        return 0;

    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] > nums[mid + 1])
            return mid + 1;
        if (nums[mid] < nums[left])
            right = mid - 1;
        else
            left = mid + 1;
    }
    return 0;
}

int findMin(vector<int>& nums) {
    return nums[findRotationIndex(nums)];
}

int main () {
    std::vector<int> nums{4,5,6,7,0,1,2};
    assert(findMin(nums) == 0);

    std::vector<int> v1{5,1,3};
    assert(findMin(v1) == 1);

    std::vector<int> v2{3,1};
    assert(findMin(v2) == 1);

    std::vector<int> v3{4,5,6,7,8,1,2,3};
    assert(findMin(v3) == 1);

    std::vector<int> v4{5,1,2,3,4};
    assert(findMin(v4) == 1);

    std::vector<int> v5{8,9,2,3,4};
    assert(findMin(v5) == 2);

    std::vector<int> v6{3,4,5,1,2};
    assert(findMin(v6) == 1);

    std::vector<int> v7{4,5,6,7,0,1,2};
    assert(findMin(v7) == 0);

    return 0;
}
