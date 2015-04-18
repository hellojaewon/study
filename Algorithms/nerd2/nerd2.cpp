#include <cstdio>
#include <map>

using namespace std;

void RemoveVictims (map<int, int> & coords, int x, int y) {
    map<int, int>::iterator it = coords.lower_bound(x);
    if (it == coords.begin())
        return;

    it--;
    for (;;) {
        if (it->second > y)
            break;
        if (it == coords.begin()) {
            coords.erase(it);
            break;
        } else {
            map<int, int>::iterator jt = it;
            jt--;
            coords.erase(it);
            it = jt;
        }
    }
}

bool IsDominated (map<int, int> & coords, int x, int y) {
    map<int, int>::iterator it = coords.lower_bound(x);
    if (it == coords.end())
        return false;
    return (y < it->second);
}

int Register (map<int, int> & coords, int x, int y) {
    if (IsDominated(coords, x, y))
        return coords.size();

    RemoveVictims(coords, x, y);
    coords[x] = y;

    return coords.size();
}

int main () {
    int c;
    scanf("%d", &c);
    while (c--) {
        int n;
        scanf("%d", &n);
        map<int, int> coords;
        int x, y;
        int sum = 0;
        for (unsigned i = 0; i < n; i++) {
            scanf("%d%d", &x, &y);
            sum = sum + Register(coords, x, y);
        }
        printf("%d\n", sum);
    }

    return 0;
}
