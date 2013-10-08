#include <cstdio>

#define MIN(a, b) (a) < (b) ? (a) : (b)
#define INFINITE 9999

int switches[10][16] = {
    {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1},
    {1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1},
    {0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}
};

int clocks[16];

bool isAligned () {
    for (unsigned i = 0; i < 16; i++)
        if (clocks[i] != 12)
            return false;
    return true;
}

void push (int sw) {
    for (unsigned i = 0; i < 16; i++) {
        if (switches[sw][i]) {
            clocks[i] += 3;
            if (clocks[i] == 15)
                clocks[i] = 3;
        }
    }
}

int solve (int sw) {
    if (sw == 10)
        return isAligned() ? 0 : INFINITE;

    int min = INFINITE;
    for (unsigned i = 0; i < 4; i++) {
        int count = i + solve(sw+1);
        min = MIN(min, count);
        push(sw);
    }

    return min;
}

int main () {
    int c;
    scanf("%d", &c);
    while (c--) {
        for (unsigned i = 0; i < 16; i++)
            scanf("%d", &clocks[i]);
        int result = solve(0);
        printf("%d\n", result == INFINITE ? -1 : result);
    }
    return 0;
}
