#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve (vector<int> & nums, vector<vector<int>> & result, vector<int> & r, vector<bool> & visited) {
    if (r.size() == nums.size()) {
        result.push_back(r);
        return;
    }

    for (int i = 0; i < nums.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            r.push_back(nums[i]);
            solve(nums, result, r, visited);
            r.pop_back();
            visited[i] = false;
        }
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> r;
    vector<bool> visited(nums.size(), false);
    solve(nums, result, r, visited);
    return result;
}

void test1 () {
    vector<int> nums{1,2,3};
    auto result = permute(nums);
    assert(result.size() == 6);
}

void test2 () {
    vector<int> nums{0,1};
    auto result = permute(nums);
    assert(result.size() == 2);
}

void test3 () {
    vector<int> nums{1};
    auto result = permute(nums);
    assert(result.size() == 1);
}

int main () {
    test1();
    test2();
    test3();

    return 0;
}
