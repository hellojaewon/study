#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

vector<int> dailyTemperatures(vector<int>& T) {
    vector<int> result(T.size(), 0);

    result[T.size() - 1] = 0;
    for (int i = T.size() - 2; i >= 0; i--) {
        int j = i + 1;
        int next = 0;
        while (j < T.size()) {
            if (T[i] < T[j]) {
                next = j - i;
                break;
            }
            if (result[j] == 0)
                break;
            j += result[j];
        }
        result[i] = next;
    }

    return result;
}

int main () {
  
    vector<int> T{73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> expected{1, 1, 4, 2, 1, 1, 0, 0};
    auto res = dailyTemperatures(T);
    assert(res.size() == expected.size());
    for (int i = 0; i < res.size(); i++)
        assert(res[i] == expected[i]);

    return 0;
}
