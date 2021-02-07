#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

bool threeConsecutiveOdds(vector<int>& arr) {
    arr[0] = arr[0] % 2;
    for (int i = 1; i < arr.size(); i++) {
        arr[i] = arr[i] % 2;
        if (arr[i])
            arr[i] += arr[i-1];
        if (arr[i] == 3)
            return true;
    }
    return false;
}

int main () {
    vector<int> n1{2,6,4,1};
    assert(threeConsecutiveOdds(n1) == false);

    vector<int> n2{1,2,34,3,4,5,7,23,12};
    assert(threeConsecutiveOdds(n2) == true);

    return 0;
}
