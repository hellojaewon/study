#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

using namespace std;

int solve (int unit, char c, char next, char five, char ten) {
    int result = 0;
    if (next == ' ')
        result = unit;
    else {
        if (next == five || next == ten)
            result = -unit;
        else
            result = unit;
    }
    return result;
}

int romanToInt(string s) {
    int sum = 0;
    int size = s.size();
    for (int i = 0; i < size; i++) {
        char next = i < size -1 ? s[i+1] : ' ';
        if (s[i] == 'I')
            sum += solve(1, s[i], next, 'V', 'X');
        else if (s[i] == 'X')
            sum += solve(10, s[i], next, 'L', 'C');
        else if (s[i] == 'C')
            sum += solve(100, s[i], next, 'D', 'M');
        else {
            if (s[i] == 'V') sum += 5;
            else if (s[i] == 'L') sum += 50;
            else if (s[i] == 'D') sum += 500;
            else if (s[i] == 'M') sum += 1000;
        }
    }
    return sum;
}

int main () {
    assert(romanToInt("III") == 3);
    assert(romanToInt("IV") == 4);
    assert(romanToInt("IX") == 9);
    assert(romanToInt("LVIII") == 58);
    assert(romanToInt("MCMXCIV") == 1994);
    return 0;
}
