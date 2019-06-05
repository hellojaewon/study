#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

int largerThan (int i, vector<int> & nums) {
    int j = nums.size() - 1;
    while (i < j && (nums[i] >= nums[j]))
        j--;
    return j;
}

void nextPermutation (vector<int> & nums) {
    int size = nums.size();
    int i = size - 2;
    while (i >= 0 && (nums[i] >= nums[i+1]))
        i--;
    if (i >= 0)
        swap(nums[i], nums[largerThan(i, nums)]);
    reverse(&nums[i + 1], &nums[size]);
}

int main () {
    vector<int> v1{1,2,3};
    nextPermutation(v1);
    assert(v1[0] == 1);
    assert(v1[1] == 3);
    assert(v1[2] == 2);
    vector<int> v2{3,2,1};
    nextPermutation(v2);
    assert(v2[0] == 1);
    assert(v2[1] == 2);
    assert(v2[2] == 3);
    vector<int> v3{1,1,5};
    nextPermutation(v3);
    assert(v3[0] == 1);
    assert(v3[1] == 5);
    assert(v3[2] == 1);
    vector<int> v4{1,2};
    nextPermutation(v4);
    assert(v4[0] == 2);
    assert(v4[1] == 1);
    vector<int> v5{2,1};
    nextPermutation(v5);
    assert(v5[0] == 1);
    assert(v5[1] == 2);
    vector<int> v6{1,3,2};
    nextPermutation(v6);
    assert(v6[0] == 2);
    assert(v6[1] == 1);
    assert(v6[2] == 3);
    vector<int> v7{1};
    nextPermutation(v7);
    assert(v7[0] == 1);
    return 0;
}
