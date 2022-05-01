#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> result(nums.size(), 0);
    
    int prefix = 1;
    for (int i = 0; i < nums.size(); i++) {
        result[i] = prefix;
        prefix *= nums[i];
    }

    int suffix = 1;
    for (int i = nums.size() - 1; i > 0; i--) {
        result[i] = result[i] * suffix;
        suffix *= nums[i];
    }
    result[0] = suffix;
    return result;
}

void test1 () {
    vector<int> nums{1,2,3,4};
    auto result = productExceptSelf(nums);
    assert(result[0] == 24);
    assert(result[1] == 12);
    assert(result[2] == 8);
    assert(result[3] == 6);
}

void test2 () {
    vector<int> nums{-1,1,0,-3,3};
    auto result = productExceptSelf(nums);
    assert(result[0] == 0);
    assert(result[1] == 0);
    assert(result[2] == 9);
    assert(result[3] == 0);
    assert(result[4] == 0);
}

int main () {
    test1();
    test2();
    return 0;
}
