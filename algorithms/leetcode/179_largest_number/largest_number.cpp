#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

string largestNumber(vector<int>& nums) {
    sort(
        nums.begin(),
        nums.end(),
        [](int lhs, int rhs) {
            string l = to_string(lhs) + to_string(rhs);
            string r = to_string(rhs) + to_string(lhs);
            int size = l.size();
            for (int i = 0; i < size; i++) {
                if (l[i] == r[i]) continue;
                if (l[i] > r[i]) return true;
                return false;
            }
            return false;
        }
    );

    string result;
    for (auto n : nums) result += to_string(n);
    if (all_of(result.begin(), result.end(), [](char c){ return c == '0'; })) return "0";
    return result;
}

void test1 () {
    vector<int> nums{10,2};
    assert(largestNumber(nums) == "210");
}

void test2 () {
    vector<int> nums{3,30,34,5,9};
    assert(largestNumber(nums) == "9534330");
}

void test3 () {
    vector<int> nums{0,0};
    assert(largestNumber(nums) == "0");
}

int main () {
    test1();
    test2();
    test3();
    return 0;
}
