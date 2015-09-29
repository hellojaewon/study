#include <cstdio>
#include <algorithm>

int n;
int m[100000][3];
int dp[1000000][3];
const int MAX = 1000;

int solve (int row, int col) {
    if (row == 0) {
        if (col == 0)
            return MAX;
        if (col == 1)
            return m[row][col];
        if (col == 2)
            return m[row][col-1] + m[row][col];
    }

    if (dp[row][col])
        return dp[row][col];

    int minimum = MAX * (row  + 1);
    if (col == 0) {
        minimum = std::min(minimum, solve(row-1, 0));
        minimum = std::min(minimum, solve(row-1, 1));
    } else if (col == 1) {
        minimum = std::min(minimum, solve(row, 0));
        minimum = std::min(minimum, solve(row-1, 0));
        minimum = std::min(minimum, solve(row-1, 1));
        minimum = std::min(minimum, solve(row-1, 2));
    } else if (col == 2) {
        minimum = std::min(minimum, solve(row, 1));
        minimum = std::min(minimum, solve(row-1, 1));
        minimum = std::min(minimum, solve(row-1, 2));
    }
    return dp[row][col] = minimum + m[row][col];
}

int main () {
    int k = 1;
    while (true) {
        scanf("%d", &n);
        if (n == 0)
            break;
        for (int i = 0; i < n; i++)
            scanf("%d%d%d", &m[i][0], &m[i][1], &m[i][2]);
        for (int i = 0; i < n; i++)
            dp[i][0] = dp[i][1] = dp[i][2] = 0;

        printf("%d. %d\n", k++, solve(n-1, 1));
    }
    return 0;
}
