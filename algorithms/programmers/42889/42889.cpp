#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> v(N+1, 0);
    for (int s : stages)
        v[s-1]++;

    vector<pair<double,int>> f;
    int total = stages.size();
    for (int i = 0; i < N; i++) {
        f.push_back(make_pair(total ? v[i] / (double)total : 0, i));
        total = total - v[i];
    }

    sort(f.begin(), f.end(), [](const pair<double,int> & lhs, const pair<double,int> & rhs) {
        if (lhs.first == rhs.first)
            return lhs.second < rhs.second;
        return lhs.first > rhs.first;
    });
    vector<int> answer;
    for (auto p : f)
        answer.push_back(p.second+1);
    return answer;
}

int main () {
    auto res = solution(5, vector<int>{2,1,2,6,2,4,3,3});
    assert(res.size() == 5);
    assert(res[0] == 3);
    assert(res[1] == 4);
    assert(res[2] == 2);
    assert(res[3] == 1);
    assert(res[4] == 5);
    res = solution(4, vector<int>{4,4,4,4,4});
    assert(res.size() == 4);
    assert(res[0] == 4);
    assert(res[1] == 1);
    assert(res[2] == 2);
    assert(res[3] == 3);
    return 0;
}
