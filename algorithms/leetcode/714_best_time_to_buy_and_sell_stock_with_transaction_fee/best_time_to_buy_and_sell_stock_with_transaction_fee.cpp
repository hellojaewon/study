#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int dp (vector<int>& prices, int i, bool bought, int fee, vector<bool> & visited, vector<vector<int>> & memo) {
    if (i == prices.size())
        return 0;

    if (!visited[i]) {
        memo[0][i] = dp(prices, i + 1, false, fee, visited, memo);
        memo[1][i] = dp(prices, i + 1, true, fee, visited, memo);
        visited[i] = true;
    }
    if (bought)
        return max(prices[i] -fee + memo[0][i], memo[1][i]);
    return max(-prices[i] + memo[1][i], memo[0][i]);
}

int maxProfit(vector<int>& prices, int fee) {
    vector<bool> visited(prices.size(), false);
    vector<vector<int>> memo;
    memo.push_back(vector<int>(prices.size()));
    memo.push_back(vector<int>(prices.size()));

    return max(-prices[0] + dp(prices, 1, true, fee, visited, memo), dp(prices, 1, false, fee, visited, memo));
}


int main () {
    vector<int> v1{1,3,2,8,4,9};
    assert(maxProfit(v1, 2) == 8);
    return 0;
}
