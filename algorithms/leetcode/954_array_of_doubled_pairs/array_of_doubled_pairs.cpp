#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cassert>

using namespace std;

bool canReorderDoubled(vector<int>& A) {
    multiset<int> s;
    sort(A.begin(), A.end());
    for (int i = 0; i < A.size(); i++) {
        auto it = s.find(A[i] * 2);
        if (it == s.end() && (A[i] % 2 == 0))
            it = s.find(A[i] / 2);
        if (it == s.end())
            s.insert(A[i]);
        else
            s.erase(it);

    }
    if (s.empty())
        return true;
    return false;
}

int main () {
    vector<int> nums1{3,1,3,6};
    assert(canReorderDoubled(nums1) == false);
    vector<int> nums2{2,1,2,6};
    assert(canReorderDoubled(nums2) == false);
    vector<int> nums3{4,-2,2,-4};
    assert(canReorderDoubled(nums3) == true);
    vector<int> nums4{1,2,4,16,8,4};
    assert(canReorderDoubled(nums4) == false);
    return 0;
}
