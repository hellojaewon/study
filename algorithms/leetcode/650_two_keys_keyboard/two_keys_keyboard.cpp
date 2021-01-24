#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

unsigned dp (int clip, int a, int n) {
    if (a == n)
        return 0;
    if (a > n)
        return INT_MAX;

    if (clip == a)
        return 1 + dp(clip, a + clip, n);

    if (clip == 0)
        return 1 + dp(a, a, n);

    return 1 + min(dp(a, a, n), dp(clip, a + clip, n));
}

int minSteps(int n) {
    return dp(0, 1, n);
}

int main () {
    assert(minSteps(3) == 3);
    assert(minSteps(1) == 0);
    return 0;
}
