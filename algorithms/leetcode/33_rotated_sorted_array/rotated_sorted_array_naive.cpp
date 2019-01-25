#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int searchInternal (vector<int> & nums, int target, int left, int right) {
    if (left > right)
        return -1;

    int mid = (left + right) / 2;
    if (nums[mid] == target)
        return mid;

    if (target < nums[mid]) {
        if (nums[left] <= nums[mid]) {
            if (nums[left] <= target)
                return searchInternal(nums, target, left, mid - 1);
            else
                return searchInternal(nums, target, mid + 1, right);
        } else {
            return searchInternal(nums, target, left, mid - 1);
        }
    } else {
        if (nums[mid] <= nums[right]) {
            if (target <= nums[right])
                return searchInternal(nums, target, mid + 1, right);
            else
                return searchInternal(nums, target, left, mid - 1);
        } else {
            return searchInternal(nums, target, mid + 1, right);
        }
    }
}

int search(vector<int>& nums, int target) {
    return searchInternal(nums, target, 0, nums.size() - 1);
}

int main () {
    std::vector<int> nums{4,5,6,7,0,1,2};
    assert(search(nums, 0) == 4);
    assert(search(nums, 1) == 5);
    assert(search(nums, 2) == 6);
    assert(search(nums, 3) == -1);
    assert(search(nums, 4) == 0);
    assert(search(nums, 5) == 1);
    assert(search(nums, 6) == 2);
    assert(search(nums, 7) == 3);

    std::vector<int> empty{};
    assert(search(empty, 5) == -1);

    std::vector<int> v1{5,1,3};
    assert(search(v1, 3) == 2);

    std::vector<int> v2{3,1};
    assert(search(v2, 1) == 1);

    std::vector<int> v3{4,5,6,7,8,1,2,3};
    assert(search(v3, 8) == 4);

    std::vector<int> v4{5,1,2,3,4};
    assert(search(v4, 1) == 1);

    std::vector<int> v5{8,9,2,3,4};
    assert(search(v5, 9) == 1);

    return 0;
}
