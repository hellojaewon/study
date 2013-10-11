#include <cstdio>

int main () {
    int t;
    scanf("%d", &t);
    while (t--) {
        int goal;
        scanf("%d", &goal);
        int used[9];
        for (unsigned i = 0; i < 9; i++)
            scanf("%d", &used[i]);
        int sum = 0;
        for (unsigned i = 0; i < 9; i++)
            sum += used[i];
        printf("%s\n", goal >= sum ? "YES" : "NO");
    }
    return 0;
}
