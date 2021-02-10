#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

char shift (char c, int i) {
    while (i--) {
        c++;
        if (c > 'z')
            c = 'a';
    }
    return c;
}

string shiftingLetters(string S, vector<int>& shifts) {
    for (int i = 0; i < shifts.size(); i++)
        shifts[i] %= 26;
    for (int i = shifts.size() - 2; i >= 0; i--)
        shifts[i] += shifts[i+1];
    for (int i = 0; i < shifts.size(); i++)
        shifts[i] = shifts[i] % 26;
    for (int i = 0; i < S.size(); i++)
        S[i] = shift(S[i], shifts[i]);
    return S;
}

int main () {
    vector<int> shifts{26,9,17};
    assert(shiftingLetters("ruu", shifts) == "rul");

    return 0;
}
