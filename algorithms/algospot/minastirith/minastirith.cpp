#include <cstdio>
#include <utility>
#include <algorithm>
#include <cmath>

int solveLinear (double begin, double end, std::pair<double, double> ranges[], int n) {
    const int INF = 987654321;

    int used = 0, idx = 0;
    while (begin < end) {
        double maxCover = -1;
        while (idx < n && ranges[idx].first <= begin) {
            maxCover = fmax(maxCover, ranges[idx].second);
            idx++;
        }
        if (maxCover <= begin)
            return INF;

        begin = maxCover;
        used++;
    }
    return used;
}

int solve (double x[], double y[], double r[], int n) {
    const double pi = 2.0 * acos(0);
    std::pair<double, double> ranges[100];

    // convert to range
    for (int i = 0; i < n; i++) {
        double loc = fmod(2*pi + atan2(y[i], x[i]), 2*pi);
        double range = 2.0 * asin(r[i]/2.0/8.0);
        ranges[i] = std::make_pair(loc - range, loc + range);
    }
    std::sort(ranges, ranges+n);

    const int INF = 987654321;

    // solve Circular
    int ret = INF;
    for (int i = 0; i < n; i++) {
        if (ranges[i].first <= 0 || ranges[i].second >= 2*pi) {
            double begin = fmod(ranges[i].second, 2*pi);
            double end = fmod(ranges[i].first + 2*pi, 2*pi);
            ret = std::min(ret, 1 + solveLinear(begin, end, ranges, n));
        }
    }
    return ret;
}

int main () {
    const int INF = 987654321;
    int c;
    scanf("%d", &c);
    while (c--) {
        int n;
        double x[100], y[100], r[100];
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%lf%lf%lf", &x[i], &y[i], &r[i]);
        unsigned min = solve(x, y, r, n);
        if (min == INF)
            printf("IMPOSSIBLE\n");
        else
            printf("%d\n", min);
    }
    return 0;
}
