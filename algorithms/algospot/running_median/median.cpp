#include <cstdio>
#include <queue>
#include <vector>

int n, a, b;

int next (bool reset = false) {
    static long long seed;
    if (reset) {
        seed = 1983;
        return 0;
    }
    int ret = seed;
    seed = (seed * a + b) % 20090711;
    return ret;
}

int solve () {
    std::priority_queue< int, std::vector<int>, std::less<int> > maxHeap;
    std::priority_queue< int, std::vector<int>, std::greater<int> > minHeap;

    next(true);
    int median = 0;
    for (int i = 0; i < n; i++) {
        int number = next();
        if (maxHeap.size() == minHeap.size())
            maxHeap.push(number);
        else
            minHeap.push(number);
        if (maxHeap.size() && minHeap.size() && maxHeap.top() > minHeap.top()) {
            int left = maxHeap.top(); maxHeap.pop();
            int right = minHeap.top(); minHeap.pop();
            maxHeap.push(right);
            minHeap.push(left);
        }
        median = (median + maxHeap.top()) % 20090711;
    }
    return median;
}

int main () {
    int c;
    scanf("%d", &c);
    while (c--) {
        scanf("%d%d%d", &n, &a, &b);
        printf("%d\n", solve());
    }
    return 0;
}
