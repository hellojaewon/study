#include <cstdio>
#include <algorithm>

using namespace std;

struct apple {
    int x;
    int a;
};

apple a[100];
int main () {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d%d", &a[i].x, &a[i].a);
    std::sort(a, a+n, [&](apple x, apple y) { return x.x < y.x; });
    int start = -1;
    for (int i = 0; i < n; i++) {
        if (a[i].x > 0) {
            start = i;
            break;
        }
    }
    if (start == -1)
        printf("%d\n", a[n-1].a);
    else if (start == 0)
        printf("%d\n", a[0].a);
    else {
        int sum = 0;
        int left = start - 1;
        int right = start;
        while (left >= 0 && right < n) {
            sum += a[left].a + a[right].a;
            left--;
            right++;
        }
        if (right < n)
            sum+= a[right].a;
        else if (left >= 0)
            sum += a[left].a;
        printf("%d\n", sum);
    }
    return 0;
}
