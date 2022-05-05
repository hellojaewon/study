#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

int dp (vector<int> & prices, int day, bool bought, vector<vector<int>> & memo) {
    if (day == prices.size())
        return 0;

    if (bought) {
        if (memo[0][day] == -1)
            memo[0][day] = max(prices[day], dp(prices, day + 1, true, memo));
        return memo[0][day];
    }
    if (memo[1][day] == -1)
        memo[1][day] = max(-prices[day] + dp(prices, day + 1, true, memo), dp(prices, day + 1, false, memo));
    return memo[1][day];
}

int maxProfitWithDp(vector<int>& prices) {
    vector<vector<int>> memo;
    memo.push_back(vector<int>(prices.size(), -1));
    memo.push_back(vector<int>(prices.size(), -1));
    return dp(prices, 0, false, memo);
}

int maxProfit(vector<int>& prices) {
    if (prices.size() < 2) return 0;

    vector<int> buy(prices.size(), -1);
    vector<int> sell(prices.size(), -1);
    buy[0] = prices[0];
    for (int i = 1; i < prices.size(); i++)
        buy[i] = min(buy[i-1], prices[i]);
    sell[prices.size() - 1] = prices[prices.size() - 1];
    for (int i = prices.size() - 2; i >= 0; i--)
        sell[i] = max(sell[i+1], prices[i]);
    int maxProfit = 0;
    for (int i = 0; i < prices.size() - 1; i++)
        maxProfit = max(maxProfit, sell[i+1]-buy[i]);
    return maxProfit;
}

int main () {
    std::vector<int> prices1{7,1,5,3,6,4};
    assert(maxProfit(prices1) ==5);

    std::vector<int> prices2{7,6,4,3,1};
    assert(maxProfit(prices2) == 0);

    return 0;
}
