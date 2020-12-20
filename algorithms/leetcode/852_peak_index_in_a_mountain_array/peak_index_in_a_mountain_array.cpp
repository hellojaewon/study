#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int peakIndexInMountainArray(vector<int>& arr) {
    int peak = 0;
    int left = 0, right = arr.size()-1;
    while (left != right) {
        peak = (left + right) / 2;
        if (left < peak) {
            if (arr[peak-1] < arr[peak]) {
                left = peak;
            } else {
                right = peak;
            }
        } else if (peak < right) {
            if (arr[peak] < arr[peak+1]) {
                left = peak;
            } else {
                right = peak;
            }
        }
    }

    return peak;
}

int main () {
    std::vector<int> mountains1{0,1,0};
    assert(peakIndexInMountainArray(mountains1) == 1);

    std::vector<int> mountains2{0,2,1,0};
    assert(peakIndexInMountainArray(mountains2) == 1);

    std::vector<int> mountains3{0,10,5,2};
    assert(peakIndexInMountainArray(mountains3) == 1);

    std::vector<int> mountains4{3,4,5,1};
    assert(peakIndexInMountainArray(mountains4) == 2);

    std::vector<int> mountains5{24,69,100,99,79,78,67,36,26,19};
    assert(peakIndexInMountainArray(mountains5) == 2);

    return 0;
}
