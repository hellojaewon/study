#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <cassert>

using namespace std;

int deleteAndEarn(vector<int>& nums) {
    if (nums.size() == 0)
        return 0;

    unordered_map<int, int> t;
    for (auto n : nums)
        t[n]++;

    vector<pair<int,int>> v;
    for (auto p : t)
        v.push_back(make_pair(p.first, p.second));
    sort(v.begin(), v.end());

    vector<int> max;
    for (int i = 0; i < v.size(); i++)
        max.push_back(v[i].first * v[i].second);

    int globalMax = max[0];
    int subMax = 0;
    for (int i = 1; i < v.size(); i++) {
        if (v[i-1].first + 1 == v[i].first) {
            if (max[i-1] == subMax)
                max[i] += globalMax;
            else
                max[i] += subMax;
        } else {
            max[i] += globalMax;
        }
        if (max[i] > subMax)
            subMax = max[i];
        if (subMax > globalMax)
            swap(subMax, globalMax);
    }
    return globalMax;
}

int main () {
    vector<int> nums;
    nums = {};
    assert(deleteAndEarn(nums) == 0);
    nums = {2,3,1,1,2,3,1};
    assert(deleteAndEarn(nums) == 9);
    nums = {3,4,2};
    assert(deleteAndEarn(nums) == 6);
    nums = {3,3,4};
    assert(deleteAndEarn(nums) == 6);
    nums = {3,3,3,4};
    assert(deleteAndEarn(nums) == 9);
    nums = {2,3,3,3,4};
    assert(deleteAndEarn(nums) == 9);
    nums = {2,2,3,3,3,4};
    assert(deleteAndEarn(nums) == 9);
    nums = {1,1,1,2,4,5,5,5,6};
    assert(deleteAndEarn(nums) == 18);
    nums = {3,7,10,5,2,4,8,9,9,4,9,2,6,4,6,5,4,7,6,10};
    assert(deleteAndEarn(nums) == 66);
    nums = {12,32,93,17,100,72,40,71,37,92,58,34,29,78,11,84,77,90,92,35,12,5,27,92,91,23,65,91,85,14,42,28,80,85,38,71,62,82,66,3,33,33,55,60,48,78,63,11,20,51,78,42,37,21,100,13,60,57,91,53,49,15,45,19,51,2,96,22,32,2,46,62,58,11,29,6,74,38,70,97,4,22,76,19,1,90,63,55,64,44,90,51,36,16,65,95,64,59,53,93};
    assert(deleteAndEarn(nums) == 3451);
    return 0;
}
