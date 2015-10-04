#include <cstdio>
#include <stack>
#include <cassert>

#define TO_INT(i,j) ((i)*(n))+(j)
#define ADDR(i,j) (m+(TO_INT(i,j)))
#define VAL(i,j) *(m+(TO_INT(i,j)))
#define VISITED(i,j) (VAL(i,j) < 0)
#define POINT(i,j) -(VAL(i,j))

int m[10000];
int n;

bool solve () {
    std::stack<int> ways;
    ways.push(0);
    VAL(0,0) = -VAL(0,0);
    while (!ways.empty()) {
        int x = ways.top() / n;
        int y = ways.top() % n;
        ways.pop();
        int point = POINT(x,y);
        assert(point >= 0);
        if (x + point < n) {
            if (VAL(x+point, y) == 0)
                return true;
            else if (!VISITED(x+point, y)) {
                VAL(x+point, y) = -VAL(x+point, y);
                ways.push(TO_INT(x+point, y));
            }
        }
        if (y + point < n) {
            if (VAL(x, y+point) == 0)
                return true;
            else if (!VISITED(x,y+point)) {
                VAL(x,y+point) = -VAL(x, y+point);
                ways.push(TO_INT(x, y+point));
            }
        }
    }
    return false;
}

int main () {
    int c;
    scanf("%d", &c);
    while (c--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                scanf("%d", ADDR(i,j));
        }
        printf("%s\n", solve() ? "YES" : "NO");
    }
    return 0;
}
