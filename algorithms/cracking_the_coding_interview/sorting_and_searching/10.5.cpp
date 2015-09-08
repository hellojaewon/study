/*
 * Given a sorted array of strings which is interspersed with empty strings,
 * write a method to find the location of a given string
 */
#include <cstdio>
#include <cstring>
#include <cassert>

#define arrsize(a) sizeof(a)/sizeof(a[0])

const char * arr[] = {
    "at",       //  0
    "",
    "",
    "",
    "ball",
    "",         // 5
    "",
    "car",
    "",
    "",
    "dad",      // 10
    "",
    ""
};

int find_location (int from, int to, const char * key) {
    if (from >= to)
        return -1;

    int half = (from + to) / 2;
    if (!strcmp(arr[half], key))
        return half;

    if (!strcmp(arr[half], "")) {
        int location = find_location(from, half-1, key);
        if (location != -1)
            return location;
        return find_location(half+1, to, key);
    }

    if (strcmp(arr[half], key) > 0)
        return find_location(from, half-1, key);
    return find_location(half+1, to, key);
}

int main () {
    assert(find_location(0, arrsize(arr), "at") == 0);
    assert(find_location(0, arrsize(arr), "ball") == 4);
    assert(find_location(0, arrsize(arr), "dad") == 10);
    assert(find_location(0, arrsize(arr), "notexist") == -1);

    return 0;
}
