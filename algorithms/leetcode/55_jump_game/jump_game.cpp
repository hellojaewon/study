#include <iostream>
#include <vector>
#include <unordered_set>
#include <cassert>

using namespace std;

bool solve (vector<int> & nums, int cur, unordered_set<int> & s) {
    if (cur >= nums.size() - 1)
        return true;
    
    if (s.find(cur) != s.end()) return false;
    s.insert(cur);
    for (int i = nums[cur]; i > 0; i--) {
        if (solve(nums, cur + i, s))
            return true;
    }
    return false;
}

bool canJump2(vector<int>& nums) {
    unordered_set<int> s;
    return solve(nums, 0, s);
}

bool canJump(vector<int>& nums) {
    int goal = nums.size() - 1;
    for (int i = nums.size() - 2; i >= 0; i--) {
        if (i + nums[i] < goal)
            continue;
        goal = i;
    }
    return goal == 0;
}


void test1 () {
    vector<int> nums{3,2,1,0,4};
    assert(canJump(nums) == false);
}

void test2 () {
    vector<int> nums{2,0};
    assert(canJump(nums) == true);
}

int main () {
    test1();
    test2();
    return 0;
}
