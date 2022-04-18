#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

const int UNDEFINED = -1;

bool interleave(int c1, int c2, int c3, string & s1, string & s2, string & s3, vector<vector<int>> & memo) {
    if (c3 == s3.size()) return true;

    if (memo[c1][c2] != UNDEFINED)
        return memo[c1][c2];

    if (s1[c1] == s2[c2]) {
        if (s1[c1] == s3[c3]) {
            bool result = interleave(c1 + 1, c2, c3 + 1, s1, s2, s3, memo) || interleave(c1, c2 + 1, c3 + 1, s1, s2, s3, memo);
            memo[c1][c2] = result;
            return result;
        }
        return false;
    }

    bool result = false;
    if (s1[c1] == s3[c3]) result = interleave(c1 + 1, c2, c3 + 1, s1, s2, s3, memo);
    if (s2[c2] == s3[c3]) result = interleave(c1, c2 + 1, c3 + 1, s1, s2, s3, memo);
    memo[c1][c2] = result;
    return result;
}

bool isInterleave(string s1, string s2, string s3) {
    if (s1.size() + s2.size() != s3.size()) return false;
    vector<vector<int>> memo;
    for (int i = 0; i <= s1.size(); i++)
        memo.push_back(vector<int>(s2.size() + 1, UNDEFINED));
    return interleave(0, 0, 0, s1, s2, s3, memo);
}

int main () {
    assert(isInterleave("aabcc", "dbbca", "aadbbcbcac") == true);
    assert(isInterleave("aabcc", "dbbca", "aadbbbaccc") == false);
    assert(isInterleave("", "", "") == true);
    return 0;
}
