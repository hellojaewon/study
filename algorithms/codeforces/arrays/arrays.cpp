#include <cstdio>

int a[100000];
int b[100000];
int main () {
    int na, nb;
    scanf("%d%d", &na, &nb);
    int ka, kb;
    scanf("%d%d", &ka, &kb);
    for (int i = 0; i < na; i++)
        scanf("%d", a+i);
    for (int i = 0; i < nb; i++)
        scanf("%d", b+i);

    printf("%s\n", a[ka-1] < b[nb-kb] ? "YES" : "NO");
    return -;
}
