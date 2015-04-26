#include <cstdio>

bool friends[10][10];
int found[10];
int n;

void init() {
    for (unsigned i = 0; i < 10; i++)
        for (unsigned j = 0; j < 10; j++)
            friends[i][j] = false;

    for (unsigned i = 0; i < 10; i++)
        found[i] = 0;
}

int solve () {
    int start = -1;
    for (unsigned i = 0; i < n; i++) {
        if (!found[i]) {
            start = i;
            break;
        }
    }

    if (start == -1) return 1;

    int cases = 0;
    for (unsigned i = start+1; i < n; i++) {
        if (found[i])
            continue;
        if (!friends[start][i])
            continue;
        found[start] = true;
        found[i] = true;
        cases += solve();
        found[start] = false;
        found[i] = false;
    }
    return cases;
}

int main () {
    int c;
    scanf("%d", &c);
    while (c--) {
        init();
        int m;
        scanf("%d%d", &n, &m);
        for (unsigned i = 0; i < m; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            friends[x][y] = true;
            friends[y][x] = true;
        }
        printf("%d\n", solve());
    }
    return 0;
}
