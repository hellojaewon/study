#include <iostream>
#include <cassert>
#include "dynamic_array.h"

using namespace std;

int main () {
    DynamicArray arr;
    assert(arr.Capacity() == 2);
    assert(arr.Size() == 0);

    arr.PushBack(1);
    arr.PushBack(2);
    assert(arr.Capacity() == 2);
    assert(arr.Size() == 2);

    arr.PushBack(3);
    arr.PushBack(4);
    assert(arr.Capacity() == 4);
    assert(arr.Size() == 4);

    assert(arr.Get(0) == 1);
    assert(arr.Get(1) == 2);
    assert(arr.Get(2) == 3);
    assert(arr.Get(3) == 4);
    assert(arr.Get(5) == -1);

    return 0;
}
