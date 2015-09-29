#include <cstdio>

int a[100001];
int dp[100001];

int main () {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    a[n] = -1;
    int max = 0;
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        if (a[i-1] > a[i]) {
            dp[i] = 1;
            if (dp[max] < dp[i-1])
                max = i-1;
        } else
            dp[i] = dp[i-1] + 1;
    }
    printf("%d\n", dp[max]);

    return 0;
}
