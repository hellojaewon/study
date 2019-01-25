#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int search (vector<int> & nums, int target, int left, int right) {
    if (left > right)
        return -1;

    int mid = (left + right) / 2;
    if (nums[mid] == target)
        return mid;

    if (target < nums[mid])
        return search(nums, target, left, mid - 1);
    else
        return search(nums, target, mid + 1, right);
}

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

int search (vector<int> & nums, int target) {
    if (nums.size() == 0)
        return -1;

    int rotationIndex = findRotationIndex(nums);
    cout<<rotationIndex<<endl;
    if (rotationIndex == 0)
        return search(nums,target, 0, nums.size() - 1);
    if (target < nums[0])
        return search(nums, target, rotationIndex, nums.size() - 1);
    else
        return search(nums, target, 0, rotationIndex - 1);
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
