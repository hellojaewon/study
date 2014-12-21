#include <cstdio>
#include <cassert>

#define MAX_NODES 1000

int pre[MAX_NODES];
int in[MAX_NODES];
int n;

void solve (int root, unsigned start, unsigned end) {
    if (start == end)
        return;

    unsigned i = -1;
    for (i = start; i < end; i++) {
        if (in[i] == pre[root])
            break;
    }
    assert(i != -1);
    solve(root+1, start, i);
    solve(root+1+i-start, i+1, end);

    printf("%d ", pre[root]);
}

int main () {
    int c;
    scanf("%d", &c);
    while (c--) {
        scanf("%d", &n);
        for (unsigned i = 0; i < n; i++)
            scanf("%d", &pre[i]);
        for (unsigned i = 0; i < n; i++)
            scanf("%d", &in[i]);
        solve(0, 0, n);
        printf("\n");
    }

    return 0;
}
