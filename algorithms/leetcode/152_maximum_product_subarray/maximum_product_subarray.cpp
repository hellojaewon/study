#include <iostream>
#include <vector>
#include <string>

using namespace std;

int maxProduct(vector<int>& nums) {
    int result = nums[0];
    int curMax = nums[0];
    int curMin = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        int a = curMax * nums[i];
        int b = curMin * nums[i];
        curMax = max(max(a,b),nums[i]);
        curMin = min(min(a,b),nums[i]);
        result = max(max(curMax, curMin), result);
    }
    return result;
}

void test1 () {
    vector<int> nums{2,3,-2,4};
    assert(maxProduct(nums) == 6);
}

void test2 () {
    vector<int> nums{-2,0,-1};
    assert(maxProduct(nums) == 0);
}

void test3 () {
    vector<int> nums{-2,3,-4};
    assert(maxProduct(nums) == 24);
}

void test4 () {
    vector<int> nums{0,2};
    assert(maxProduct(nums) == 2);
}

int main () {
    test1();
    test2();
    test3();
    test4();

    return 0;
}
