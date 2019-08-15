#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

int findDuplicate(vector<int>& nums) {
    int fast = 0;
    int slow = 0;
    do {
        fast = nums[nums[fast]];
        slow = nums[slow];
    } while (nums[fast] != nums[slow]);

    int ptr1 = 0;
    int ptr2 = slow;
    while (nums[ptr1] != nums[ptr2]) {
        ptr1 = nums[ptr1];
        ptr2 = nums[ptr2];
    }
    return nums[ptr1];
}

int main () {
    vector<int> v1{1,3,4,2,2};
    assert(findDuplicate(v1) == 2);
    vector<int> v2{3,1,3,4,2};
    assert(findDuplicate(v2) == 3);
    return 0;
}
