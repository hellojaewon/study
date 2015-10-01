#include <cstdio>

int main () {
    int x;
    scanf("%d", &x);
    int answer = 0;
    for (int i = 0; i < 32; i++) {
        if (x & 0x01)
            answer++;
        x = x >> 1;
    }
    printf("%d\n", answer);


    return 0;
}
