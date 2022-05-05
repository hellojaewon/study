#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

inline int pop (vector<int> & stones) {
    int value = stones.front();
    pop_heap(stones.begin(), stones.end());
    stones.pop_back();
    return value;
}

inline void push (vector<int> & stones, int value) {
    stones.push_back(value);
    push_heap(stones.begin(), stones.end());
}

int lastStoneWeight(vector<int>& stones) {
    make_heap(stones.begin(), stones.end());

    while (stones.size() > 1) {
        int x = pop(stones);
        int y = pop(stones);
        if (x == y)
            continue;
        push(stones, abs(x-y));
    }
    return stones.size() ? stones[0] : 0;
}

void test1 () {
    vector<int> stones{2,7,4,1,8,1};
    assert(lastStoneWeight(stones) == 1);
}

void test2 () {
    vector<int> stones{1};
    assert(lastStoneWeight(stones) == 1);
}

int main () {
    test1();
    test2();

    return 0;
}
