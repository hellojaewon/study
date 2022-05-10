#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> result;
    int cur = 0;
    while (cur < intervals.size()) {
        if (newInterval[1] < intervals[cur][0])
            break;
        if (intervals[cur][1] < newInterval[0])
            result.push_back(intervals[cur++]);
        else {
            newInterval[0] = min(intervals[cur][0], newInterval[0]);
            newInterval[1] = max(intervals[cur][1], newInterval[1]);
            cur++;
        }
    }
    result.push_back(newInterval);
    while (cur < intervals.size())
        result.push_back(intervals[cur++]);

    return result;
}

void test1 () {
    vector<vector<int>> intervals;
    intervals.push_back({1,3});
    intervals.push_back({6,9});
    vector<int> newInterval{2,5};
    auto result = insert(intervals, newInterval);
    assert(result.size() == 2);
    assert(result[0][0] == 1);
    assert(result[0][1] == 5);
    assert(result[1][0] == 6);
    assert(result[1][1] == 9);
}

void test2 () {
    vector<vector<int>> intervals;
    intervals.push_back({1,2});
    intervals.push_back({3,5});
    intervals.push_back({6,7});
    intervals.push_back({8,10});
    intervals.push_back({12,16});
    vector<int> newInterval{4,8};
    auto result = insert(intervals, newInterval);
    assert(result.size() == 3);
    assert(result[0][0] == 1);
    assert(result[0][1] == 2);
    assert(result[1][0] == 3);
    assert(result[1][1] == 10);
    assert(result[2][0] == 12);
    assert(result[2][1] == 16);
}

void test3 () {
    vector<vector<int>> intervals;
    vector<int> newInterval{5,7};
    auto result = insert(intervals, newInterval);
    assert(result.size() == 1);
    assert(result[0][0] = 5);
    assert(result[0][1] = 7);
}

void test4 () {
    vector<vector<int>> intervals;
    intervals.push_back({1,5});
    vector<int> newInterval{2,3};
    auto result = insert(intervals, newInterval);
    assert(result.size() == 1);
    assert(result[0][0] == 1);
    assert(result[0][1] == 5);
}

int main () {
    test1();
    test2();
    test3();
    test4();

    return 0;
}
