/*
 * 10.4 Sorted Search, No Size
 * You are given an array-like data structure Listy which lacks a size method.
 * It does, however, have an elementAt(i) method that returns the element at
 * index in O(1) time. It i is beyond the bounds of the data structure, it
 * returns -1. (For this reason, the data structure only supports positive
 * integers.) Given a Listy which contains sorted, positive integers find the
 * index at which an element x occurs. If x occurs multiple times, you may
 * return any index.
 */
#include <cstdio>
#include <cassert>
#include <vector>

class Listy {
public:
    Listy (int size);

    int elementAt (int index) const;

private:
    std::vector<int> m_array;
    int              m_size;
};

Listy::Listy (int size)
 : m_size(size)
{
    for (unsigned i = 0; i < m_size; i++)
        m_array.push_back(i);
}

int Listy::elementAt (int index) const {
    if (index < 0 || index >= m_size)
        return -1;
    return m_array[index];
}

int binarySearch (const Listy & listy, int left, int right, int key) {
    int mid = (left + right) / 2;

    // ignores the right half array because it is beyond the array boundary
    if (listy.elementAt(mid) == -1)
        return binarySearch(listy, left, mid-1, key);

    if (listy.elementAt(mid) == key)
        return mid;

    if (listy.elementAt(mid) > key)
        return binarySearch(listy, 0, mid-1, key);
    return binarySearch(listy, mid+1, right, key);
}

int findIndex (const Listy & listy, int key) {
    // finds the upper bound of array exponentially starting from 1
    // therefore, its time complexity is O(logN)
    int upper = 1;
    while (true) {
        if (listy.elementAt(upper) == -1)
            break;
        upper = upper << 1;
    }

    return binarySearch(listy, 0, upper, key);
}

int main () {
    Listy listy(10);
    assert(listy.elementAt(-1) == -1);
    assert(listy.elementAt(10) == -1);
    assert(listy.elementAt(11) == -1);
    assert(listy.elementAt(12) == -1);
    assert(listy.elementAt(14) == -1);

    for (unsigned i = 0; i < 10; i++)
        assert(findIndex(listy, i) == i);

    return 0;
}
