/*
 * 10.1 Sorted Merge
 * You are given two sorted arrays, A and B, where A has a large enough buffer
 * at the end to hold B. Write a method to merge B into A in sorted order.
 */
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <vector>
#include <algorithm>

const int max_size = 100;

void merge (std::vector<int> & a, const std::vector<int> & b) {
    assert(a.size() + b.size() <= a.capacity());
    int right = a.capacity() - 1;
    int index_a = a.size() - 1;
    int index_b = b.size() - 1;
    while (index_a >= 0 && index_b >= 0) {
        if (a[index_a] > b[index_b]) {
            a[right] = a[index_a];
            index_a--;
        } else {
            a[right] = b[index_b];
            index_b--;
        }
        right--;
    }

    while (index_b >= 0) {
        a[right] = b[index_b];
        index_b--;
        right--;
    }
}

int main () {
    std::srand(std::time(0));
    int a_length = std::rand() % max_size;
    int b_length = std::rand() % max_size;
    std::vector<int> a, b;
    a.reserve(a_length + b_length);
    for (unsigned i = 0; i < a_length; i++)
        a.push_back(rand() % RAND_MAX);
    for (unsigned i = 0; i < b_length; i++)
        b.push_back(rand() % RAND_MAX);

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    merge(a, b);
    assert(std::is_sorted(&a[0], &a[a.capacity()]));

    return 0;
}
