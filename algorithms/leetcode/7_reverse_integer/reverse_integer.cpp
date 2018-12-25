#include <iostream>
#include <string>
#include <cassert>

using namespace std;

// pop operation
// pop = x % 10;
// pop /= 10;
//
// push operation
// rev = rev * 10 + pop;
//
// overflow check
// if push operation cause overflow, then rev >= INT_MAX / 10
// if rev > INT_MAX / 10, then overflow
// if rev == INT_MAX / 10, then the overflow occurs if and only if pop > 7
// (where 7 is the minimum significant digit of INT_MAX)
//
int reverseInteger (int x) {
    bool negative = false;
    if (x < 0) {
        negative = true;
        x = -x;
    }

    int reverse = 0;
    while (x) {
        int pop = x % 10;
        x = x / 10;

        if ((reverse > INT_MAX / 10) || (!negative && (reverse == INT_MAX / 10) && pop > 7)) return 0;
        if ((reverse > INT_MAX / 10) || (negative && (reverse == INT_MAX / 10) && pop > 8)) return 0;
        reverse = reverse * 10 + pop;
    }
    if (negative) reverse = -reverse;
    return reverse;
}

int main () {
    assert(reverseInteger(0) == 0);
    assert(reverseInteger(123) == 321);
    assert(reverseInteger(-123) == -321);
    assert(reverseInteger(120) == 21);
    assert(reverseInteger(1534236469) == 0);
    return 0;
}
