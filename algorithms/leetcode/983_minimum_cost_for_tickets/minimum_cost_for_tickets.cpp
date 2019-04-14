#include <iostream>
#include <cstdio>
#include <vector>
#include <cassert>

using namespace std;

int next (vector<int> & days, int dayIndex, int valid) {
    int validDay = days[dayIndex] + valid - 1;
    int i = 0;
    for (i = dayIndex + 1; i < days.size() && i < validDay; i++) {
        if (days[i] > validDay)
            break;
    }
    return i;
}

int solve (vector<int> & days, vector<int> & costs, vector<int> & dp, int dayIndex) {
    if (dayIndex >= days.size())
        return 0;
    if (dp[dayIndex])
        return dp[dayIndex];
    int oneDay = costs[0] + solve(days, costs, dp, next(days, dayIndex, 1));
    int sevenDay = costs[1] + solve(days, costs, dp, next(days, dayIndex, 7));
    int thirtyDay = costs[2] + solve(days, costs, dp, next(days, dayIndex, 30));
    int min = oneDay < sevenDay ? oneDay : sevenDay;
    min = min < thirtyDay ? min : thirtyDay;
    dp[dayIndex] = min;
    return min;
}

int mincostTickets(vector<int>& days, vector<int>& costs) {
    vector<int> dp(days.size(), 0);
    return solve(days, costs, dp, 0);
}

int main () {
    vector<int> days1{1,4,6,7,8,20};
    vector<int> costs1{2,7,15};
    assert(mincostTickets(days1, costs1) == 11);

    vector<int> days2{1,2,3,4,5,6,7,8,9,10,30,31};
    vector<int> costs2{2,7,15};
    assert(mincostTickets(days2, costs2) == 17);

    vector<int> days3{1,4,6,9,10,11,12,13,14,15,16,17,18,20,21,22,23,27,28};
    vector<int> costs3{3,13,45};
    assert(mincostTickets(days3, costs3) == 44);

    vector<int> days4{1,2,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,20,21,24,25,27,28,29,30,31,34,37,38,39,41,43,44,45,47,48,49,54,57,60,62,63,66,69,70,72,74,76,78,80,81,82,83,84,85,88,89,91,93,94,97,99};
    vector<int> costs4{9,38,134};
    assert(mincostTickets(days4, costs4) == 423);
    return 0;
}
