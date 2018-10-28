#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

std::vector<double> differenticate (const std::vector<double> & poly) {
    int n = poly.size() - 1;
    std::vector<double> diff;
    for (auto & c : poly)
        diff.push_back(c*n--);
    diff.pop_back();
    return diff;
}

std::vector<double> solveNaive (const std::vector<double> & poly) {
    std::vector<double> res;
    if (poly.size() == 2) {
        res.push_back(poly[1]/poly[0] * -1);
    } else {
        double tmp = sqrt(poly[1]*poly[1] - (4*poly[0]*poly[2]));
        res.push_back((-poly[1] - tmp) / (2*poly[0]));
        res.push_back((-poly[1] + tmp) / (2*poly[0]));
    }

    return res;
}

double evaluate (const std::vector<double> & poly, double x0) {
    int n = poly.size();
    double res = 0;
    for (int i = 0; i < n; i++)
        res += poly[i] * pow(x0, n-1-i);
    return res;
}

std::vector<double> solve (std::vector<double> & poly) {
    const double L = 10;
    int n = poly.size() - 1;
    if (n <= 2) return solveNaive(poly);

    std::vector<double> derivative = differenticate(poly);
    std::vector<double> sols = solve(derivative);

    sols.insert(sols.begin(), -L-1);
    sols.insert(sols.end(), L+1);
    std::vector<double> ret;
    for (int i = 0; i+1 <sols.size(); i++) {
        double x1 = sols[i], x2 = sols[i+1];
        double y1 = evaluate(poly, x1), y2 = evaluate(poly, x2);
        if (y1 * y2 > 0) continue;
        if (y1 > y2) {
            std::swap(y1, y2);
            std::swap(x1, x2);
        }
        for (int iter = 0; iter < 100; iter++) {
            double mx = (x1 + x2) / 2;
            double my = evaluate(poly, mx);
            if (y1 * my > 0) {
                x1 = mx;
                y1 = my;
            } else {
                x2 = mx;
                y2 = my;
            }
        }
        ret.push_back((x1 + x2) / 2);
    }
    std::sort(ret.begin(), ret.end());
    return ret;
}

int main () {
    int c;
    scanf("%d", &c);
    while (c--) {
        int n;
        scanf("%d", &n);
        std::vector<double> poly;
        double tmp;
        for (int i = 0; i <= n; i++) {
            scanf("%lf", &tmp);
            poly.push_back(tmp);
        }
        auto roots = solve(poly);
        for (auto & r : roots)
            printf("%.12lf\t", r);
        printf("\n");
    }

    return 0;
}
