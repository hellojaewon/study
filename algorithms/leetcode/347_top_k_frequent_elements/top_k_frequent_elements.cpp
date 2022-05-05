#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cassert>

using namespace std;

bool compare (const pair<int,int> & lhs, const pair<int,int> & rhs) {
    return lhs.second < rhs.second;
}

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> m;
    for (auto n : nums) m[n]++;

    vector<pair<int,int>> heap;
    for (auto & p : m) {
        heap.push_back(p);
        push_heap(heap.begin(), heap.end(), compare);
    }

    vector<int> result;
    for (int i = 0; i < k; i++) {
        result.push_back(heap.front().first);
        pop_heap(heap.begin(), heap.end(), compare);
        heap.pop_back();
    }

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
