#include <iostream>
#include <stack>
#include <vector>
#include <cassert>

using namespace std;

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    stack<int> s;
    int i = 0;
    int j = 0;
    while (i < pushed.size() && j < popped.size()) {
        if (!s.empty() && s.top() == popped[j]) {
            s.pop();
            j++;
        } else {
            s.push(pushed[i]);
            i++;
        }
    }

    while (j < popped.size() && s.top() == popped[j]) {
        s.pop();
        j++;
    }

    return s.empty();
}

int main () {
    vector<int> pushed1{1,2,3,4,5};
    vector<int> poped1{4,5,3,2,1};
    assert(validateStackSequences(pushed1, poped1));
    vector<int> pushed2{1,2,3,4,5};
    vector<int> poped2{4,3,5,1,2};
    assert(!validateStackSequences(pushed2, poped2));
    return 0;
}
