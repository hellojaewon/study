#include <cstdio>

int main () {
    int n;
    scanf("%d", &n);
    int remaining = 0;
    while (n--) {
        int students, apples;
        scanf("%d%d", &students, &apples);
        remaining += apples % students;
    }
    printf("%d\n", remaining);
    return 0;
}
