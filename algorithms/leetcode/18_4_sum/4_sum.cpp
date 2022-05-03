#include <iostream>
#include <vector>
#include <string>

using namespace std;

void kSum (vector<int> & nums, int k, int target, int start, vector<vector<int>> & result, vector<int> & r) {
    if (k == 2) {
        int left = start;
        int right = nums.size() - 1;
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum == target) {
                r.push_back(nums[left]);
                r.push_back(nums[right]);
                result.push_back(r);
                r.pop_back();
                r.pop_back();
                left++;
                right--;
                while (left < right && nums[left-1] == nums[left]) left++;
                while (left < right && nums[right+1] == nums[right]) right--;
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        return;
    }

    for (int i = start; i < nums.size() - k + 1; i++) {
        if (i == start || nums[i] != nums[i-1]) {
            r.push_back(nums[i]);
            kSum(nums, k - 1, target - nums[i], i + 1, result, r);
            r.pop_back();
        }
    }
}

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    if (nums.size() < 4) return result;
    vector<int> r;
    kSum(nums, 4, target, 0, result, r);
    return result;
}

void test1 () {
    vector<int> nums{1,0,-1,0,-2,2};
    auto result = fourSum(nums, 0);
    assert(result.size() == 3);
}

void test2 () {
    vector<int> nums{2,2,2,2,2};
    auto result = fourSum(nums, 8);
    assert(result.size() == 1);
}

void test3 () {
    vector<int> nums{-2,-1,-1,1,1,2,2};
    auto result = fourSum(nums, 0);
    assert(result.size() == 2);
}

int main () {
    test1();
    test2();
    test3();

    return 0;
}
