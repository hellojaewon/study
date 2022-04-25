#include <iostream>
#include <vector>
#include <numeric>
#include <cassert>

using namespace std;

int pivotIndex(vector<int>& nums) {
    int right = accumulate(nums.begin(), nums.end(), 0);
    int left = 0;
    for (int i = 0; i < nums.size(); i++) {
        right -= nums[i];
        if (left == right)
            return i;
        left += nums[i];
    }
    return -1;
}

void test1 () {
    vector<int> nums{1,7,3,6,5,6};
    assert(pivotIndex(nums) == 3);
}

void test2 () {
    vector<int> nums{1,2,3};
    assert(pivotIndex(nums) == -1);
}

void test3 () {
    vector<int> nums{2,1,-1};
    assert(pivotIndex(nums) == 0);
}

void test4 () {
    vector<int> nums{1};
    assert(pivotIndex(nums) == 0);
}

int main () {
    test1();
    test2();
    test3();
    test4();

    return 0;
}
