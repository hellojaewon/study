#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <cassert>

using namespace std;

int solve (const string & text1, const string & text2, int t1, int t2, vector<vector<int>> & m) {
    if (t1 >= text1.size() || t2 >= text2.size()) return 0;
   
    if (m[t1][t2] == -1) {
        if (text1[t1] == text2[t2])
            m[t1][t2] = 1 + solve(text1, text2, t1 + 1, t2 + 1, m);
        else
            m[t1][t2] = max(solve(text1, text2, t1 + 1, t2, m), solve(text1, text2, t1, t2 + 1, m));
    }
    return m[t1][t2];
}

int longestCommonSubsequenceWithMemo(string text1, string text2) {
    vector<vector<int>> m;
    for (int i = 0; i < 1000; i++)
        m.push_back(vector<int>(1000, -1));
    return solve(text1, text2, 0, 0, m);
}

int longestCommonSubsequence(string text1, string text2) {
    vector<vector<int>> m;
    for (int i = 0; i <= text1.size(); i++)
        m.push_back(vector<int>(text2.size() + 1, 0));
    for (int i = text1.size() - 1; i >= 0; i--) {
        for (int j = text2.size() - 1; j >= 0; j--) {
            if (text1[i] == text2[j])
                m[i][j] = 1 + m[i+1][j+1];
            else
                m[i][j] = max(m[i+1][j], m[i][j+1]);
        }
    }
    return m[0][0];
}


int main () {
    assert(longestCommonSubsequence("abcde", "ace") == 3);
    assert(longestCommonSubsequence("abc", "abc") == 3);
    assert(longestCommonSubsequence("abc", "def") == 0);
    assert(longestCommonSubsequence("pmjghexybyrgzczy", "hafcdqbgncrcbihkd") == 4);
    return 0;
}
