#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include "heap.h"

int main () {
    Heap<char> heap;

    heap.Insert(Element<char>(3, 'h'));
    heap.Insert(Element<char>(1, 'e'));
    heap.Insert(Element<char>(2, 'l'));
    heap.Insert(Element<char>(4, 'l'));
    heap.Insert(Element<char>(5, 'o'));

    assert(heap.Delete()->GetKey() == 1);
    assert(heap.Delete()->GetKey() == 2);
    assert(heap.Delete()->GetKey() == 3);
    assert(heap.Delete()->GetKey() == 4);
    assert(heap.Delete()->GetKey() == 5);

    return 0;
}
