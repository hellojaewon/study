#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int firstMissingPositive(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++)
        if (nums[i] < 0) nums[i] = 0;

    for (int i = 0; i < nums.size(); i++) {
        int value = nums[i];
        if (value < 0) value = -value;
        if (1 <= value && value <= nums.size()) {
            if (nums[value-1] > 0)
                nums[value-1] = -nums[value-1];
            else if (nums[value-1] == 0)
                nums[value-1] = -(nums.size() + 1);
        }
    }

    for (int i = 1; i <= nums.size(); i++) {
        if (nums[i-1] >= 0)
            return i;
    }
    return nums.size() + 1;
}

void test1 () {
    vector<int> nums{1,2,0};
    assert(firstMissingPositive(nums) == 3);
}

void test2 () {
    vector<int> nums{3,4,-1,1};
    assert(firstMissingPositive(nums) == 2);
}

void test3 () {
    vector<int> nums{7,8,9,11,12};
    assert(firstMissingPositive(nums) == 1);
}

void test4 () {
    vector<int> nums{1};
    assert(firstMissingPositive(nums) == 2);
}

int main () {
    test1();
    test2();
    test3();
    test4();

    return 0;
}
