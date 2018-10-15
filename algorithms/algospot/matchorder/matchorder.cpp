#include <cstdio>
#include <algorithm>

int matchorder (int n, int korea[], int russia[]) {
    std::sort(&korea[0], &korea[n]);

    bool used[100] = {0,};
    int win = 0;
    for (int i = 0; i < n; i++) {
        int j;
        for (j = 0; j < n; j++) {
            if (russia[i] <= korea[j] && !used[j]) {
                used[j] = true;
                break;
            }
        }
        if (j == n) {
            for (int x = 0; x < n; x++) {
                if (!used[x]) {
                    used[x] = true;
                    break;
                }
            }
        } else {
            win++;
        }
    }
    return win;
}

int main () {
    int c;
    scanf("%d", &c);
    while (c--) {
        int n;
        scanf("%d", &n);
        int korea[100], russia[100];
        for (int i = 0; i < n; i++)
            scanf("%d", &russia[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &korea[i]);

        printf("%d\n", matchorder(n, korea, russia));
    }
    return 0;
}
