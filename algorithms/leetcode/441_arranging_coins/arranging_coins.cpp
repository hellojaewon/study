#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int arrangeCoins (int n) {
    long l = 1;
    long r = n;
    long result = 0;
    while (l <= r) {
        long mid = (l+r)/2;
        long required = (mid * (mid + 1)) / 2;
        if (required > n)
            r = mid - 1;
        else {
            result = max(mid, result);
            l = mid + 1;
        }
    }
    return result;
}

int main () {
    assert(arrangeCoins(5) == 2);
    assert(arrangeCoins(8) == 3);

    return 0;
}
