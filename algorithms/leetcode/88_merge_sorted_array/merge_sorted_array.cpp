#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int cur = 0;
    for (cur = nums1.size() - 1; cur >= 0; cur--) {
        if (m == 0 || n == 0) break;
        if (nums1[m-1] > nums2[n-1]) {
            nums1[cur] = nums1[m-1];
            m--;
        } else {
            nums1[cur] = nums2[n-1];
            n--;
        }
    }

    while (m > 0) nums1[cur--] = nums1[--m];
    while (n > 0) nums1[cur--] = nums2[--n];
}

void test1 () {
    vector<int> nums1{1,2,3,0,0,0};
    vector<int> nums2{2,5,6};
    merge(nums1, nums1.size() - nums2.size(), nums2, nums2.size());
    assert(nums1[0] == 1);
    assert(nums1[1] == 2);
    assert(nums1[2] == 2);
    assert(nums1[3] == 3);
    assert(nums1[4] == 5);
    assert(nums1[5] == 6);
}

void test2 () {
    vector<int> nums1{1};
    vector<int> nums2{};
    merge(nums1, nums1.size() - nums2.size(), nums2, nums2.size());
    assert(nums1[0] == 1);
}

void test3 () {
    vector<int> nums1{0};
    vector<int> nums2{1};
    merge(nums1, nums1.size() - nums2.size(), nums2, nums2.size());
    assert(nums1[0] == 1);
}

int main () {
    test1();
    test2();
    test3();

    return 0;
}
