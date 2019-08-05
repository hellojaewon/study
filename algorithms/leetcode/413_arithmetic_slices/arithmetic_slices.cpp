#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

int numberOfArithmeticSlices(vector<int>& A) {
    vector<int> gap;
    for (int i = 0; i < A.size(); i++) {
        if (i + 1 >= A.size()) break;
        gap.push_back(A[i+1]-A[i]);
    }

    int result = 0;
    for (int i = 0; i < gap.size(); i++) {
        for (int j = i + 1; j < gap.size(); j++) {
            if (gap[i] != gap[j]) break;
            result ++;
        }
    }
    return result;
}

int main () {
    vector<int> v1{1,2,3,4};
    assert(numberOfArithmeticSlices(v1) == 3);
    vector<int> v2{1,3,5,7,9};
    assert(numberOfArithmeticSlices(v2) == 6);
    vector<int> v3{};
    assert(numberOfArithmeticSlices(v3) == 0);
    vector<int> v4{1,2,3};
    assert(numberOfArithmeticSlices(v4) == 1);
    vector<int> v5{1,2,5};
    assert(numberOfArithmeticSlices(v5) == 0);
    vector<int> v6{1,2,3,8,9,10};
    assert(numberOfArithmeticSlices(v6) == 2);
    return 0;
}
