#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

bool search (vector<int> & nums, int target, int left, int right) {
    if (left > right)
        return false;

    int mid = (left + right) / 2;
    if (nums[mid] == target)
        return true;

    if (target < nums[mid])
        return search(nums, target, left, mid - 1);
    else
        return search(nums, target, mid + 1, right);
}

int findRotationIndex (vector<int> & nums) {
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] > nums[mid + 1])
            return mid + 1;
        if (nums[mid] < nums[left])
            right = mid;
        else if (nums[mid] > nums[right])
            left = mid;
        else if (nums[left] > nums[left+1])
            return left + 1;
        else if (nums[right-1] > nums[right])
            return right;
        else {
            left++;
            right--;
        }
    }
    return 0;
}

bool search (vector<int>& nums, int target) {
    if (nums.size() == 0)
        return false;

    int rotationIndex = findRotationIndex(nums);
    if (rotationIndex == 0)
        return search(nums, target, 0, nums.size() - 1);
    if (target < nums[0])
        return search(nums, target, rotationIndex, nums.size() - 1);
    else
        return search(nums, target, 0, rotationIndex - 1);
}

int main () {
    std::vector<int> v0{1,3,1,1,1};
    assert(search(v0, 3) == true);

    std::vector<int> v1{2,5,6,0,0,1,2};
    assert(search(v1, 0) == true);
    assert(search(v1, 1) == true);
    assert(search(v1, 2) == true);
    assert(search(v1, 3) == false);
    assert(search(v1, 4) == false);
    assert(search(v1, 5) == true);
    assert(search(v1, 6) == true);

    std::vector<int> v2{2,5,0,0,0,0,1};
    assert(search(v2, 0) == true);
    assert(search(v2, 1) == true);
    assert(search(v2, 2) == true);
    assert(search(v2, 3) == false);
    assert(search(v2, 4) == false);
    assert(search(v2, 5) == true);
    assert(search(v2, 6) == false);

    std::vector<int> v3{0,0,0,0,0,1,2};
    assert(search(v3, 0) == true);
    assert(search(v3, 1) == true);
    assert(search(v3, 2) == true);
    assert(search(v3, 3) == false);

    std::vector<int> v4{1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,1,1,1,1};
    assert(search(v4, 0) == false);
    assert(search(v4, 1) == true);
    assert(search(v4, 2) == false);
    assert(search(v4, 3) == true);

    std::vector<int> v5{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    assert(search(v5, 2) == true);

    return 0;
}
