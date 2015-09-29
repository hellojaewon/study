#include <cstdio>
#include <algorithm>

int n;
int left[2000];
int right[2000];
int memo[2000][2000];

int solve (int l, int r) {
    if (l >= n || r >= n)
        return 0;

    if (memo[l][r])
        return memo[l][r];

    memo[l][r] = std::max(solve(l+1, r+1), solve(l+1, r));
    if (left[l] > right[r])
        memo[l][r] = std::max(memo[l][r], right[r] + solve(l, r+1));
    return memo[l][r];
}

int main () {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &left[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &right[i]);

    printf("%d\n", solve(0, 0));
    return 0;
}
