#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cassert>

using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> m;
    for (auto n : nums) {
        auto found = m.find(n);
        if (found == m.end())
            m.insert(make_pair(n, 1));
        else
            found->second++;
    }

    vector<pair<int,int>> pairs;
    for (auto n : m)
        pairs.push_back(n);
    sort(pairs.begin(), pairs.end(), [](const pair<int,int> & lhs, const pair<int,int> & rhs) { return lhs.second > rhs.second; });

    vector<int> result;
    for (int i = 0; i < k; i++)
        result.push_back(pairs[i].first);

    return result;
}

int main () {
    vector<int> nums1{1,1,1,2,2,3};
    auto result = topKFrequent(nums1, 2);
    assert(result.size() == 2);
    assert(result[0] == 1);
    assert(result[1] == 2);

    vector<int> nums2{1};
    result = topKFrequent(nums2, 1);
    assert(result.size() == 1);
    assert(result[0] == 1);
    return 0;
}
