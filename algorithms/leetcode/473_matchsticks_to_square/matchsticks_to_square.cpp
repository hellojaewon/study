#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

bool solve (vector<int> & matchsticks, vector<int> & t, int r, int cur) {
    if (cur == matchsticks.size()) return true;

    for (int i = 0; i < 4; i++) {
        if (t[i] + matchsticks[cur] > r)
            continue;
        t[i] += matchsticks[cur];
        if (solve(matchsticks, t, r, cur + 1))
            return true;
        t[i] -= matchsticks[cur];
    }

    return false;
}

bool makesquare(vector<int>& matchsticks) {
    int sum = 0;
    for (auto i : matchsticks)
        sum += i;
    if (sum % 4 != 0) return false;

    vector<int> t(4, 0);
    sort(matchsticks.begin(), matchsticks.end(), greater<int>());
    return solve(matchsticks, t, sum / 4, 0);
}

int main () {
    std::vector<int> v1{1,1,2,2,2};
    assert(makesquare(v1) == true);
    std::vector<int> v2{3,3,3,3,4};
    assert(makesquare(v2) == false);
    std::vector<int> v3{12,12,12,16,20,24,28,32,36,40,44,48,52,56,60};
    assert(makesquare(v3) == false);
    return 0;
}
